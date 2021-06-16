/*
 * Port.cpp
 *
 *  Created on: 19 Apr 2021
 *      Author: ykhan
 */

#include "Port.h"

Port::Port(int i) :
		portNum{i} {
}

Port::Port(std::string_view s) {
	// TODO: verify the port string consists of only numbers
	portNum = atoi(s.data());
}

Port::operator int() {
	return portNum;
}

Port::~Port() {
	// TODO Auto-generated destructor stub
}

