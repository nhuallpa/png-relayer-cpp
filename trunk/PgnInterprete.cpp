/*
 * PgnInterprete.cpp
 *
 *  Created on: 21/04/2011
 *      Author: Nestor Huallpa
 */

#include "PgnInterprete.h"
using namespace std;


PgnInterprete::PgnInterprete() {
	piezasIniciales = NULL;

}

PgnAjedrez *PgnInterprete::getPgn() const {
    return pgn;
}

void PgnInterprete::setPgn(PgnAjedrez *pgn) {
    this->pgn = pgn;
}

PgnInterprete::~PgnInterprete() {

	if (piezasIniciales){
		ListaPPieza::IteratorList it = piezasIniciales->getIterator();
		while (it.hasNext()) {
			delete it.next();
		}
		delete piezasIniciales;
	}

}

ListaPPieza* PgnInterprete::getPiezasIniciales() {
	return piezasIniciales;
}

void PgnInterprete::interpretar() {
	if (!piezasIniciales) {
		piezasIniciales = new ListaPPieza();
		Coordenada coord;
		for (int fila = PNG_CANT_FILA; fila > 0; fila--) {
			string filaString = pgn->dameFila(fila);
			for (size_t index = 0; index < filaString.length(); ++index) {
				char simbolo = filaString.at(index);
				PiezaJugadora* pJugadadora = factoryPiezaJugadora.crear(simbolo);
				if (pJugadadora) {
					piezasIniciales->agregar(new Pieza(pJugadadora, coord));
				}

			}
		}
	}
}


