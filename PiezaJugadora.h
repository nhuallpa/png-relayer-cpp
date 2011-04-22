/*
 * PiezaJugadora.h
 *
 *  Created on: 21/04/2011
 *      Author: administrador
 */

#ifndef __PIEZAJUGADORA_H_
#define __PIEZAJUGADORA_H_

typedef enum {NEGRO = 0, BLANCO = 1, SIN_COLOR = 2} tColor;


class PiezaJugadora {
	tColor color;
public:
	PiezaJugadora();
	virtual ~PiezaJugadora();
    tColor getColor() const;
    void setColor(tColor color);
};

#endif /* PIEZAJUGADORA_H_ */
