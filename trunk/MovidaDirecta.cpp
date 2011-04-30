/*
 * MovidaDirecta.cpp
 *
 *  Created on: 30/04/2011
 *      Author: administrador
 */

#include "MovidaDirecta.h"

MovidaDirecta::MovidaDirecta(int filaOrigen, char columnaOrigen,
		  	  	  	  	  	  int filaDestino, char columnaDestino) {
	origen.setFila(filaOrigen);
	origen.setColumna(columnaOrigen);
	destino.setFila(filaDestino);
	destino.setColumna(columnaDestino);
}

void MovidaDirecta::aplicarEn(TableroAjedrez* tablero) {
	PiezaJugadora* piezaJugadora = tablero->levantarPiezaJugadora(origen);
	if (piezaJugadora) {
		tablero->posionar(piezaJugadora, destino);
	}
}

MovidaDirecta::~MovidaDirecta() {
	// TODO Auto-generated destructor stub
}
