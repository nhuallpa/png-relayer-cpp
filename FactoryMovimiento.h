/*
 * FactoryMovimiento.h
 *
 *  Created on: 30/04/2011
 *      Author: Nestor Huallpa
 */

#ifndef __FACTORYMOVIMIENTO_H_
#define __FACTORYMOVIMIENTO_H_
#include "Movimiento.h"
#include "MovidaDirecta.h"
#include "NingunMovimiento.h"
#include "Promocion.h"
#include "EnroqueLargo.h"
#include "EnroqueCorto.h"
#include "Coordenada.h"
#include "FactoryPiezaJugadora.h"
#include "PiezaJugadora.h"
#include "Util.h"
#include <string>

const char c_JAQUE = '+';
const char c_MATE = '#';

class FactoryMovimiento {
public:
	Movimiento* crear(std::string palabra, tColor color);
	bool esMovimientoSimpleCombinable(std::string palabra);
	bool esMovimientoSimple(std::string palabra);
	bool esEnroqueLargo(std::string palabra);
	bool esEnroqueCorto(std::string palabra);
	bool esPromocion(std::string palabra);
	bool esJaque(std::string palabra);
	bool esMate(std::string palabra);
};

#endif /* FACTORYMOVIMIENTO_H_ */
