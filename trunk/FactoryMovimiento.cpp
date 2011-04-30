
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

		Movimiento* movidaDirecta = new MovidaDirecta(Util::charToInt(palabra[1]), palabra[0],
													  Util::charToInt(palabra[3]), palabra[2]);
		movimiento = movidaDirecta;
	}

	if (palabra.compare("0-0-0") == 0) {
		Movimiento* enroqueLargo = new EnroqueLargo(color);
		movimiento = enroqueLargo;
	}

	if (palabra.compare("0-0") == 0) {
		Movimiento* enroqueLargo = new EnroqueCorto(color);
		movimiento = enroqueLargo;
	}

	if (palabra.length() == 5 && Util::esMayucula(palabra[4])) {
		char simbolo = palabra[4];
		Movimiento* enroqueLargo = new Promocion(simbolo);
		movimiento = enroqueLargo;
	}


	if (movimiento == NULL) {
		movimiento = new NingunMovimiento();
	}
	return movimiento;
}

