//============================================================================
// Name        : PngReplayer.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Png.h"


int main(int argc, char* argv[]) {

	tEstado estado = EXITOSO;
	Png entradaPng;
	if (argc == 2) {
		estado = entradaPng.cargarPng(argv[1]);
	} else if (argc == 1){
		estado = entradaPng.cargarPng(cin);
	} else if (argc > 2) {
		estado = CANT_PARAM_INV;
	}

	if (estado == EXITOSO) {
		cout<<entradaPng.getTableroInicial()<<endl;
		cout<<entradaPng.getMovidas()->str()<<endl;
		// ejecutar
	}

	return estado;
}
