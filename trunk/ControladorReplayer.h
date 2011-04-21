/*
 * ControladorReplayer.h
 *
 *  Created on: 15/04/2011
 *      Author: administrador
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



class ControladorReplayer {

private:
	TableroAjedrez* tableroAjedrez;
	PgnInterprete pgnInterprete;
	ListaPPieza* piezasIniciales;

public:
	ControladorReplayer(TableroAjedrez* ajedrez);
	void reproducir(PgnAjedrez* entradaPng);
	virtual ~ControladorReplayer();
	void mostrarResultados();


private:
	void prepararTableroInicial(PgnAjedrez* entradaPng);

};

#endif /* CONTROLADORREPLAYER_H_ */
