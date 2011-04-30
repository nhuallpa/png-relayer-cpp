/*
 * TestTableroAjedrez.cpp
 *
 *  Created on: 16/04/2011
 *      Author: administrador
 */

#include "TestTableroAjedrez.h"
#include "Coordenada.h"

using namespace std;



void TestTableroAjedrez::testTableroVacio() {
	stringstream streamtest;

	streamtest<<"rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w"<<endl;
	streamtest<<endl;
	streamtest<<""<<endl;

	Coordenada coord;
	TableroAjedrez ajedrez;
	for (int fila = 1; fila <= ajedrez.getCantFilas(); fila++) {
		for (char colum = 'a'; colum <= 'h'; colum++) {
			coord.setColumna(colum);
			coord.setFila(fila);
			Assert::assertFalse(ajedrez.hayPiezaJugadora(coord), "testTableroVacio");
		}
	}
}

void TestTableroAjedrez::testTableroCargado() {
	stringstream streamtest;

	streamtest<<"rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w"<<endl;
	streamtest<<endl;
	streamtest<<""<<endl;

	PgnAjedrez entradaPng;
	entradaPng.cargarPng(streamtest);
	TableroAjedrez ajedrez;
	VistaReplayer vista;
	ControladorReplayer controlador(&ajedrez, &vista);
	controlador.reproducir(&entradaPng);


	Coordenada coord;
	for (int fila = 1; fila <= 2; fila++) {
		for (char colum = 'a'; colum <= 'h'; colum++) {
			coord.setColumna(colum);
			coord.setFila(fila);
			Assert::assertTrue(ajedrez.hayPiezaJugadora(coord), "testTableroCargado-Blancas");
		}
	}

	for (int fila = 3; fila <= 6; fila++) {
		for (char colum = 'a'; colum <= 'h'; colum++) {
			coord.setColumna(colum);
			coord.setFila(fila);
			Assert::assertFalse(ajedrez.hayPiezaJugadora(coord), "testTableroCargado-Nada");
		}
	}
	for (int fila = 7; fila <= ajedrez.getCantFilas(); fila++) {
		for (char colum = 'a'; colum <= 'h'; colum++) {
			coord.setColumna(colum);
			coord.setFila(fila);
			Assert::assertTrue(ajedrez.hayPiezaJugadora(coord), "testTableroCargado-Negras");
		}
	}


}

void TestTableroAjedrez::run() {
	testTableroVacio();
	testTableroCargado();
}
