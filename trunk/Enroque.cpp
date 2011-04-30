/*
 * Enroque.cpp
 *
 *  Created on: 30/04/2011
 *      Author: Nestor Huallpa
 */

#include "Enroque.h"

void Enroque::aplicarEn(TableroAjedrez* tablero){
	PiezaJugadora* rey = tablero->levantarPiezaJugadora(origenRey);
	PiezaJugadora* torre = tablero->levantarPiezaJugadora(origenTorre);
	if (rey && torre) {
		tablero->posionar(rey, destinoRey);
		tablero->posionar(torre, destinoTorre);
	} else {
		tablero->posionar(rey, origenRey);
		tablero->posionar(torre, origenTorre);
	}
}
