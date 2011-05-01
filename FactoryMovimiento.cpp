
/*
 * FactoryMovimiento.cpp
 *
 *  Created on: 30/04/2011
 *      Author: administrador
 */

#include "FactoryMovimiento.h"


Movimiento *FactoryMovimiento::crear(std::string palabra, tColor color) {
	Movimiento* movimiento = NULL;
	if (esMovimientoSimple(palabra) || esMovimientoSimpleCombinable(palabra)) {
		int i = (palabra.length() == 4)?0:1;
		Coordenada origen(Util::charToInt(palabra[i+1]), palabra[i+0]);
		Coordenada destino(Util::charToInt(palabra[i+3]), palabra[i+2]);
		Movimiento* movidaDirecta = new MovidaDirecta(origen, destino);
		movimiento = movidaDirecta;
	}

	if (esMate(palabra) || esJaque(palabra)) {
		int i = (palabra.length() == 5)?0:1;
		Coordenada origen(Util::charToInt(palabra[i+1]), palabra[i]);
		Coordenada destino(Util::charToInt(palabra[i+3]), palabra[i+2]);
		Movimiento* movidaDirecta = new MovidaDirecta(origen, destino);
		movimiento = movidaDirecta;
	}


	if (esEnroqueLargo(palabra)) {
		Movimiento* enroqueLargo = new EnroqueLargo(color);
		movimiento = enroqueLargo;
	}

	if (esEnroqueCorto(palabra)) {
		Movimiento* enroqueCorto= new EnroqueCorto(color);
		movimiento = enroqueCorto;
	}

	if (esPromocion(palabra)) {
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

bool FactoryMovimiento::esJaque(std::string palabra) {
	return ((palabra.size() == 5 && palabra[4] == c_JAQUE) ||
			(palabra.size() == 6 && palabra[5] == c_JAQUE));
}



bool FactoryMovimiento::esMate(std::string palabra) {
	return ((palabra.size() == 5 && palabra[4] == c_MATE) ||
			(palabra.size() == 6 && palabra[5] == c_MATE));
}



bool FactoryMovimiento::esEnroqueLargo(std::string palabra) {
	return (palabra.compare("0-0-0") == 0);
}



bool FactoryMovimiento::esPromocion(std::string palabra) {
	return (palabra.length() == 5 && Util::esMayucula(palabra[4]));
}



bool FactoryMovimiento::esEnroqueCorto(std::string palabra) {
	return (palabra.compare("0-0") == 0);
}



bool FactoryMovimiento::esMovimientoSimple(std::string palabra) {
	return (palabra.length() == 4);
}

bool FactoryMovimiento::esMovimientoSimpleCombinable(std::string palabra) {
	return (palabra.length() == 5) && Util::esMayucula(palabra[0]);
}

