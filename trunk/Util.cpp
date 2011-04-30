/*
 * Util.cpp
 *
 *  Created on: 30/04/2011
 *      Author: administrador
 */

#include "Util.h"


int Util::charToInt(char c) {
	return (c - '0');
}

bool Util::esMayucula(char c) {
	return (c>='A' && c<='Z');
}


