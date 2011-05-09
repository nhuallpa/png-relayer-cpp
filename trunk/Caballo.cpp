/*
 * Caballo.cpp
 *
 *  Created on: 21/04/2011
 *      Author: Nestor Huallpa
 */

#include "Caballo.h"
#include "TableroAjedrez.h"

int despFila[8] = { 2, 1, -1, -2 , -2, -1,  1,  2};
int despColu[8] = { 1, 2,  2,  1 , -1, -2, -2, -1};



ListaPCoordenadas* Caballo::
filtrarCoordValidas(const Coordenada& coordenada, TableroAjedrez* unTablero) {
	ListaPCoordenadas* coordenasResultantes = NULL;
	coordenasResultantes = validarCoordenadasDestino(coordenada, unTablero);
	return coordenasResultantes;
}

ListaPCoordenadas* Caballo::validarCoordenadasDestino(
												const Coordenada& coordOrigen,
												TableroAjedrez* unTablero) {
	ListaPCoordenadas* lCoordenadas = new ListaPCoordenadas();
	for (int i = 0; i < 8; i++) {
		Coordenada coordAux;
		coordAux.setFila(coordOrigen.getFila() + despFila[i]);
		coordAux.setColumna(coordOrigen.getColumna() + despColu[i]);
		if (coordAux.validaEnAjedrez()) {
			if (!(unTablero->hayPiezaJugadora(coordAux))) {
				lCoordenadas->agregar(new Coordenada(coordAux));
			} else if (!(unTablero->getPiezaJugadora(coordAux)->esAliado(*this))) {
				lCoordenadas->agregar(new Coordenada(coordAux));
			}
		}
	}
	return lCoordenadas;
}

