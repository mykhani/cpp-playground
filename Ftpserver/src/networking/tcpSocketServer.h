/*
 * TcpSocketServer.h
 *
 *  Created on: 17 Apr 2021
 *      Author: ykhan
 */

#ifndef NETWORKING_TCPSOCKETSERVER_H_
#define NETWORKING_TCPSOCKETSERVER_H_

#include <optional>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include "../util/eventEmitter.h"
#include "hostAddress.h"
#include "port.h"
#include <poll.h>
#include "tcpSocket.h"
#include "connection.h"

// Polling timeout in ms
#define POLLING_TIMEOUT 1000

enum TcpServerEvents {
	newConnection,
};

class TcpSocketServer: public EventEmitter {
private:
	TcpSocket sock;
	HostAddress address;
	Port port;
	int queued_connections;
	std::unordered_map<int, ConnectionPtr> connections;
	std::vector<pollfd> poll_events;
	friend void tcpServerBackgroundTask(TcpSocketServer& server);

public:
	TcpSocketServer(int _queued_connections = 5);
	void listen(Port port, std::optional<HostAddress> address = std::nullopt);
	void addConnection(TcpSocket& sock, HostAddress& addr);
	void closeConnection(TcpSocket& sock);
};

class NewConnectionEvent: public Event {
public:
	ConnectionPtr connection;
	TcpSocketServer* server;

	NewConnectionEvent(ConnectionPtr _conn, TcpSocketServer *_server) :
			Event{newConnection}, connection{_conn}, server{_server} {
	}
};

#endif /* NETWORKING_TCPSOCKETSERVER_H_ */
