/*
 * EnroqueCorto.cpp
 *
 *  Created on: 30/04/2011
 *      Author: Nestor Huallpa
 */

#include "EnroqueCorto.h"

EnroqueCorto::EnroqueCorto(tColor color) {
	int fila = (color == NEGRO)?8:1;
	origenRey.setFila(fila);
	origenRey.setColumna('e');
	destinoRey.setFila(fila);
	destinoRey.setColumna('g');
	origenTorre.setFila(fila);
	origenTorre.setColumna('h');
	destinoTorre.setFila(fila);
	destinoTorre.setColumna('f');
}

