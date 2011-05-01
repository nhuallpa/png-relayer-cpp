/*
 * Promocion.cpp
 *
 *  Created on: 30/04/2011
 *      Author: Nestor Huallpa
 */

#include "Promocion.h"

Promocion::Promocion(const Coordenada &ori,const Coordenada &dest, char simbolo):
					origen(ori), destino(dest) {
	piezaPromocion = NULL;
	conPomocion = true;
	simboloPromocion = simbolo;
}

void Promocion::aplicarEn(TableroAjedrez* tablero) {
	PiezaJugadora* peon = tablero->levantarPiezaJugadora(origen);
	if (peon){
		if (piezaPromocion) {
			tablero->posionar(piezaPromocion, destino);
		} else {
			tablero->posionar(peon, origen);
		}
	}
}

void Promocion::setPiezaPromocion(PiezaJugadora* piezaJugadora) {
	piezaPromocion = piezaJugadora;
}

char Promocion::getSimboloPromocion() {
	return simboloPromocion;
}

Coordenada& Promocion::getDestino() {
	return destino;
}

