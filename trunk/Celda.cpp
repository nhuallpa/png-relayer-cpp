/*
 * Celda.cpp
 *
 *  Created on: 16/04/2011
 *      Author: administrador
 */

#include "Celda.h"

Celda::Celda() {
	pieza = NULL;

}

Pieza *Celda::getPieza() const
{
    return pieza;
}

void Celda::setPieza(Pieza *pieza)
{
    this->pieza = pieza;
}

Celda::~Celda() {
}
