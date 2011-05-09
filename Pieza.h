/*
 * Pieza.h
 *
 *  Created on: 16/04/2011
 *      Author: administrador
 */

#ifndef PIEZA_H_
#define PIEZA_H_
#include "PiezaJugadora.h"
#include "Coordenada.h"
#include "commonType.h"

class Pieza {
private:
	PiezaJugadora* piezaJugadora;
	Coordenada coordenadaInicial;
	char symbol;

public:
	Pieza(PiezaJugadora* pJugadora, const Coordenada& coord, char unSimbolo);
	virtual ~Pieza();
    Coordenada getCoordenadaInicial() const;
    PiezaJugadora *getPiezaJugadora() const;
    void setCoordenadaInicial(Coordenada coordenadaInicial);
    void setPiezaJugadora(PiezaJugadora *piezaJugadora);
    char getSymbol() const;
    void setSymbol(char symbol);
};

#endif /* PIEZA_H_ */
