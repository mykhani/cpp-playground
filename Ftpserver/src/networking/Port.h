/*
 * Port.h
 *
 *  Created on: 19 Apr 2021
 *      Author: ykhan
 */

#ifndef NETWORKING_PORT_H_
#define NETWORKING_PORT_H_

#include <string>

class Port {
	int portNum;
public:
	Port(int i);
	Port(std::string_view s);

	// provide an int type conversion operator to use with BSD socket API which
	// uses int for port number
	operator int();
	virtual ~Port();
};

#endif /* NETWORKING_PORT_H_ */
