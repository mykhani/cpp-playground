/*
 * Socket.cpp
 *
 *  Created on: 14 Apr 2021
 *      Author: ykhan
 */

#include "Socket.h"

Socket::Socket(int domain, int type, int protocol) {
	fd = socket(domain, type, protocol);
	if (fd < 0)
		throw std::runtime_error{"Failed to create the TcpSocket"};
}

bool Socket::bind(Port port, optional<HostAddress> address) {
	int ret;

	// if address not specified, use the ip address of the system
	if (address) {
		;
//		getaddrinfo(NULL, "3490", &hints, &res)
	}
//	ret = bind(fd, struct sockaddr *my_addr, int addrlen);
}
