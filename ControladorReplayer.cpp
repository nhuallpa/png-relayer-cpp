/*
 * ControladorReplayer.cpp
 *
 *  Created on: 15/04/2011
 *      Author: Nestor Huallpa
 */

#include "ControladorReplayer.h"
using namespace std;

ControladorReplayer::ControladorReplayer(TableroAjedrez* unAjedrez) {
	tableroAjedrez = unAjedrez;
	piezasIniciales = NULL;
}

ControladorReplayer::~ControladorReplayer() {
	if (piezasIniciales) {
		//todo: liberar lista y sus datas
	}
}

void ControladorReplayer::mostrarResultados() {
}

void ControladorReplayer::reproducir(PgnAjedrez* entradaPng) {
	prepararTableroInicial(entradaPng);
//	this.ejecutarMovidas(entradaPng);
//	this.armarTableroFinal(entradaPng);
}

void ControladorReplayer::prepararTableroInicial(PgnAjedrez* entradaPng) {
	pgnInterprete.setPgn(entradaPng);
	piezasIniciales = pgnInterprete.getPiezasIniciales();
	if (piezasIniciales) {
		ListaPPieza::IteratorList itPiezasInicales = piezasIniciales->getIterator();
		while (itPiezasInicales.hasNext()) {
			Pieza* unaPieza = itPiezasInicales.next();
			tableroAjedrez->posionar(unaPieza->getPiezaJugadora(),
					unaPieza->getCoordenadaInicial());
		}
	}

}


