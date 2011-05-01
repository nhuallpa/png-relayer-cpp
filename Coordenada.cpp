/*
 * Coordenada.cpp
 *
 *  Created on: 21/04/2011
 *      Author: administrador
 */

#include "Coordenada.h"

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

char Coordenada::getColumna() const {
    return columna;
}

int Coordenada::getFila() const {
    return fila;
}

void Coordenada::setColumna(char columna) {
    this->columna = columna;
}

void Coordenada::setFila(int fila) {
    this->fila = fila;
}

Coordenada::~Coordenada() {

}
