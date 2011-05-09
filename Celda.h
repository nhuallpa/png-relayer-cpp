/*
 * Celda.h
 *
 *  Created on: 16/04/2011
 *      Author: administrador
 */

#ifndef ___CELDA_H_
#define ___CELDA_H_
#include "commonType.h"
#include "Pieza.h"
#include "PiezaJugadora.h"


class Celda {
private:
	PiezaJugadora*  piezaJugadora;
public:
	Celda();
	virtual ~Celda();
    PiezaJugadora *getPiezaJugadora() const;
    void setPiezaJugadora(PiezaJugadora *piezaJugadora);
};

#endif /* CELDA_H_ */
