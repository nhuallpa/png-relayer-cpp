/*
 * Assert.h
 *
 *  Created on: 16/04/2011
 *      Author: administrador
 */

#ifndef ASSERT_H_
#define ASSERT_H_
#include <iostream>
#include <string>


class Assert {
public:
	Assert();
	static void assertTrue(bool value, std::string descr);
	static void assertFalse(bool value, std::string descr);
	virtual ~Assert();
};

#endif /* ASSERT_H_ */
