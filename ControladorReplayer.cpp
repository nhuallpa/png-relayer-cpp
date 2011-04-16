/*
 * ControladorReplayer.cpp
 *
 *  Created on: 15/04/2011
 *      Author: administrador
 */

#include "ControladorReplayer.h"
using namespace std;

ControladorReplayer::ControladorReplayer(Ajedrez* ajedrez) {


}

ControladorReplayer::~ControladorReplayer() {

}

void ControladorReplayer::reproducir(PngAjedrez* entradaPng) {
	armarTableroInicial(entradaPng);
//	this.ejecutarMovidas(entradaPng);
//	this.armarTableroFinal(entradaPng);
}

void ControladorReplayer::armarTableroInicial(PngAjedrez* entradaPng)
{
	string cadenaFilaActual;
	for (int nroFila = AJ_CANT_FILAS; nroFila > 0; nroFila--) {
		cadenaFilaActual = entradaPng->dameFila(nroFila);
		construirFila(cadenaFilaActual, nroFila);
	}
}

void ControladorReplayer::construirFila(string cadenaFilaActual, int nroFila) {

	for (int indice = 0; indice < cadenaFilaActual.size(); indice++) {
		//todo: aca me quede
	}
}




