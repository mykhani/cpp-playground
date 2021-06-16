/*
 * TcpSocket.h
 *
 *  Created on: 14 Apr 2021
 *      Author: ykhan
 */

#ifndef NETWORKING_TCPSOCKET_H_
#define NETWORKING_TCPSOCKET_H_

#include <stdexcept>

#include "Socket.h"

class TcpSocket: public Socket {
public:
	TcpSocket() :
			Socket{PF_INET, SOCK_STREAM, 0} {

	}
};

#endif /* NETWORKING_TCPSOCKET_H_ */
