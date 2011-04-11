/*
 * PngFile.cpp
 *
 *  Created on: 10/04/2011
 *      Author: administrador
 */

#include "Png.h"

Png::Png() {

	this->tableroInicial.clear();
	this->movidas.clear();

}

tEstado Png::cargarPng(char *rutaPng) {
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



tEstado Png::cargarPng(istream &inStream) {
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

stringstream*  Png::getMovidas() {
    return &movidas;
}

string Png::getTableroInicial() {
    return this->tableroInicial;
}



