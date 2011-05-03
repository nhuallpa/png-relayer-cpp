/*
 * Ajedrez.cpp
 *
 *  Created on: 15/04/2011
 *      Author: Nestor Huallpa
 */

#include "TableroAjedrez.h"
#include "PiezaJugadora.h"

TableroAjedrez::TableroAjedrez() {
	cantFilas = AJ_CANT_FILAS;
	cantColumnas = AJ_CANT_COLUMNAS;
}

bool TableroAjedrez::hayPiezaJugadora(int fila, char columna) {
	Coordenada coord;
	coord.setFila(fila);
	coord.setColumna(columna);
	return hayPiezaJugadora(coord);
}

bool TableroAjedrez::hayPiezaJugadora(const Coordenada &coord) {
	bool result = false;
	int i = filaToIndice(coord.getFila());
	int j = columnaToIndice(coord.getColumna());

	if (indicesValidos(i, j)) {
		result = (tablero[i][j].getPiezaJugadora() != NULL);
	}
	return result;
}

PiezaJugadora *TableroAjedrez::getPiezaJugadora(const Coordenada &coord) {
	return getPiezaJugadora(coord.getFila(), coord.getColumna());
}

PiezaJugadora *TableroAjedrez::getPiezaJugadora(int fila, char columna) {

	PiezaJugadora* result = NULL;

	int i = filaToIndice(fila);
	int j = columnaToIndice(columna);

	if (indicesValidos(i, j)) {
		result = tablero[i][j].getPiezaJugadora();
	}
	return result;
}


void TableroAjedrez::posionar(PiezaJugadora *piezaJugadora, const Coordenada &coord) {

	//  i 0 es FilaAjedrez 1
	//  j 0 es la columnaTablero a

	int i = filaToIndice(coord.getFila());
	int j = columnaToIndice(coord.getColumna());

	if (indicesValidos(i, j)) {
		tablero[i][j].setPiezaJugadora(piezaJugadora);
	}
}

PiezaJugadora* TableroAjedrez::levantarPiezaJugadora(const Coordenada &coord) {

	PiezaJugadora* pieza = getPiezaJugadora(coord.getFila(), coord.getColumna());
	posionar(NULL, coord);
	return pieza;
}

bool TableroAjedrez::indicesValidos(int i, int j) {
	return (i >= 0 && i < cantFilas &&
			j >= 0 && j < cantColumnas);
}

int TableroAjedrez::columnaToIndice(char columna) {
	return columna - 'a';
}

int TableroAjedrez::filaToIndice(int fila) {
	return fila - 1;
}






