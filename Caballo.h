/*
 * Caballo.h
 *
 *  Created on: 21/04/2011
 *      Author: Nestor Huallpa
 */

#ifndef __CABALLO_H_
#define __CABALLO_H_

#include "PiezaJugadora.h"

class Caballo: public PiezaJugadora {
public:

	ListaPCoordenadas* filtrarCoordValidas(const Coordenada& coorBlanco,
												TableroAjedrez* unTablero);

private:
	ListaPCoordenadas* validarCoordenadasDestino(const Coordenada& coordOrigen,
							  	  	  	  	  	  TableroAjedrez* unTablero);
};

#endif /* CABALLO_H_ */
