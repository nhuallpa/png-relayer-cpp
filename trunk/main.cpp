//============================================================================
// Name        : main.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include "PngAjedrez.h"
#include "Ajedrez.h"
#include "ControladorReplayer.h"

#include "TestTableroAjedrez.h"

using namespace std;

#define TEST
void iniciarEjecucion(PngAjedrez* entradaPng) {
	Ajedrez ajedrez;
	ControladorReplayer controlador(&ajedrez);
//	VistaReplayer unaVista(ajedrez);
//	controlador.setVista(unaVista);
	controlador.reproducir(entradaPng);
	controlador.mostrarResultados();
}

int main(int argc, char* argv[]) {


#ifdef TEST
	TestTableroAjedrez testSuit;
	testSuit.run();
#else
	PngAjedrez entradaPng;
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
