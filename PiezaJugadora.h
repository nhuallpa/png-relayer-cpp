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

const int pasoFil[8] = {1, 1, 0, -1, -1, -1, 	0, 	1};
const int pasoCol[8] = {0, 1, 1, 	1, 	0, -1, -1, -1};
typedef enum { NORTE, NORESTE, ESTE, SURESTE, SUR, SUROESTE, OESTE, NOROESTE}
		tDireccionPaso;


class TableroAjedrez;
class PiezaJugadora {
	tColor color;
public:
	PiezaJugadora();
	virtual ~PiezaJugadora();
	bool esAliado(const PiezaJugadora & piezaJugadora) const;
	bool esAliado(const PiezaJugadora* piezaJugadora) const;
    tColor getColor() const;
    void setColor(tColor color);

    virtual ListaPCoordenadas* filtrarCoordValidas(
    										const Coordenada& coorBlanco,
    										TableroAjedrez* unTablero);

protected:
    bool estaHabilitada(Coordenada* coordenada, TableroAjedrez* unTablero);
    ListaPCoordenadas *cargarCoordValidas(ListaPCoordenadas * listaCoord,
    					 				  const Coordenada & coorBlanco,
    									  TableroAjedrez *unTablero,
    									  tDireccionPaso Dir);
};

#endif /* PIEZAJUGADORA_H_ */

