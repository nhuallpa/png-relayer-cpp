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
}

ControladorReplayer::~ControladorReplayer() {

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
	ListaPPieza* piezasIniciales = pgnInterprete.getPiezasIniciales();
	ListaPPieza::IteratorList itPiezasInicales = piezasIniciales->getIterator();
	while (itPiezasInicales.hasNext()) {
		Pieza* unaPieza = itPiezasInicales.next();
		tableroAjedrez->posionar(unaPieza->getPiezaJugadora(),
									unaPieza->getCoordenadaInicial());
	}
	// todo: resguardar la lista para visualizar
}


