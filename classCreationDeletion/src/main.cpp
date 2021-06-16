/*
 * main.cpp
 *
 *  Created on: 31 Mar 2021
 *      Author: ykhan
 */

//============================================================================
// Name        : classCreationDeletion.cpp
// Author      : Yasir Khan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class A {
public:
	A() {
		cout << "Constructor A" << endl;
	}
	~A() {
		cout << "Destructor A" << endl;
	}
};

class B : public A {
public:
	B() {
		cout << "Constructor B" << endl;
	}
	~B() {
		cout << "Destructor B" << endl;
	}
};

class C : public B {
public:
	C() {
		cout << "Constructor C" << endl;
	}
	~C() {
		cout << "Destructor C" << endl;
	}
};

int main() {

	C c;

	/*	Output
	 	Constructor A
		Constructor B
		Constructor C
		Destructor C
		Destructor B
		Destructor A
	 */
	return 0;
}
