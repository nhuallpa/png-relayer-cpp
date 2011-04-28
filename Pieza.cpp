/*
 * Pieza.cpp
 *
 *  Created on: 16/04/2011
 *      Author: Nestor Hualpa
 */

#include "Pieza.h"

Pieza::Pieza(PiezaJugadora* pJugadora, const Coordenada& coord, char simbolo) {
	piezaJugadora = pJugadora;
	coordenadaInicial.setFila(coord.getFila());
	coordenadaInicial.setColumna(coord.getColumna());
	setSymbol(simbolo);
}

Coordenada Pieza::getCoordenadaInicial() const {
    return coordenadaInicial;
}

PiezaJugadora *Pieza::getPiezaJugadora() const {
    return piezaJugadora;
}

void Pieza::setCoordenadaInicial(Coordenada coordenadaInicial) {
    this->coordenadaInicial = coordenadaInicial;
}

char Pieza::getSymbol() const
{
    return symbol;
}

void Pieza::setSymbol(char symbol)
{
    this->symbol = symbol;
}

void Pieza::setPiezaJugadora(PiezaJugadora *piezaJugadora) {
    this->piezaJugadora = piezaJugadora;
}

Pieza::~Pieza() {
	if (piezaJugadora) {
		delete piezaJugadora;
	}
}
