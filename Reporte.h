/*
 * Reporte.h
 *
 *  Created on: 07/05/2011
 *      Author: Nestor Huallpa
 */

#ifndef __REPORTE_H_
#define __REPORTE_H_
#include "Coordenada.h"

class Reporte {
	int nroTurno;
	ListaPCoordenadas* listCoordenadasBlancas;
	ListaPCoordenadas* listCoordenadasNegras;

public:
	Reporte(int nro, ListaPCoordenadas* listCoordBlancas,
					 ListaPCoordenadas* listCoordNegras);

	virtual ~Reporte();
    ListaPCoordenadas *getListCoordenadasBlancas() const;
    ListaPCoordenadas *getListCoordenadasNegras() const;
    int getNroTurno() const;
    void setListCoordenadasBlancas(ListaPCoordenadas *listCoordenadasBlancas);
    void setListCoordenadasNegras(ListaPCoordenadas *listCoordenadasNegras);
    void setNroTurno(int nroTurno);
};

typedef Lista<Reporte*> listaPReporte;

#endif /* REPORTE_H_ */
