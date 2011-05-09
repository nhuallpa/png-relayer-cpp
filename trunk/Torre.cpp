/*
 * Torre.cpp
 *
 *  Created on: 21/04/2011
 *      Author: Nestor Hualpa
 */

#include "Torre.h"
#include "TableroAjedrez.h"

ListaPCoordenadas *Torre::filtrarCoordValidas(const Coordenada & coordenada,
												TableroAjedrez *unTablero) {
	ListaPCoordenadas* lCoordenadas = new ListaPCoordenadas();
	Coordenada coord(coordenada);
	lCoordenadas = cargarCoordValidas(lCoordenadas, coordenada, unTablero, NORTE);
	lCoordenadas = cargarCoordValidas(lCoordenadas, coordenada, unTablero, ESTE);
	lCoordenadas = cargarCoordValidas(lCoordenadas, coordenada, unTablero, SUR);
	lCoordenadas = cargarCoordValidas(lCoordenadas, coordenada, unTablero, OESTE);
	return lCoordenadas;
}

