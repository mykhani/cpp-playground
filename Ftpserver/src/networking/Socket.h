/*
 * Socket.h
 *
 *  Created on: 14 Apr 2021
 *      Author: ykhan
 */

#ifndef SOCKET_H_
#define SOCKET_H_

class Socket {
protected:
	int fd; // socket descriptor
public:
	virtual void send() = 0;
	virtual void recv() = 0;

};

#endif /* SOCKET_H_ */
