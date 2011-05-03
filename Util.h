/*
 * Util.h
 *
 *  Created on: 30/04/2011
 *      Author: administrador
 */

#ifndef __UTIL_H_
#define __UTIL_H_
#include <string>
#include <sstream>

class Util {
public:
	static int charToInt(char c);
	static bool esMayucula(char c);
	static int stringToInt(std::string nro);
};

#endif /* UTIL_H_ */
