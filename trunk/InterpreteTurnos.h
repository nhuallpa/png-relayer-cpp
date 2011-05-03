/*
 * InterpreteTurnos.h
 *
 *  Created on: 01/05/2011
 *      Author: Nestor Huallpa
 */

#ifndef __INTERPRETETURNOS_H_
#define __INTERPRETETURNOS_H_
#include "Lista.h"
#include "PgnAjedrez.h"
#include <string>
#include "Pieza.h"
#include "FactoryPiezaJugadora.h"
#include "Turno.h"
#include "PiezaJugadora.h"
#include "FactoryMovimiento.h"

typedef Lista<Pieza*> ListaPPieza;
typedef Lista<Turno*> ListaPTurno;
const char JUGADOR_NEGRO = 'b';
const char c_ANALIZAR = '?';

class InterpreteTurnos {

private:
	PgnAjedrez* pgn;
	FactoryPiezaJugadora factoryPiezaJugadora;
	FactoryMovimiento	factoryMovimiento;
	ListaPPieza* piezasPromocion;
	ListaPTurno* turnos;

public:
	InterpreteTurnos();
	virtual ~InterpreteTurnos();

	ListaPPieza* getPiezasPromocion();

	ListaPTurno* getTurnos();

	void setPgn(PgnAjedrez *pgn);

	void interpretarTurnos();

private:

	// caso particular, debido a que un movimiento es causante de un
	// una nueva pieza. Esta debe registrarse para ser usada en el MVC
	void registrarPromocionDe(Movimiento* movimientoBlanco,
							  std::string palabra);

	Turno* crearTurno(std::string nroTurno, std::string movidaNegro);

	Turno* crearTurno(std::string nroTurno, std::string movidaBlanco,
										  std::string movidaNegro);

	Turno* crearTurno(std::string& nroTurno, Movimiento* movidaBlanco,
										   Movimiento* movidaNegro);
	int obtenerNumeroTurno(std::string& nroTurno);

	void preparaParaAnalizar(Turno* unTurno, std::string& movNegro,
											 std::string& movBlanco);

	Coordenada obtenerCoordenadaInicial(std::string& movida);

	bool requiereAnalisis(std::string& nroTurno);

	bool empiezaNegra();
};

#endif /* INTERPRETETURNOS_H_ */
