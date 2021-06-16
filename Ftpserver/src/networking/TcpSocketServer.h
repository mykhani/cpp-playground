/*
 * TcpSocketServer.h
 *
 *  Created on: 17 Apr 2021
 *      Author: ykhan
 */

#ifndef NETWORKING_TCPSOCKETSERVER_H_
#define NETWORKING_TCPSOCKETSERVER_H_

#include <string_view>
#include "TcpSocket.h"
#include "Port.h"
#include "HostAddress.h"
#include "../util/EventEmitter.h"

enum ServerEvent {
	newConnection,
};

class NewConnectionEvent: public Event {
private:
	HostAddress ipaddr;
	Port port;

public:
	NewConnectionEvent(const HostAddress& _ipaddr, const Port& _port) :
			Event{newConnection}, ipaddr{_ipaddr}, port{_port} {
	}
};

//struct NewConnectionHandler: public EventCallback {
//
//	NewConnectionHandler() = default;
//
//	virtual void operator(const Event& e)() override {
//
//	}
//};

class TcpSocketServer: public EventEmitter {
public:
	TcpSocketServer() {
//		NewConnection newConn;
	}

	bool listen(Port port, HostAddress address);
};

#endif /* NETWORKING_TCPSOCKETSERVER_H_ */
