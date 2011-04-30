/*
 * MovidaDirecta.h
 *
 *  Created on: 30/04/2011
 *      Author: Nestor Huallpa
 */

#ifndef __MOVIDADIRECTA_H_
#define __MOVIDADIRECTA_H_

#include "Movimiento.h"

class MovidaDirecta: public Movimiento {
private:
	Coordenada origen;
	Coordenada destino;

public:
	MovidaDirecta(int filaOrigen, char columnaOrigen,
				  int filaDestino, char columnaDestino);

	void aplicarEn(TableroAjedrez* tablero);

	virtual ~MovidaDirecta();
};

#endif /* MOVIDADIRECTA_H_ */
