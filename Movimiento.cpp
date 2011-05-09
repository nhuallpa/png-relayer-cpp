/*
 * Movimiento.cpp
 *
 *  Created on: 30/04/2011
 *      Author: administrador
 */

#include "Movimiento.h"

Movimiento::Movimiento() {
	conPomocion = false;
}

bool Movimiento::tienePromocion() {
	return conPomocion;
}
Movimiento::~Movimiento() {
}



