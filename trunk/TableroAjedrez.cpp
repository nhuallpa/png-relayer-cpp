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


bool TableroAjedrez::hayPiezaJugadora(const Coordenada &coord) {

	bool result = false;

	int fila = coord.getFila() - 1;
	int columna = coord.getColumna() - 'a';

	if (fila >= 0 && fila < cantFilas &&
			columna >= 0 && columna < cantColumnas) {
		result = (tablero[fila][columna].getPiezaJugadora() != NULL);
	}

	return result;
}


void TableroAjedrez::posionar(PiezaJugadora *piezaJugadora, const Coordenada &coord) {

	//  Fila 0 es FilaAjedrez 1
	//  Columna 0 es la columnaTablero a

	int fila = coord.getFila() - 1;
	int columna = coord.getColumna() - 'a';

	if (fila >= 0 && fila < AJ_CANT_FILAS &&
		columna >= 0 && columna < AJ_CANT_COLUMNAS ) {
		tablero[fila][columna].setPiezaJugadora(piezaJugadora);
	}

}


