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
#include "PiezaJugadora.h"
#include "FactoryMovimiento.h"
#include "InterpreteTurnos.h"

typedef Lista<Pieza*> ListaPPieza;
typedef Lista<Turno*> ListaPTurno;
//const char JUGADOR_NEGRO = 'b';
//const char c_ANALIZAR = '?';


class PgnInterprete {
private:
	PgnAjedrez* pgn;
	FactoryPiezaJugadora factoryPiezaJugadora;
//	FactoryMovimiento	factoryMovimiento;
	ListaPPieza* piezasIniciales;
//	ListaPPieza* piezasPromocion;
//	ListaPTurno* turnos;


	InterpreteTurnos interpreteTurno;

public:
	PgnInterprete();
	virtual ~PgnInterprete();
    void setPgn(PgnAjedrez *pgn);

    /**
     * Pre: Se debe tener cargado el PGN y ejecutar interpretar
     *
     */
    ListaPPieza* getPiezasIniciales();

    ListaPPieza* getPiezasPromocion();

    ListaPTurno* getTurnos();

    /*
     * Ejecuta los interpretes
     * */
    void interpretar();

    /*
     * */
    // bool empiezaNegra();

private:

    /*
	* Interpreta el pgn de Ajedrez y carga la lista
	* de piezas iniciales
	* */
    void interpretarTableroInicial();



    void interpretarFila(std::string filaString, int fila);

    void registrarPiezas(PiezaJugadora* piezaJugadora,
    					 const Coordenada& coord, char simbolo);

//    void interpretarTurnos();
//
//    // caso particular, debido a que un movimiento es causante de un
//    // una nueva pieza. Esta debe registrarse para ser usada en el MVC
//    void registrarPromocionDe(Movimiento* movimientoBlanco,
//    						  std::string palabra);
//
//    void crearTurno(std::string nroTurno, std::string movidaNegro);
//
//    void crearTurno(std::string nroTurno, std::string movidaBlanco,
//    									  std::string movidaNegro);
//
//    void crearTurno(std::string& nroTurno, Movimiento* movidaBlanco,
//    									   Movimiento* movidaNegro);
//    int obtenerNumeroTurno(std::string& nroTurno);
};

#endif /* PGNINTERPRETE_H_ */
