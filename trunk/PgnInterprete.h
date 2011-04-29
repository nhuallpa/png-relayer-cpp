/*
 * PgnInterprete.h
 *
 *  Created on: 21/04/2011
 *      Author: Nestor Huallpa
 *
 *
 * Interpretar el PGN de ajedrez y crea una lista de piezas iniciales donde
 * cada una tiene su symbolo de pieza y la referencia a la pieza en juego
 *
 * p : Peon negro		P : blanco
 * r : Torre negro		R : blanco
 * n : Caballo negro	N : blanco
 * b : Alfil negro		B : blanco
 * q : Reina negro		Q : blanco
 * k : Rey negro		K : blanco
 */

#ifndef __PGNINTERPRETE_H_
#define __PGNINTERPRETE_H_
#include "Lista.h"
#include "PgnAjedrez.h"
#include <string>
#include "Pieza.h"
#include "FactoryPiezaJugadora.h"
#include "Turno.h"

typedef Lista<Pieza*> ListaPPieza;
typedef Lista<Turno*> ListaPTurno;

class PgnInterprete {
private:
	PgnAjedrez* pgn;
	FactoryPiezaJugadora factoryPiezaJugadora;
	ListaPPieza* piezasIniciales;
	ListaPTurno* turnos;

public:
	PgnInterprete();
	virtual ~PgnInterprete();
    PgnAjedrez *getPgn() const;
    void setPgn(PgnAjedrez *pgn);

    /**
     * Pre: Se debe tener cargado el PGN y ejecutar interpretar
     *
     */
    ListaPPieza* getPiezasIniciales();

    /*
     * Ejecuta los interpretes
     * */
    void interpretar();

private:

    /*
	* Interpreta el pgn de Ajedrez y carga la lista
	* de piezas iniciales
	* */
    void interpretarTableroInicial();

    void interpretarTurnos();

    void interpretarFila(std::string filaString, int fila);
};

#endif /* PGNINTERPRETE_H_ */
