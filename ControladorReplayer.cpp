/*
 * ControladorReplayer.cpp
 *
 *  Created on: 15/04/2011
 *      Author: administrador
 */

#include "ControladorReplayer.h"
using namespace std;

ControladorReplayer::ControladorReplayer(Ajedrez* unAjedrez) {
	ajedrez = unAjedrez;
}

ControladorReplayer::~ControladorReplayer() {

}

void ControladorReplayer::mostrarResultados() {
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

	int tamanio = cadenaFilaActual.size();
	int columnaLibre = 0;
	for (int indice = 0; indice < tamanio; indice++) {
		char indicador = cadenaFilaActual.at(indice);
		if (hayPosicionesVacias(indicador)) {
			int nroVacios = cadenaFilaActual[indice] - '0';
			columnaLibre += nroVacios;
		} else {
//			Pieza unaPieza = new Pieza();
//			ajedrez.registrarPieza(unaPieza);
//			ajedrez.posicionarFicha(posicion, unaPieza);
			columnaLibre++;
		}
	}
}

bool ControladorReplayer::hayPosicionesVacias(char indicador) {
	return (indicador >= '1' && indicador <= '8');
}













