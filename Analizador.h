/*
 * Analizador.h
 *
 *  Created on: 01/05/2011
 *      Author: Nestor Huallpa
 */

#ifndef __ANALIZADOR_H_
#define __ANALIZADOR_H_
#include "Reporte.h"
#include "Turno.h"
#include "TableroAjedrez.h"
#include "Lista.h"
#include "Coordenada.h"
#include "PiezaJugadora.h"

class Analizador {

private:
	Lista<Reporte*>* reportes;

public:
	Analizador();

	void analizar(Turno* unTurno, TableroAjedrez* unTablero);


//	ListaPCoordenadas* filtrarCoordValidas(Coordenada& coordenada,
//										   PiezaJugadora* piezaJugadora,
//										   TableroAjedrez* unTablero);
//
//	ListaPCoordenadas* validarCoordenadasDestino(ListaPCoordenadas* coordenasDestino,
//											 	 PiezaJugadora* piezaJugadora,
//											 	 TableroAjedrez* unTablero);
	ListaPReportes*  getReportes();

	virtual ~Analizador();
};

#endif /* ANALIZADOR_H_ */
