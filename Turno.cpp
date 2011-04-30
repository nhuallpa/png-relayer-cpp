/*
 * Turnos.cpp
 *
 *  Created on: 29/04/2011
 *      Author: Nestor Huallpa
 */

#include "Turno.h"

Turno::Turno() {
	movimientoBlanco = NULL;
	movimientoNegro = NULL;
}

Movimiento *Turno::getMovimientoBlanco() const
{
    return movimientoBlanco;
}

Movimiento *Turno::getMovimientoNegro() const
{
    return movimientoNegro;
}

void Turno::setMovimientoBlanco(Movimiento *movimientoBlanco)
{
    this->movimientoBlanco = movimientoBlanco;
}

void Turno::setMovimientoNegro(Movimiento *movimientoNegro)
{
    this->movimientoNegro = movimientoNegro;
}

Turno::~Turno() {
	if (movimientoBlanco) {
		delete movimientoBlanco;
	}
	if (movimientoNegro) {
		delete movimientoNegro;
	}
}
