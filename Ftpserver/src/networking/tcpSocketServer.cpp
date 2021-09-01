/*
 * TcpSocketServer.cpp
 *
 *  Created on: 17 Apr 2021
 *      Author: ykhan
 */

#include "tcpSocketServer.h"
#include <iostream>
#include <sstream>
#include <thread>
#include <cstring>

using namespace std;

void tcpServerBackgroundTask(TcpSocketServer& server) {
	int ret;
	ret = listen(server.sock, server.queued_connections);
	if (ret) {
		cout << "tcp server failed to start listening" << endl;
	}

	cout << "Started thread " << this_thread::get_id()
			<< " listening on " << server.address
			<< " port " << server.port << endl;


	auto event = pollfd{server.sock.handle(), POLLIN};
	server.poll_events.emplace_back(event);

	while (true) {
		auto poll_count = poll(server.poll_events.data(), server.poll_events.size(), POLLING_TIMEOUT);

		cout << "poll count: " << poll_count << endl;

		for (int i = 0; poll_count > 0 && i < server.poll_events.size(); i++) {
			// check if data is available to read
			if (server.poll_events[i].revents & POLLIN) {
				if (server.poll_events[i].fd == server.sock) {
					// accept new incoming connection
					sockaddr client_info;
					socklen_t client_info_size = sizeof(client_info);

					int conn_handle = accept(server.sock, &client_info, &client_info_size);

					TcpSocket client_sock{conn_handle};
					HostAddress client_addr = HostAddress::fromSockAddr(&client_info);

					server.addConnection(client_sock, client_addr);
				} else {
					// received some data
					char buf[4028];
					int bytes_received = 0;

					bytes_received = read(server.poll_events[i].fd, (void*)buf, sizeof(buf));
					if (bytes_received > 0) {
						string data{buf};
						int desc = server.poll_events[i].fd;
						ConnectionPtr conn;
						// map i to client socket
						if (server.connections.find(desc) != server.connections.end()) {
							conn = server.connections[desc];
							conn->getTcpSocket().dataReady(data);
						}
					}
				}
			}
		}
	}
}

TcpSocketServer::TcpSocketServer(int _queued_connections)
		: queued_connections{_queued_connections} {
}

void TcpSocketServer::listen(Port port, std::optional<HostAddress> address) {
	HostAddress bind_address;

	// mark server socket as reusable
	sock.makeReusable();

	try {
		bind_address = sock.bind(port, address);
	} catch (std::exception& e) {
		cout << "Failed to bind the socket, error: " << strerror(errno);
		ostringstream oss;

		oss << "Failed to listen on ";
		if (address)
			oss << "address : " << address.value();

		oss << " port: " << port
			<< " error: " << e.what() << endl;

		throw std::runtime_error{oss.str()};
	}

	this->address = bind_address;
	this->port = port;

	std::thread background_task{tcpServerBackgroundTask, std::ref(*this)};

	background_task.detach();

//	throw std::runtime_error("Method not implemented!");
}

void TcpSocketServer::addConnection(TcpSocket& client_sock, HostAddress& client_addr) {

	auto event = pollfd{static_cast<int>(client_sock.handle()), POLLIN};
	poll_events.push_back(event);

	ConnectionPtr conn{new Connection{client_addr, std::move(client_sock)}};

	this->connections.insert({conn->getTcpSocket().handle(), conn});

	auto newConnectionEvent = make_shared<NewConnectionEvent>(conn, this);

	emit(newConnectionEvent);

}

void TcpSocketServer::closeConnection(TcpSocket& client_sock) {
	auto handle = client_sock.handle();

	auto match = [handle](pollfd& poll) {
		return poll.fd == handle;
	};

	// remove polling descriptor
	poll_events.erase(std::remove_if(poll_events.begin(), poll_events.end(), match), poll_events.end());
	// remove the connection
	this->connections.erase(handle);

	// close the socket descriptor
	close(handle);
}
