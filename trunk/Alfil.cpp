/*
 * Alfil.cpp
 *
 *  Created on: 21/04/2011
 *      Author: Nestor Huallpa
 */

#include "Alfil.h"
#include "TableroAjedrez.h"


ListaPCoordenadas *Alfil::filtrarCoordValidas(const Coordenada & coordenada,
												TableroAjedrez *unTablero) {
	ListaPCoordenadas * lCoordenadas = new ListaPCoordenadas();
	lCoordenadas = cargarCoordValidas(lCoordenadas, coordenada,
											unTablero, NORESTE);
	lCoordenadas = cargarCoordValidas(lCoordenadas, coordenada,
											unTablero, SURESTE);
	lCoordenadas = cargarCoordValidas(lCoordenadas, coordenada,
											unTablero, SUROESTE);
	lCoordenadas = cargarCoordValidas(lCoordenadas, coordenada,
											unTablero, NOROESTE);
	return lCoordenadas;
}
