
/*
 * FactoryMovimiento.cpp
 *
 *  Created on: 30/04/2011
 *      Author: administrador
 */

#include "FactoryMovimiento.h"


Movimiento *FactoryMovimiento::crear(std::string palabra, tColor color) {
	Movimiento* movimiento = NULL;
	if (palabra.length() == 4) {
		Coordenada origen(Util::charToInt(palabra[1]), palabra[0]);
		Coordenada destino(Util::charToInt(palabra[3]), palabra[2]);
		Movimiento* movidaDirecta = new MovidaDirecta(origen, destino);
		movimiento = movidaDirecta;
	}

	if (palabra.compare("0-0-0") == 0) {
		Movimiento* enroqueLargo = new EnroqueLargo(color);
		movimiento = enroqueLargo;
	}

	if (palabra.compare("0-0") == 0) {
		Movimiento* enroqueCorto= new EnroqueCorto(color);
		movimiento = enroqueCorto;
	}

	if (palabra.length() == 5 && Util::esMayucula(palabra[4])) {
		char simbolo =  palabra[4];
		if (color == NEGRO) {
			simbolo = tolower(palabra[4]);
		}
		Coordenada origen(Util::charToInt(palabra[1]), palabra[0]);
		Coordenada destino(Util::charToInt(palabra[3]), palabra[2]);
		Movimiento* promocion = new Promocion(origen, destino, simbolo);
		movimiento = promocion;
	}

	if (movimiento == NULL) {
		movimiento = new NingunMovimiento();
	}
	return movimiento;
}

