/*
 * Socket.h
 *
 *  Created on: 14 Apr 2021
 *      Author: ykhan
 */

#ifndef NETWORKING_SOCKET_H_
#define NETWORKING_SOCKET_H_

#include <sys/socket.h>
#include <experimental/optional>
#include <stdexcept>
#include "HostAddress.h"
#include "Port.h"

using std::experimental::optional;
using std::experimental::nullopt;

class Socket {
private:
	int fd; // socket descriptor
public:
	Socket(int domain, int type, int protocol);
	bool bind(Port port, optional<HostAddress> address = nullopt);

	virtual void send() = 0;
	virtual void recv() = 0;
};

#endif /* NETWORKING_SOCKET_H_ */
