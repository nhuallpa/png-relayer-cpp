/*
 * Reina.cpp
 *
 *  Created on: 21/04/2011
 *      Author: Nestor Huallpa
 */

#include "Reina.h"
#include "TableroAjedrez.h"

Reina::Reina() {
}

ListaPCoordenadas *Reina::coordDestinoDesde(const Coordenada & coord) {
	return NULL;
}

ListaPCoordenadas* Reina::filtrarCoordValidas(const Coordenada& coordenada,
										TableroAjedrez* unTablero) {
	ListaPCoordenadas* lCoordenadas = new ListaPCoordenadas();
	Coordenada coord(coordenada);
	lCoordenadas = cargarCoordValidas(lCoordenadas, coordenada, unTablero, NORTE);
	lCoordenadas = cargarCoordValidas(lCoordenadas, coordenada, unTablero, ESTE	);
	lCoordenadas = cargarCoordValidas(lCoordenadas, coordenada, unTablero, SUR);
	lCoordenadas = cargarCoordValidas(lCoordenadas, coordenada, unTablero, OESTE);
	lCoordenadas = cargarCoordValidas(lCoordenadas, coordenada, unTablero, NORESTE);
	lCoordenadas = cargarCoordValidas(lCoordenadas, coordenada, unTablero, SURESTE);
	lCoordenadas = cargarCoordValidas(lCoordenadas, coordenada, unTablero, SUROESTE);
	lCoordenadas = cargarCoordValidas(lCoordenadas, coordenada, unTablero, NOROESTE);
	return lCoordenadas;
}

Reina::~Reina() {
}
