/*
 * FactoryPiezaJugadora.cpp
 *
 *  Created on: 21/04/2011
 *      Author: Nestor Huallpa
 */

#include "FactoryPiezaJugadora.h"

char idPiezas[6] = {'P', 'R', 'N', 'B', 'Q', 'K'};

FactoryPiezaJugadora::FactoryPiezaJugadora() {
	creadores[0] = new CreadorEstandar<Peon>();
	creadores[1] = new CreadorEstandar<Torre>();
	creadores[2] = new CreadorEstandar<Caballo>();
	creadores[3] = new CreadorEstandar<Alfil>();
	creadores[4] = new CreadorEstandar<Reina>();
	creadores[5] = new CreadorEstandar<Rey>();
}

PiezaJugadora *FactoryPiezaJugadora::crear(char simbolo) {
	char simboloId = toupper(simbolo);
	PiezaJugadora* pJugadora = NULL;

	for (int index = 0; index < CANT_PIEZAS; ++index) {
		if (idPiezas[index] == simboloId) {
			pJugadora = creadores[index]->getInstancia();
		}
	}
	if (pJugadora) {
		if (esMinuscula(simbolo)) {
			pJugadora->setColor(NEGRO);
		} else {
			pJugadora->setColor(BLANCO);
		}
	}
	return pJugadora;
}

bool FactoryPiezaJugadora::esMinuscula(char value) {
	return (value >= 'a' && value <= 'z');
}

FactoryPiezaJugadora::~FactoryPiezaJugadora() {
	for (int index = 0; index < CANT_PIEZAS; index++) {
		delete creadores[index];
	}
}


