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


class Celda {

private:
	Pieza* pieza;

public:
	Celda();
	virtual ~Celda();
    Pieza *getPieza() const;
    void setPieza(Pieza *pieza);
};

#endif /* CELDA_H_ */
