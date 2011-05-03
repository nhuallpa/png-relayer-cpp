/*
 * PiezaJugadora.cpp
 *
 *  Created on: 21/04/2011
 *      Author: administrador
 */

#include "PiezaJugadora.h"
#include "TableroAjedrez.h"

PiezaJugadora::PiezaJugadora() {
	color = SIN_COLOR;
}

tColor PiezaJugadora::getColor() const {
    return color;
}

bool PiezaJugadora::esAliado(const PiezaJugadora & piezaJugadora) const{
	return (this->color == piezaJugadora.getColor());
}

bool PiezaJugadora::esAliado(const PiezaJugadora* piezaJugadora) const {
	return (this->color == piezaJugadora->getColor());
}

void PiezaJugadora::setColor(tColor color) {
    this->color = color;
}

PiezaJugadora::~PiezaJugadora() {

}

ListaPCoordenadas *PiezaJugadora::filtrarCoordValidas(const Coordenada & coorBlanco, TableroAjedrez *unTablero) {
	return NULL;
}


bool PiezaJugadora::estaHabilitada(Coordenada* coordenada, TableroAjedrez* unTablero) {
	bool valido = false;
	if  (!unTablero->hayPiezaJugadora(*coordenada)){
		valido = true;
	} else {
		PiezaJugadora* piezaJugadora = unTablero->getPiezaJugadora(*coordenada);
		if (!this->esAliado(piezaJugadora)){
			valido = true;
		}
	}
	return valido;
}

