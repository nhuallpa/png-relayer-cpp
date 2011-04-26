/*
 * Assert.h
 *
 *  Created on: 16/04/2011
 *      Author: administrador
 */

#ifndef __ASSERT_H_
#define __ASSERT_H_
#include <iostream>
#include <string>


class Assert {
public:
	Assert();
	static void assertTrue(bool value, std::string descr);
	static void assertFalse(bool value, std::string descr);
	static void assertEquals(int expected, int result, std::string descr);
	static void assertEquals(char expected, char result, std::string descr);
	virtual ~Assert();
};

#endif /* ASSERT_H_ */
