/*
 * Pieza.cpp
 *
 *  Created on: 16/04/2011
 *      Author: administrador
 */

#include "Pieza.h"

Pieza::Pieza(PiezaJugadora* pJugadora, const Coordenada& coord) {
	piezaJugadora = pJugadora;
}

Coordenada Pieza::getCoordenadaInicial() const
{
    return coordenadaInicial;
}

PiezaJugadora *Pieza::getPiezaJugadora() const
{
    return piezaJugadora;
}

void Pieza::setCoordenadaInicial(Coordenada coordenadaInicial)
{
    this->coordenadaInicial = coordenadaInicial;
}

void Pieza::setPiezaJugadora(PiezaJugadora *piezaJugadora)
{
    this->piezaJugadora = piezaJugadora;
}

Pieza::~Pieza() {
	if (piezaJugadora) {
		delete piezaJugadora;
	}
}
