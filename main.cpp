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

using namespace std;

#define TEST
void iniciarEjecucion(PgnAjedrez* entradaPng) {
	TableroAjedrez ajedrez;
	ControladorReplayer controlador(&ajedrez);
//	VistaReplayer unaVista(ajedrez);
//	controlador.setVista(unaVista);
	controlador.reproducir(entradaPng);
	controlador.mostrarResultados();
}

int main(int argc, char* argv[]) {


#ifdef TEST
	TestTableroAjedrez testSuit;
	TestPgnInterprete testSuitPgn;
	//testSuit.run();
	testSuitPgn.run();
#else
	PgnAjedrez entradaPng;
	if (argc == 2) {
		estado = entradaPng.cargarPng(argv[1]);
	} else if (argc == 1){
		estado = entradaPng.cargarPng(cin);
	} else if (argc > 2) {
		estado = CANT_PARAM_INV;
	}
	if (estado == EXITOSO) {
// 		TODO: borrar luego
//		cout<<entradaPng.getTableroInicial()<<endl;
//		cout<<entradaPng.getMovidas()->str()<<endl;
		iniciarEjecucion(&entradaPng);
	}
#endif
	tEstado estado = EXITOSO;

	return estado;
}