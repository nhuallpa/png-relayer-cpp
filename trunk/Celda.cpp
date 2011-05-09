/*
 * Celda.cpp
 *
 *  Created on: 16/04/2011
 *      Author: administrador
 */

#include "Celda.h"

Celda::Celda() {
	piezaJugadora = NULL;
}

PiezaJugadora *Celda::getPiezaJugadora() const {
    return piezaJugadora;
}

void Celda::setPiezaJugadora(PiezaJugadora *piezaJugadora) {
    this->piezaJugadora = piezaJugadora;
}

Celda::~Celda() {
}
