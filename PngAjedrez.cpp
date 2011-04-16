/*
 * PngFile.cpp
 *
 *  Created on: 10/04/2011
 *      Author: administrador
 */

#include "PngAjedrez.h"
using namespace std;


PngAjedrez::PngAjedrez() {

	this->tableroInicial.clear();
	this->movidas.clear();

}

tEstado PngAjedrez::cargarPng(char *rutaPng) {
	tEstado estado = EXITOSO;
	string lineaBuffer;
	ifstream in(rutaPng);
	if (in.is_open()) {
		getline(in, this->tableroInicial);
		getline(in, lineaBuffer);
		while (!in.eof()) {
			getline(in, lineaBuffer);
			this->movidas<<lineaBuffer<<endl;
		}
		in.close();
	} else {
		estado = PNG_NO_ENCONTRADO;
	}
	return estado;
}



tEstado PngAjedrez::cargarPng(istream &inStream) {
	tEstado estado = EXITOSO;
	string lineaBuffer;
	getline(inStream, this->tableroInicial);
	getline(inStream, lineaBuffer);
	while (!inStream.eof()) {
		getline(inStream, lineaBuffer);
		this->movidas<<lineaBuffer<<endl;
	}
	return estado;
}

string PngAjedrez::dameFila(int nroFila) {
	int posIni = 0;
	string fila = "";
	int nroToken = PNG_CANT_FILA - nroFila + 1;
	for (int i = 0; i<nroToken; i++) {
		size_t posEntontrado = tableroInicial.find('/', posIni);
		if (posEntontrado != string::npos) {
			fila = tableroInicial.substr(posIni, posEntontrado - posIni);
			posIni = posEntontrado + 1;
		}
	}
	return fila;
}


// todo: quitar despues
stringstream*  PngAjedrez::getMovidas() {
    return &movidas;
}
string PngAjedrez::getTableroInicial() {
    return this->tableroInicial;
}



