/*
 * PgnInterprete.cpp
 *
 *  Created on: 21/04/2011
 *      Author: Nestor Huallpa
 */

#include "PgnInterprete.h"



using std::string;

PgnInterprete::PgnInterprete() {
	piezasIniciales = NULL;
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
}

void PgnInterprete::interpretar() {
	interpretarTableroInicial();
	interpreteTurno.interpretarTurnos();
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
			Coordenada coord;
			coord.setFila(fila);
			coord.setColumna('a' + columna);
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


ListaPPieza* PgnInterprete::getPiezasPromocion() {
	 return interpreteTurno.getPiezasPromocion();
}

ListaPTurno* PgnInterprete::getTurnos() {
	 return interpreteTurno.getTurnos();
}

