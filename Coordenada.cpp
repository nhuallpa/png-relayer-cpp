/*
 * Coordenada.cpp
 *
 *  Created on: 21/04/2011
 *      Author: administrador
 */

#include "Coordenada.h"
using std::string;


Coordenada::Coordenada() {
	fila = 1;
	columna = 'a';
}
Coordenada::Coordenada(int fil, char colum) {
	fila = fil;
	columna = colum;
}

Coordenada::Coordenada(const Coordenada & coordena) {
	fila = coordena.getFila();
	columna = coordena.getColumna();
}

Coordenada::Coordenada(const Coordenada* coordena) {
	fila = coordena->getFila();
	columna = coordena->getColumna();
}

void Coordenada::operator=(const Coordenada & coordena) {
	fila = coordena.getFila();
	columna = coordena.getColumna();
}

bool Coordenada::operator==(const Coordenada & coordena) {
	return (fila == coordena.getFila() && columna == coordena.getColumna());
}
bool Coordenada::esIgual(const Coordenada & coordena) {
	return (fila == coordena.getFila() && columna == coordena.getColumna());
}



void Coordenada::setFila(int fila) {
    this->fila = fila;
}

string Coordenada::toString() {
	string fila(fila);
	string columna(columna);
	return columna + fila;
}

bool Coordenada::validaEnAjedrez() const {
	bool valida = false;
	if ( fila >= 1 && fila <= 8 &&
		 columna >='a' && columna <= 'h') {
		valida = true;
	}
	return valida;
}
