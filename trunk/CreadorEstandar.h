/*
 * CreadorEstandar.h
 *
 *  Created on: 21/04/2011
 *      Author: Nestor Huallpa
 */

#ifndef __CREADORESTANDAR_H_
#define __CREADORESTANDAR_H_
#include "Creador.h"

template <class P>
class CreadorEstandar : public Creador {
public:
	PiezaJugadora* getInstancia();
};

template<class P> inline
PiezaJugadora *CreadorEstandar<P>::getInstancia() {
	return new P;
}

#endif /* CREADORESTANDAR_H_ */
