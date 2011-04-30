/*
 * ControladorReplayer.h
 *
 *  Created on: 15/04/2011
 *      Author: Nestor Huallp
 */

#ifndef _CONTROLADORREPLAYER_H_
#define _CONTROLADORREPLAYER_H_
#include "TableroAjedrez.h"
#include "PgnAjedrez.h"
#include "PgnInterprete.h"
#include <string>
#include "Lista.h"
#include "PiezaJugadora.h"
#include "Coordenada.h"
#include "VistaReplayer.h"
#include "Movimiento.h"
#include "Turno.h"

class ControladorReplayer {

private:
	TableroAjedrez* tableroAjedrez;
	VistaReplayer* vista;
	PgnInterprete pgnInterprete;

public:
	ControladorReplayer(TableroAjedrez* ajedrez, VistaReplayer* unaVista);
	void reproducir(PgnAjedrez* entradaPng);
	virtual ~ControladorReplayer();
	void mostrarResultados();
	void ejecutarTurnos();


private:
	void prepararTableroInicial();
	void colocarPiezasIniciales(ListaPPieza* piezasIniciales);

};

#endif /* CONTROLADORREPLAYER_H_ */
