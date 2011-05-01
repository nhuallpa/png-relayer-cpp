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
	piezasPromocion = NULL;
	turnos = NULL;
	pgn = NULL;

}

void PgnInterprete::interpretar() {
	interpretarTableroInicial();
	interpretarTurnos();
}

void PgnInterprete::interpretarTurnos() {
	if (!turnos && pgn) {
		turnos = new ListaPTurno();
		stringstream& streamMovidas = pgn->getMovidas();
		while (!streamMovidas.eof()) {
			string palabra;

			streamMovidas>>palabra;
			if (!streamMovidas.good()) {
				break;
			}

			streamMovidas>>palabra;
			Movimiento* movimientoBlanco = NULL;
			movimientoBlanco = factoryMovimiento.crear(palabra, BLANCO);

			if (movimientoBlanco->tienePromocion()) {
				registrarPromocionDe(movimientoBlanco, palabra);
			}

			streamMovidas>>palabra;
			Movimiento* movimientoNegro = NULL;
			movimientoNegro = factoryMovimiento.crear(palabra, NEGRO);
			if (movimientoBlanco->tienePromocion()) {
				registrarPromocionDe(movimientoNegro, palabra);
			}

			Turno* unTurno = new Turno();
			unTurno->setMovimientoNegro(movimientoNegro);
			unTurno->setMovimientoBlanco(movimientoBlanco);
			turnos->agregar(unTurno);
		}
	}

}

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
									const Coordenada& coord, char simbolo){
	if (piezaJugadora) {
		piezasIniciales->agregar(new Pieza(piezaJugadora, coord, simbolo));
	}
}
void PgnInterprete::registrarPromocionDe(Movimiento* movimiento, string palabra) {
	if (piezasPromocion == NULL) {
		piezasPromocion = new ListaPPieza();
	}

	char simbolo = ((Promocion*)movimiento)->getSimboloPromocion();
	PiezaJugadora* nuevaPiezaJugadora = factoryPiezaJugadora.crear(simbolo);
	((Promocion*)movimiento)->setPiezaPromocion(nuevaPiezaJugadora);
	Coordenada& destino = ((Promocion*)movimiento)->getDestino();
	if (nuevaPiezaJugadora) {
		piezasPromocion->agregar(new Pieza(nuevaPiezaJugadora, destino, simbolo));
	}

}

void PgnInterprete::setPgn(PgnAjedrez *pgn) {
    this->pgn = pgn;
}

ListaPPieza* PgnInterprete::getPiezasIniciales() {
	return piezasIniciales;
}

ListaPTurno* PgnInterprete::getTurnos() {
	return turnos;
}

PgnInterprete::~PgnInterprete() {
	if (piezasIniciales){
		ListaPPieza::IteratorList it = piezasIniciales->getIterator();
		while (it.hasNext()) {
			delete it.next();
		}
		delete piezasIniciales;
	}
	if (turnos){
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






