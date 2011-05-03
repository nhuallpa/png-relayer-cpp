/*
 * Util.cpp
 *
 *  Created on: 30/04/2011
 *      Author: administrador
 */

#include "Util.h"
using namespace std;


int Util::charToInt(char c) {
	return (c - '0');
}

bool Util::esMayucula(char c) {
	return (c>='A' && c<='Z');
}

int Util::stringToInt(std::string nro) {
	int nroInt;
	stringstream stream;
	stream<<nro;
	stream>>nroInt;
	return nroInt;
}


