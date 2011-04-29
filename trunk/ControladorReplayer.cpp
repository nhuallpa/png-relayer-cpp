/*
 * ControladorReplayer.cpp
 *
 *  Created on: 15/04/2011
 *      Author: Nestor Huallpa
 */

#include "ControladorReplayer.h"
using namespace std;

std::ostream& operator<< (ostream& out, VistaReplayer* vista){
	out<<vista->toString();
	return out;
}


ControladorReplayer::ControladorReplayer(TableroAjedrez* unAjedrez, VistaReplayer* unaVista) {
	tableroAjedrez = unAjedrez;
	vista = unaVista;
	piezasIniciales = NULL;
}

ControladorReplayer::~ControladorReplayer() {
}

void ControladorReplayer::mostrarResultados() {
	cout<<vista;
}


//  TODO:seguir con trablero Vista.
void ControladorReplayer::reproducir(PgnAjedrez* entradaPng) {

	pgnInterprete.setPgn(entradaPng);
	pgnInterprete.interpretar();
	prepararTableroInicial();
	vista->visualizar(tableroAjedrez, pgnInterprete.getPiezasIniciales());

//	this.ejecutarMovidas(entradaPng);
//	ReplayerVista<<analisisRealizado;
//	ReplayerVista<<tableroAjedrez;
}

void ControladorReplayer::prepararTableroInicial() {
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



