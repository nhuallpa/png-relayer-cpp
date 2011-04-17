/*
 * Ajedrez.cpp
 *
 *  Created on: 15/04/2011
 *      Author: administrador
 */

#include "Ajedrez.h"

Ajedrez::Ajedrez() {
	cantFilas = AJ_CANT_FILAS;
	cantColumnas = AJ_CANT_COLUMNAS;
}


bool Ajedrez::hayFicha(int fila, int colum) {

	bool result = false;
	if (fila > 0 && fila < cantFilas &&
		colum > 0 && colum < cantColumnas) {
		result = (tablero[fila][colum].getPieza() != NULL);
	}

	return result;
}

Ajedrez::~Ajedrez() {

}
