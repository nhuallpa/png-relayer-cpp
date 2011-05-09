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
	hay_QueAnalizar = false;
}

Movimiento *Turno::getMovimientoBlanco() const {
    return movimientoBlanco;
}

Movimiento *Turno::getMovimientoNegro() const {
    return movimientoNegro;
}

void Turno::setMovimientoBlanco(Movimiento *movimientoBlanco) {
    this->movimientoBlanco = movimientoBlanco;
}

void Turno::setMovimientoNegro(Movimiento *movimientoNegro) {
    this->movimientoNegro = movimientoNegro;
}

void Turno::requirirAnalisis() {
	hay_QueAnalizar = true;
}

bool Turno::getHay_QueAnalizar() const {
    return hay_QueAnalizar;
}

int Turno::getNroTurno() const {
    return nroTurno;
}

void Turno::setHay_QueAnalizar(bool hay_QueAnalizar) {
    this->hay_QueAnalizar = hay_QueAnalizar;
}

Coordenada Turno::getCoordOrigenBlanco() const {
    return coordOrigenBlanco;
}

Coordenada Turno::getCoordOrigenNegro() const {
    return coordOrigenNegro;
}

void Turno::setCoordOrigenBlanco(Coordenada& coordOrigenBlanco) {
    this->coordOrigenBlanco = coordOrigenBlanco;
}

void Turno::setCoordOrigenNegro(Coordenada& coordOrigenNegro) {
    this->coordOrigenNegro = coordOrigenNegro;
}

void Turno::setNroTurno(int nroTurno) {
    this->nroTurno = nroTurno;
}

bool Turno::requiereAnalisis() {
	return hay_QueAnalizar;
}

Turno::~Turno() {
	if (movimientoBlanco) {
		delete movimientoBlanco;
	}
	if (movimientoNegro) {
		delete movimientoNegro;
	}
}

