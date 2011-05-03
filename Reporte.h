/*
 * Reporte.h
 *
 *  Created on: 01/05/2011
 *      Author: Nestor Huallpa
 */

#ifndef __REPORTE_H_
#define __REPORTE_H_
#include "Lista.h"
#include "Coordenada.h"

class Reporte {

private:
	int nro;
	ListaPCoordenadas* lCoordBlanco, *lCoordNegro;

public:

	Reporte();
	Reporte(int nroTurno, ListaPCoordenadas* listaCoordBlanco,
						 ListaPCoordenadas* listaCoordNegro);


	ListaPCoordenadas* getCoordenasDestinoBlanco();
	ListaPCoordenadas* getCoordenasDestinoNegro();

	int getNroTurno();

	virtual ~Reporte();
};

typedef Lista<Reporte*> ListaPReportes;

#endif /* REPORTE_H_ */
