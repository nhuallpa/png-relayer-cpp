/*
 * PiezaJugadora.h
 *
 *  Created on: 21/04/2011
 *      Author: Nestor Huallpa
 */

#ifndef __PIEZAJUGADORA_H_
#define __PIEZAJUGADORA_H_
#define CANT_PIEZAS 6
#include "Coordenada.h"

typedef enum {NEGRO = 0, BLANCO = 1, SIN_COLOR = 2} tColor;

class TableroAjedrez;
class PiezaJugadora {
	tColor color;
public:
	PiezaJugadora();
	virtual ~PiezaJugadora();
	virtual ListaPCoordenadas* coordDestinoDesde(const Coordenada& coord) = 0;
	bool esAliado(const PiezaJugadora & piezaJugadora) const;
	bool esAliado(const PiezaJugadora* piezaJugadora) const;
    tColor getColor() const;
    void setColor(tColor color);

    virtual ListaPCoordenadas* filtrarCoordValidas(const Coordenada& coorBlanco, TableroAjedrez* unTablero);

protected:
    bool estaHabilitada(Coordenada* coordenada, TableroAjedrez* unTablero);
};

#endif /* PIEZAJUGADORA_H_ */

