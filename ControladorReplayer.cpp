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

void ControladorReplayer::reproducir(PgnAjedrez* entradaPng) {
	prepararTableroInicial(entradaPng);
//	this.ejecutarMovidas(entradaPng);
//	this.armarTableroFinal(entradaPng);
}

/*
 * todo: Tests
 * test interprete piezas coordenadas y colores
 * test coordenadas de la pieza
 * test posicionar de tablero
 *
 * */
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

