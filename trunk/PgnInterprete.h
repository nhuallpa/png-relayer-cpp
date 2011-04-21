/*
 * PgnInterprete.h
 *
 *  Created on: 21/04/2011
 *      Author: Nestor Huallpa
 */

#ifndef __PGNINTERPRETE_H_
#define __PGNINTERPRETE_H_
#include "Lista.h"
#include "PgnAjedrez.h"
#include "Pieza.h"
typedef Lista<Pieza*> ListaPPieza;

class PgnInterprete {
private:
	PgnAjedrez* pgn;
public:
	PgnInterprete();
	virtual ~PgnInterprete();
    PgnAjedrez *getPgn() const;
    void setPgn(PgnAjedrez *pgn);
    /**
     * El que use este metodo, tendra que liberar
     * el recurso usado para la lista incluyendo
     * la memoria de las piezas
     * */
    ListaPPieza* getPiezasIniciales();

};

#endif /* PGNINTERPRETE_H_ */
