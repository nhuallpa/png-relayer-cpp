/*
 * EnroqueLargo.cpp
 *
 *  Created on: 30/04/2011
 *      Author: administrador
 */

#include "EnroqueLargo.h"


EnroqueLargo::EnroqueLargo(tColor color) {

	int fila = (color == NEGRO)?8:1;
	origenRey.setFila(fila);
	origenRey.setColumna('e');
	destinoRey.setFila(fila);
	destinoRey.setColumna('c');
	origenTorre.setFila(fila);
	origenTorre.setColumna('a');
	destinoTorre.setFila(fila);
	destinoTorre.setColumna('d');
}


