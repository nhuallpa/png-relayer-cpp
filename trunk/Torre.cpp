/*
 * Torre.cpp
 *
 *  Created on: 21/04/2011
 *      Author: Nestor Hualpa
 */

#include "Torre.h"
#include "TableroAjedrez.h"

Torre::Torre() {

}

ListaPCoordenadas *Torre::coordDestinoDesde(const Coordenada & coord) {
	return NULL;
}



ListaPCoordenadas *Torre::filtrarCoordValidas(const Coordenada & coordenada, TableroAjedrez *unTablero) {

	ListaPCoordenadas* lCoordenadas = new ListaPCoordenadas();
	Coordenada coord(coordenada);

	bool continuar;

	//  Norte
	coord.setFila(coord.getFila() + 1);
	continuar = true;
	while (coord.validaEnAjedrez() && continuar) {
		if (unTablero->hayPiezaJugadora(coord)) {
			continuar = false;
			if (!unTablero->getPiezaJugadora(coord)->esAliado(*this)) {
				lCoordenadas->agregar(new Coordenada(coord));
			}
		} else {
			lCoordenadas->agregar(new Coordenada(coord));
		}
		coord.setFila(coord.getFila() + 1);
	}

	//  Este
	coord = coordenada;
	coord.setColumna(coord.getColumna() + 1);
	continuar = true;
	while (coord.validaEnAjedrez() && continuar) {
		if (unTablero->hayPiezaJugadora(coord)) {
			continuar = false;
			if (!unTablero->getPiezaJugadora(coord)->esAliado(*this)) {
				lCoordenadas->agregar(new Coordenada(coord));
			}
		} else {
			lCoordenadas->agregar(new Coordenada(coord));
		}
		coord.setColumna(coord.getColumna() + 1);
	}

	//  Sur
	coord = coordenada;
	coord.setFila(coord.getFila() - 1);
	continuar = true;
	while (coord.validaEnAjedrez() && continuar) {
		if (unTablero->hayPiezaJugadora(coord)) {
			continuar = false;
			if (!unTablero->getPiezaJugadora(coord)->esAliado(*this)) {
				lCoordenadas->agregar(new Coordenada(coord));
			}
		} else {
			lCoordenadas->agregar(new Coordenada(coord));
			}
		coord.setFila(coord.getFila() - 1);
	}

	//  Oeste
	coord = coordenada;
	coord.setColumna(coord.getColumna() - 1);
	continuar = true;
	while (coord.validaEnAjedrez() && continuar) {
		if (unTablero->hayPiezaJugadora(coord)) {
			continuar = false;
			if (!unTablero->getPiezaJugadora(coord)->esAliado(*this)) {
				lCoordenadas->agregar(new Coordenada(coord));
			}
		} else {
			lCoordenadas->agregar(new Coordenada(coord));
		}
		coord.setColumna(coord.getColumna() - 1);
	}

	return lCoordenadas;

}

Torre::~Torre() {

}

