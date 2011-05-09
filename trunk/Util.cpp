/*
 * Util.cpp
 *
 *  Created on: 30/04/2011
 *      Author: administrador
 */

#include "Util.h"
using std::stringstream;
using std::string;


int Util::charToInt(char c) {
	return (c - '0');
}

bool Util::esMayucula(char c) {
	return (c >= 'A' && c <= 'Z');
}

int Util::stringToInt(string nro) {
	int nroInt;
	stringstream stream;
	stream << nro;
	stream >> nroInt;
	return nroInt;
}


