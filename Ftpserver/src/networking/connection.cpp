/*
 * Connection.cpp
 *
 *  Created on: 20 Apr 2021
 *      Author: ykhan
 */

#include "connection.h"

Connection::Connection(const HostAddress& _client_addr, TcpSocket&& _sock)
		: client_addr{_client_addr}, sock{std::move(_sock)} {
}

TcpSocket& Connection::getTcpSocket() {
	return sock;
}
