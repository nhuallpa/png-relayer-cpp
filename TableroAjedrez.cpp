/*
 * Ajedrez.cpp
 *
 *  Created on: 15/04/2011
 *      Author: Nestor Huallpa
 */

#include "TableroAjedrez.h"

TableroAjedrez::TableroAjedrez() {
	cantFilas = AJ_CANT_FILAS;
	cantColumnas = AJ_CANT_COLUMNAS;
}


bool TableroAjedrez::hayFicha(int fila, int colum) {

	bool result = false;
	if (fila > 0 && fila < cantFilas &&
		colum > 0 && colum < cantColumnas) {
		result = (tablero[fila][colum].getPiezaJugadora() != NULL);
	}

	return result;
}

TableroAjedrez::~TableroAjedrez() {

}


// todo: seguir con getPieza de tablero;
void TableroAjedrez::posionar(PiezaJugadora *piezaJugadora, const Coordenada &coord) {

	int fila = coord.getFila() - 1;
	int columna = coord.getColumna() - 'a';

	if (fila > 0 && fila < AJ_CANT_FILAS && columna > 0 && columna <AJ_CANT_COLUMNAS ) {
		tablero[fila][columna].setPiezaJugadora(piezaJugadora);
	}

}


