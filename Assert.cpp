/*
 * Assert.cpp
 *
 *  Created on: 16/04/2011
 *      Author: administrador
 */

#include "Assert.h"
using namespace std;

Assert::Assert() {
	// TODO Auto-generated constructor stub

}

void Assert::assertTrue(bool value, string descr) {
	if (value == false) {
		cout<<"se esperaba TRUE, se recibio FALSE en '"<<descr<<"'"<<endl;
	}

}

void Assert::assertFalse(bool value, string descr)
{
	if (value == true) {
		cout<<"se esperaba FALSE, se recibio TRUE en '"<<descr<<"'"<<endl;
	}
}

Assert::~Assert() {
}
