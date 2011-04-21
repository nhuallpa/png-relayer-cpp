/*
 * PgnInterprete.cpp
 *
 *  Created on: 21/04/2011
 *      Author: Nestor Huallpa
 */

#include "PgnInterprete.h"

PgnInterprete::PgnInterprete() {
	// TODO Auto-generated constructor stub

}

PgnAjedrez *PgnInterprete::getPgn() const {
    return pgn;
}

void PgnInterprete::setPgn(PgnAjedrez *pgn) {
    this->pgn = pgn;
}

PgnInterprete::~PgnInterprete() {
	// TODO Auto-generated destructor stub
}

ListaPPieza* PgnInterprete::getPiezasIniciales() {
	return NULL;
}
