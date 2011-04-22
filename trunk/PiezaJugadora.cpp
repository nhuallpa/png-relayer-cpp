/*
 * PiezaJugadora.cpp
 *
 *  Created on: 21/04/2011
 *      Author: administrador
 */

#include "PiezaJugadora.h"

PiezaJugadora::PiezaJugadora() {
	color = SIN_COLOR;

}

tColor PiezaJugadora::getColor() const {
    return color;
}

void PiezaJugadora::setColor(tColor color) {
    this->color = color;
}

PiezaJugadora::~PiezaJugadora() {
	// TODO Auto-generated destructor stub
}
