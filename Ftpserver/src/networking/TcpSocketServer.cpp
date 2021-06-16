/*
 * TcpSocketServer.cpp
 *
 *  Created on: 17 Apr 2021
 *      Author: ykhan
 */

#include "TcpSocketServer.h"

bool TcpSocketServer::listen(Port port, HostAddress address) {
	emit(newConnection,
			NewConnectionEvent{HostAddress{"127.0.0.1"}, Port{8080}});
//	throw std::runtime_error("Method not implemented!");
}
