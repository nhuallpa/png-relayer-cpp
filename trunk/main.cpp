//============================================================================
// Name        : main.cpp
// Author      : Nestor Huallpa
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include "PgnAjedrez.h"
#include "TableroAjedrez.h"
#include "ControladorReplayer.h"

#include "TestTableroAjedrez.h"
#include "TestPgnInterprete.h"
#include "TestPiezas.h"
#include "TestAnalizador.h"

using std::cin;

#define TEST
void iniciarEjecucion(PgnAjedrez* entradaPng) {
	TableroAjedrez ajedrez;
	VistaReplayer vista;
	ControladorReplayer controlador(&ajedrez, &vista);
	controlador.reproducir(entradaPng);
	controlador.mostrarResultados();
}

int main(int argc, char* argv[]) {
	tEstado estado = EXITOSO;
#ifdef TEST
	TestTableroAjedrez testSuitTablero;
	TestPgnInterprete testSuitPgn;
	TestPiezas testSuitPiezasJugadoras;
	TestAnalizador testSuitAnalizador;
	testSuitTablero.run();
	testSuitPgn.run();
	testSuitPiezasJugadoras.run();
	testSuitAnalizador.run();
#else
	PgnAjedrez entradaPng;
	if (argc == 2) {
		estado = entradaPng.cargarPng(argv[1]);
	} else if (argc == 1){
		cin >> entradaPng;
		estado = entradaPng.getEstado();
	} else if (argc > 2) {
		estado = CANT_PARAM_INV;
	}
	if (estado == EXITOSO) {
		iniciarEjecucion(&entradaPng);
	}
#endif


	return estado;
}
