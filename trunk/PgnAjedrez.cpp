/*
 * PgnFile.cpp
 *
 *  Created on: 10/04/2011
 *      Author: Nestor Huallpa
 */

#include "PgnAjedrez.h"
using std::string;
using std::istream;
using std::stringstream;
using std::ifstream;
using std::endl;

istream& operator >> (istream &in, PgnAjedrez& pgn) {
	pgn.cargarPng(in);
	return in;
}


PgnAjedrez::PgnAjedrez() {
	this->tableroInicial.clear();
	this->movidas.clear();
	estado = PNG_NO_ENCONTRADO;
}

tEstado PgnAjedrez::cargarPng(char *rutaPng) {
	estado = EXITOSO;
	string lineaBuffer;
	ifstream in(rutaPng);
	if (in.is_open()) {
		getline(in, this->tableroInicial);
		getline(in, lineaBuffer);
		while (!in.eof()) {
			getline(in, lineaBuffer);
			this->movidas << lineaBuffer << endl;
		}
	} else {
		estado = PNG_NO_ENCONTRADO;
	}
	return estado;
}



tEstado PgnAjedrez::cargarPng(istream &inStream) {
	estado = EXITOSO;
	string lineaBuffer;
	getline(inStream, this->tableroInicial);
	getline(inStream, lineaBuffer);
	while (!inStream.eof()) {
		getline(inStream, lineaBuffer);
		this->movidas << lineaBuffer << endl;
	}
	return estado;
}

string PgnAjedrez::dameFila(int nroFila) {
	int posIni = 0;
	string fila = "";
	int nroToken = PNG_CANT_FILA - nroFila + 1;
	for (int filaActual = 0; filaActual < nroToken; filaActual++) {
		size_t posEntontrado;
		if (filaActual == (PNG_CANT_FILA-1)) {
			posEntontrado = tableroInicial.find(' ', posIni);
		} else {
			posEntontrado = tableroInicial.find('/', posIni);
		}
		if (posEntontrado != string::npos) {
			fila = tableroInicial.substr(posIni, posEntontrado - posIni);
			posIni = posEntontrado + 1;
		}
	}
	return fila;
}

stringstream&  PgnAjedrez::getMovidas() {
    return movidas;
}
tEstado PgnAjedrez::getEstado() const {
    return estado;
}


string PgnAjedrez::getTableroInicial() {
    return this->tableroInicial;
}

char PgnAjedrez::getSimboloSiguienteJugador() {
    return this->tableroInicial[this->tableroInicial.length() - 1];
}



