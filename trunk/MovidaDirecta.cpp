/*
 * MovidaDirecta.cpp
 *
 *  Created on: 30/04/2011
 *      Author: administrador
 */

#include "MovidaDirecta.h"

MovidaDirecta::MovidaDirecta(const Coordenada &ori,const Coordenada &dest):
							origen(ori), destino(dest) {
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
