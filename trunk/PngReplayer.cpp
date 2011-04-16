//============================================================================
// Name        : PngReplayer.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "PngAjedrez.h"
#include "Ajedrez.h"
#include "ControladorReplayer.h"
using namespace std;


void iniciarEjecucion(PngAjedrez* entradaPng) {
	Ajedrez ajedrez;
	ControladorReplayer controlador(&ajedrez);
//	VistaReplayer unaVista(ajedrez);
//	controlador.setVista(unaVista);
	controlador.reproducir(entradaPng);
	//controlador.mostrarResultados();
}

int main(int argc, char* argv[]) {

	tEstado estado = EXITOSO;
	PngAjedrez entradaPng;
	if (argc == 2) {
		estado = entradaPng.cargarPng(argv[1]);
	} else if (argc == 1){
		estado = entradaPng.cargarPng(cin);
	} else if (argc > 2) {
		estado = CANT_PARAM_INV;
	}

	if (estado == EXITOSO) {
		// TODO: 	borrar luego
//		cout<<entradaPng.getTableroInicial()<<endl;
//		cout<<entradaPng.getMovidas()->str()<<endl;
		iniciarEjecucion(&entradaPng);
	}

	return estado;
}
