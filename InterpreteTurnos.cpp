/*
 * InterpreteTurnos.cpp
 *
 *  Created on: 01/05/2011
 *      Author: Nestor Huallpa
 */

#include "InterpreteTurnos.h"
using std::string;
using std::stringstream;


InterpreteTurnos::InterpreteTurnos() {
	piezasPromocion = NULL;
	turnos = NULL;
	pgn = NULL;
}

void InterpreteTurnos::setPgn(PgnAjedrez *pgn) {
    this->pgn = pgn;
}

InterpreteTurnos::~InterpreteTurnos() {
	if (turnos) {
		ListaPTurno::IteratorList it = turnos->getIterator();
		while (it.hasNext()) {
			delete it.next();
		}
		delete turnos;
	}
	if (piezasPromocion) {
		ListaPPieza::IteratorList it = piezasPromocion->getIterator();
		while (it.hasNext()) {
			delete it.next();
		}
		delete piezasPromocion;
	}
}

void InterpreteTurnos::interpretarTurnos() {
	if (!turnos && pgn) {
		turnos = new ListaPTurno();
		stringstream& streamMovidas = pgn->getMovidas();

		bool primerTurno = true;
		while (!streamMovidas.eof()) {
			Turno* unTurno = NULL;
			string nroTurno, movNegro, movBlanco;
			streamMovidas >> nroTurno;
			if (!streamMovidas.good()) { break;	}
			if (primerTurno && empiezaNegra()) {
				streamMovidas >> movNegro;
				unTurno = crearTurno(nroTurno, movNegro);
			} else {
				streamMovidas >> movBlanco;
				streamMovidas >> movNegro;
				unTurno = crearTurno(nroTurno, movBlanco, movNegro);
			}

			if (unTurno && unTurno->requiereAnalisis()) {
				preparaParaAnalizar(unTurno, movNegro, movBlanco);
			}

			turnos->agregar(unTurno);

			if (primerTurno) { primerTurno = !primerTurno; }
		}
	}
}


ListaPPieza* InterpreteTurnos::getPiezasPromocion() {
	return piezasPromocion;
}

ListaPTurno* InterpreteTurnos::getTurnos() {
	return turnos;
}

bool InterpreteTurnos::empiezaNegra() {
	return (pgn->getSimboloSiguienteJugador() == JUGADOR_NEGRO);
}

Turno* InterpreteTurnos::crearTurno(string nroTurno,
								string movidaBlanco, string movidaNegro) {
	Movimiento* movimientoBlanco = NULL;
	movimientoBlanco = factoryMovimiento.crear(movidaBlanco, BLANCO);
	if (movimientoBlanco->tienePromocion()) {
		registrarPromocionDe(movimientoBlanco, movidaBlanco);
	}
	Movimiento* movimientoNegro = NULL;
	movimientoNegro = factoryMovimiento.crear(movidaNegro, NEGRO);
	if (movimientoNegro->tienePromocion()) {
		registrarPromocionDe(movimientoNegro, movidaNegro);
	}
	return crearTurno(nroTurno, movimientoBlanco, movimientoNegro);
}

Turno* InterpreteTurnos::crearTurno(string nroTurno, string movidaNegro) {
	Movimiento* movimientoNegro = NULL;
	movimientoNegro = factoryMovimiento.crear(movidaNegro, NEGRO);
	if (movimientoNegro->tienePromocion()) {
		registrarPromocionDe(movimientoNegro, movidaNegro);
	}
	Movimiento* movimientoVacio = new NingunMovimiento();
	return crearTurno(nroTurno, movimientoVacio, movimientoNegro);
}

Turno* InterpreteTurnos::crearTurno(string& nroTurno,
			Movimiento* movidaBlanco, Movimiento* movidaNegro) {
	Turno* unTurno = new Turno();
	int nro = obtenerNumeroTurno(nroTurno);
	unTurno->setMovimientoBlanco(movidaBlanco);
	unTurno->setMovimientoNegro(movidaNegro);
	unTurno->setNroTurno(nro);

	if (requiereAnalisis(nroTurno)) {
		unTurno->requirirAnalisis();
	}
	return unTurno;
}

bool InterpreteTurnos::requiereAnalisis(string& nroTurno) {
	int nro = nroTurno.find(c_ANALIZAR, 0);
	return (nro >= 0);
}

int InterpreteTurnos::obtenerNumeroTurno(string& nroTurno) {
	int pos = nroTurno.find(c_ANALIZAR, 0);
	if (pos < 0) {
		pos = nroTurno.find('.', 0);
	}
	string nro = nroTurno.substr(0, pos);
	return Util::stringToInt(nro);
}


void InterpreteTurnos::preparaParaAnalizar(Turno* unTurno, string& movNegro,
														string& movBlanco) {
	Coordenada coordOrigenBlanco = obtenerCoordenadaInicial(movBlanco);
	Coordenada coordOrigenNegro = obtenerCoordenadaInicial(movNegro);
	unTurno->setCoordOrigenBlanco(coordOrigenBlanco);
	unTurno->setCoordOrigenNegro(coordOrigenNegro);
}

Coordenada InterpreteTurnos::obtenerCoordenadaInicial(string& movida) {
	Coordenada coord;

	if (factoryMovimiento.esMovimientoSimple(movida) ||
		factoryMovimiento.esMovimientoSimpleCombinable(movida)) {
		int i = (movida.length() == 4)?0:1;
		coord.setFila(Util::charToInt(movida[i+1]));
		coord.setColumna(movida[i]);
	}
	if (factoryMovimiento.esMate(movida) ||
		factoryMovimiento.esJaque(movida)) {
		int i = (movida.length() == 5)?0:1;
		coord.setFila(Util::charToInt(movida[i+1]));
		coord.setColumna(movida[i]);
	}

	if (factoryMovimiento.esPromocion(movida)) {
		coord.setFila(Util::charToInt(movida[1]));
		coord.setColumna(movida[0]);
	}
	return coord;
}


void InterpreteTurnos::registrarPromocionDe(Movimiento* movimiento,
													string palabra) {
	if (piezasPromocion == NULL) {
		piezasPromocion = new ListaPPieza();
	}
	char simbolo = ((Promocion*)movimiento)->getSimboloPromocion();
	PiezaJugadora* nuevaPiezaJugadora = factoryPiezaJugadora.crear(simbolo);
	((Promocion*)movimiento)->setPiezaPromocion(nuevaPiezaJugadora);
	Coordenada& destino = ((Promocion*)movimiento)->getDestino();
	if (nuevaPiezaJugadora) {
		piezasPromocion->agregar(
				new Pieza(nuevaPiezaJugadora, destino, simbolo));
	}
}
