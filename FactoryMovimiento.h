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

class FactoryMovimiento {
public:
	Movimiento* crear(std::string palabra, tColor color);
};

#endif /* FACTORYMOVIMIENTO_H_ */
