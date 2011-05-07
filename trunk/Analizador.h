/*
 * Analizador.h
 *
 *  Created on: 01/05/2011
 *      Author: Nestor Huallpa
 */

#ifndef __ANALIZADOR_H_
#define __ANALIZADOR_H_
#include "Turno.h"
#include "TableroAjedrez.h"
#include "Lista.h"
#include "Coordenada.h"
#include "PiezaJugadora.h"
#include "Reporte.h"

class Analizador {

private:
	listaPReporte* reportes;

public:
	Analizador();

	void analizar(Turno* unTurno, TableroAjedrez* unTablero);

	virtual ~Analizador();
    listaPReporte *getReportes() const;
};

#endif /* ANALIZADOR_H_ */
