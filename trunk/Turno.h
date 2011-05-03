/*
 * Turnos.h
 *
 *  Created on: 29/04/2011
 *      Author: Nestor Huallpa
 */

#ifndef __TURNO_H_
#define __TURNO_H_
#include "Movimiento.h"

class Turno {
	bool hay_QueAnalizar;
	int nroTurno;

	Coordenada coordOrigenBlanco;
	Coordenada coordOrigenNegro;

	Movimiento* movimientoBlanco;
	Movimiento* movimientoNegro;

public:
	Turno();
	virtual ~Turno();
    Movimiento *getMovimientoBlanco() const;
    Movimiento *getMovimientoNegro() const;
    void setMovimientoBlanco(Movimiento *movimientoBlanco);
    void setMovimientoNegro(Movimiento *movimientoNegro);
    void requirirAnalisis();
    bool requiereAnalisis();
    bool getHay_QueAnalizar() const;
    int getNroTurno() const;
    void setHay_QueAnalizar(bool hay_QueAnalizar);
    void setNroTurno(int nroTurno);

    // para poder realizar los analisis
    Coordenada getCoordOrigenBlanco() const;
    Coordenada getCoordOrigenNegro() const;
    void setCoordOrigenBlanco(Coordenada& coordOrigenBlanco);
    void setCoordOrigenNegro(Coordenada& coordOrigenNegro);
};

#endif /* TURNOS_H_ */
