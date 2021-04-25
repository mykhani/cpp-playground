/*
 * TcpSocket.h
 *
 *  Created on: 14 Apr 2021
 *      Author: ykhan
 */

#ifndef TCPSOCKET_H_
#define TCPSOCKET_H_

#include <stdexcept>
#include "Socket.h"
#include <sys/socket.h>

class TcpSocket : public Socket {
public:
	TcpSocket() {
		fd = socket(AF_INET, SOCK_STREAM, 0);
		if (fd < 0) {
			throw std::runtime_error{"Failed to create the TcpSocket"};
		}
	}
};

#endif /* TCPSOCKET_H_ */
