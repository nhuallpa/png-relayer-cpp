/*
 * Promocion.h
 *
 *  Created on: 30/04/2011
 *      Author: Nestor Huallpa
 */

#ifndef __PROMOCION_H_
#define __PROMOCION_H_

#include "Movimiento.h"

class Promocion: public Movimiento {
private:
	char simboloPromocion;
	PiezaJugadora* piezaPromocion;
	Coordenada origen;
	Coordenada destino;

public:
	Promocion(const Coordenada& ori, const Coordenada& dest, char simbolo);
	void aplicarEn(TableroAjedrez* tablero);
	void setPiezaPromocion(PiezaJugadora* piezaJugadora);
	char getSimboloPromocion();
	Coordenada& getDestino();
};

#endif /* PROMOCION_H_ */
