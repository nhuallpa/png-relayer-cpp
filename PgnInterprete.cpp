/*
 * PgnInterprete.cpp
 *
 *  Created on: 21/04/2011
 *      Author: Nestor Huallpa
 */

#include "PgnInterprete.h"



using namespace std;
// todo : sacar
//istream &operator >> (istream &in, Turno &turno) {
//	cout<<"jeje";
//	return in;
//}



PgnInterprete::PgnInterprete() {
	piezasIniciales = NULL;
//	piezasPromocion = NULL;
//	turnos = NULL;
	pgn = NULL;

}

PgnInterprete::~PgnInterprete() {
	if (piezasIniciales) {
		ListaPPieza::IteratorList it = piezasIniciales->getIterator();
		while (it.hasNext()) {
			delete it.next();
		}
		delete piezasIniciales;
	}

	// todo: pasar esto
//	if (turnos) {
//		ListaPTurno::IteratorList it = turnos->getIterator();
//		while (it.hasNext()) {
//			delete it.next();
//		}
//		delete turnos;
//	}
//	if (piezasPromocion) {
//		ListaPPieza::IteratorList it = piezasPromocion->getIterator();
//		while (it.hasNext()) {
//			delete it.next();
//		}
//		delete piezasPromocion;
//	}
}

void PgnInterprete::interpretar() {
	interpretarTableroInicial();
	// interpretarTurnos();
	interpreteTurno.interpretarTurnos();
}

// todo: pasar esto, ref a pgn
//void PgnInterprete::interpretarTurnos() {
//	if (!turnos && pgn) {
//		turnos = new ListaPTurno();
//		stringstream& streamMovidas = pgn->getMovidas();
//
//		bool primerTurno = true;
//		while (!streamMovidas.eof()) {
//			string nroTurno;
//
//			streamMovidas>>nroTurno;
//			if (!streamMovidas.good()) {
//				break;
//			}
//			if (primerTurno && empiezaNegra()) {
//				string movNegro;
//				streamMovidas>>movNegro;
//				crearTurno(nroTurno, movNegro);
//			} else {
//				string movNegro;
//				string movBlanco;
//				streamMovidas>>movBlanco;
//				streamMovidas>>movNegro;
//				crearTurno(nroTurno, movBlanco, movNegro);
//			}
//			if (primerTurno) { primerTurno = !primerTurno; }
//		}
//	}
//}

void PgnInterprete::interpretarTableroInicial() {
	if (!piezasIniciales && pgn) {
		piezasIniciales = new ListaPPieza();
		for (int fila = PNG_CANT_FILA; fila > 0; fila--) {
			string filaString = pgn->dameFila(fila);
			interpretarFila(filaString, fila);
		}
	}
}

void PgnInterprete::interpretarFila(string filaString, int fila) {
	int columna = 0;
	for (size_t index = 0; index < filaString.length(); ++index) {
		char simbolo = filaString.at(index);
		if (simbolo > '0' && simbolo <= '8') {
			columna += (simbolo - '0');
		} else {
			PiezaJugadora* pJugadadora = factoryPiezaJugadora.crear(simbolo);
			Coordenada coord(fila, 'a' + columna );
			registrarPiezas(pJugadadora, coord, simbolo);
			++columna;
		}
	}
}

void PgnInterprete::registrarPiezas(PiezaJugadora* piezaJugadora,
									const Coordenada& coord, char simbolo) {
	if (piezaJugadora) {
		piezasIniciales->agregar(new Pieza(piezaJugadora, coord, simbolo));
	}
}

void PgnInterprete::setPgn(PgnAjedrez *pgn) {
    this->pgn = pgn;


     interpreteTurno.setPgn(pgn);
}

ListaPPieza* PgnInterprete::getPiezasIniciales() {
	return piezasIniciales;
}


// todo: pasar esto hasta abajo
ListaPPieza* PgnInterprete::getPiezasPromocion() {
	// return piezasPromocion;
	 return interpreteTurno.getPiezasPromocion();
}

ListaPTurno* PgnInterprete::getTurnos() {
	// return turnos;
	 return interpreteTurno.getTurnos();
}
//
//bool PgnInterprete::empiezaNegra() {
//	return (pgn->getSimboloSiguienteJugador() == JUGADOR_NEGRO);
//}
//
//void PgnInterprete::crearTurno(string nroTurno, string movidaBlanco, string movidaNegro) {
//	Movimiento* movimientoBlanco = NULL;
//	movimientoBlanco = factoryMovimiento.crear(movidaBlanco, BLANCO);
//	if (movimientoBlanco->tienePromocion()) {
//		registrarPromocionDe(movimientoBlanco, movidaBlanco);
//	}
//	Movimiento* movimientoNegro = NULL;
//	movimientoNegro = factoryMovimiento.crear(movidaNegro, NEGRO);
//	if (movimientoNegro->tienePromocion()) {
//		registrarPromocionDe(movimientoNegro, movidaNegro);
//	}
//	crearTurno(nroTurno, movimientoBlanco, movimientoNegro);
//}
//
//void PgnInterprete::crearTurno(string nroTurno, string movidaNegro) {
//	Movimiento* movimientoNegro = NULL;
//	movimientoNegro = factoryMovimiento.crear(movidaNegro, NEGRO);
//	if (movimientoNegro->tienePromocion()) {
//		registrarPromocionDe(movimientoNegro, movidaNegro);
//	}
//	Movimiento* movimientoVacio = new NingunMovimiento();
//	crearTurno(nroTurno, movimientoVacio, movimientoNegro);
//}
//
//void PgnInterprete::crearTurno(string& nroTurno, Movimiento* movidaBlanco, Movimiento* movidaNegro) {
//
//	Turno* unTurno = new Turno();
//	int nro = obtenerNumeroTurno(nroTurno);
//	unTurno->setMovimientoBlanco(movidaBlanco);
//	unTurno->setMovimientoNegro(movidaNegro);
//	unTurno->setNroTurno(nro);
//
//	int pos = nroTurno.find(c_ANALIZAR, 0);
//	if (pos >= 0) {
//		unTurno->requirirAnalisis();
//	}
//	turnos->agregar(unTurno);
//}
//
//int PgnInterprete::obtenerNumeroTurno(string& nroTurno) {
//
//	int pos = nroTurno.find(c_ANALIZAR, 0);
//	if (pos < 0) {
//		pos = nroTurno.find('.', 0);
//	}
//	string nro = nroTurno.substr(0, pos);
//	return Util::stringToInt(nro);
//}
//
//void PgnInterprete::registrarPromocionDe(Movimiento* movimiento, string palabra) {
//	if (piezasPromocion == NULL) {
//		piezasPromocion = new ListaPPieza();
//	}
//	char simbolo = ((Promocion*)movimiento)->getSimboloPromocion();
//	PiezaJugadora* nuevaPiezaJugadora = factoryPiezaJugadora.crear(simbolo);
//	((Promocion*)movimiento)->setPiezaPromocion(nuevaPiezaJugadora);
//	Coordenada& destino = ((Promocion*)movimiento)->getDestino();
//	if (nuevaPiezaJugadora) {
//		piezasPromocion->agregar(new Pieza(nuevaPiezaJugadora, destino, simbolo));
//	}
//
//}
