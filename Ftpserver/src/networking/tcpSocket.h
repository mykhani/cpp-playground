/*
 * TcpSocket.h
 *
 *  Created on: 14 Apr 2021
 *      Author: ykhan
 */

#ifndef NETWORKING_TCPSOCKET_H_
#define NETWORKING_TCPSOCKET_H_

#include <stdexcept>

#include "socket.h"

class TcpSocket: public Socket {
public:
	TcpSocket();
	TcpSocket(int fd);
	TcpSocket(TcpSocket& other) = delete;
	TcpSocket(TcpSocket&& other);
	~TcpSocket();
};

#endif /* NETWORKING_TCPSOCKET_H_ */
