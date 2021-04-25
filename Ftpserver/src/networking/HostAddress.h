/*
 * HostAddress.h
 *
 *  Created on: 17 Apr 2021
 *      Author: ykhan
 */

#ifndef HOSTADDRESS_H_
#define HOSTADDRESS_H_

#include <string>

class HostAddress {
private:
	std::string_view address;

public:
	HostAddress(const std::string_view& _address) : address{_address} {
	}
};


#endif /* HOSTADDRESS_H_ */
