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
}

void ControladorReplayer::mostrarResultados() {
}


//  todo:seguir con trablero Vista.
void ControladorReplayer::reproducir(PgnAjedrez* entradaPng) {
	prepararTableroInicial(entradaPng);
	//cout<<tableroVista.toString();
//	this.ejecutarMovidas(entradaPng);
//	cout<<analisisRealizado;
//	cout<<tableroVista;
}

void ControladorReplayer::prepararTableroInicial(PgnAjedrez* entradaPng) {
	pgnInterprete.setPgn(entradaPng);
	pgnInterprete.interpretar();
	piezasIniciales = pgnInterprete.getPiezasIniciales();
	if (piezasIniciales) {
		colocarPiezasIniciales();
	}
}
void ControladorReplayer::colocarPiezasIniciales(){
	ListaPPieza::IteratorList itPiezasInicales =
											piezasIniciales->getIterator();
    while(itPiezasInicales.hasNext()){
        Pieza *unaPieza = itPiezasInicales.next();
        tableroAjedrez->posionar(unaPieza->getPiezaJugadora(),
        								unaPieza->getCoordenadaInicial());
    }
}

