/*
 * FactoryPiezaJugadora.cpp
 *
 *  Created on: 21/04/2011
 *      Author: administrador
 */

#include "FactoryPiezaJugadora.h"

FactoryPiezaJugadora::FactoryPiezaJugadora() {


}

PiezaJugadora *FactoryPiezaJugadora::crear(char simbolo) {
	PiezaJugadora* pJugadora = NULL;
	if (simbolo == 'p') {
		pJugadora = new PiezaJugadora();
		pJugadora->setColor(NEGRO);
	}
	if (simbolo == 'P') {
		pJugadora = new PiezaJugadora();
		pJugadora->setColor(BLANCO);
	}

	return pJugadora;
}

FactoryPiezaJugadora::~FactoryPiezaJugadora() {

}
