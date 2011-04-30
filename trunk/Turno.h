/*
 * Turnos.h
 *
 *  Created on: 29/04/2011
 *      Author: Nestor Huallpa
 */

#ifndef __TURNO_H_
#define __TURNO_H_
#include "Movimiento.h"

class Turno {

	Movimiento* movimientoBlanco;
	Movimiento* movimientoNegro;

public:
	Turno();
	virtual ~Turno();
    Movimiento *getMovimientoBlanco() const;
    Movimiento *getMovimientoNegro() const;
    void setMovimientoBlanco(Movimiento *movimientoBlanco);
    void setMovimientoNegro(Movimiento *movimientoNegro);
};

#endif /* TURNOS_H_ */
