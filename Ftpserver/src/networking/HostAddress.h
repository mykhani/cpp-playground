/*
 * HostAddress.h
 *
 *  Created on: 17 Apr 2021
 *      Author: ykhan
 */

#ifndef NETWORKING_HOSTADDRESS_H_
#define NETWORKING_HOSTADDRESS_H_

#include <string>

class HostAddress {
private:
	std::string address;

public:
	HostAddress(std::string_view _address) :
			address{_address} {
	}
};

#endif /* NETWORKING_HOSTADDRESS_H_ */
