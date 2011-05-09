/*
 * PiezaJugadora.cpp
 *
 *  Created on: 21/04/2011
 *      Author: administrador
 */

#include "PiezaJugadora.h"
#include "TableroAjedrez.h"

PiezaJugadora::PiezaJugadora() {
	color = SIN_COLOR;
}

tColor PiezaJugadora::getColor() const {
    return color;
}

bool PiezaJugadora::esAliado(const PiezaJugadora & piezaJugadora) const {
	return (this->color == piezaJugadora.getColor());
}

bool PiezaJugadora::esAliado(const PiezaJugadora* piezaJugadora) const {
	return (this->color == piezaJugadora->getColor());
}

void PiezaJugadora::setColor(tColor color) {
    this->color = color;
}

PiezaJugadora::~PiezaJugadora() {
}

ListaPCoordenadas *PiezaJugadora::filtrarCoordValidas(
										const Coordenada & coorBlanco,
										TableroAjedrez *unTablero) {
	return NULL;
}

ListaPCoordenadas *PiezaJugadora::cargarCoordValidas(
										ListaPCoordenadas * listaCoord,
										const Coordenada & coordenada,
										TableroAjedrez *unTablero,
										tDireccionPaso dir) {
	if (listaCoord) {
		Coordenada coord(coordenada);
		bool continuar;
		coord.setFila(coord.getFila() + pasoFil[dir]);
		coord.setColumna(coord.getColumna() + pasoCol[dir]);
		continuar = true;
		while (coord.validaEnAjedrez() && continuar) {
			if (!(unTablero->hayPiezaJugadora(coord))) {
				listaCoord->agregar(new Coordenada(coord));
			} else {
				if (!(unTablero->getPiezaJugadora(coord)->esAliado(*this))) {
					listaCoord->agregar(new Coordenada(coord));
				}
				continuar = false;
			}
			coord.setFila(coord.getFila() + pasoFil[dir]);
			coord.setColumna(coord.getColumna() + pasoCol[dir]);
		}
	}
	return listaCoord;
}



bool PiezaJugadora::estaHabilitada(Coordenada* coordenada,
								   TableroAjedrez* unTablero) {
	bool valido = false;
	if  (!unTablero->hayPiezaJugadora(*coordenada)) {
		valido = true;
	} else {
		PiezaJugadora* piezaJugadora =
							unTablero->getPiezaJugadora(*coordenada);
		if (!this->esAliado(piezaJugadora)) {
			valido = true;
		}
	}
	return valido;
}



