/*
 * main.cpp
 *
 *  Created on: 14 Apr 2021
 *      Author: ykhan
 */
#include <iostream>
#include <string>

#include <memory>

#include <thread>
#include "networking/tcpSocket.h"
#include "networking/connection.h"
#include "networking/hostAddress.h"
#include "networking/port.h"
#include "networking/tcpSocketServer.h"

using namespace std;

/*
 If the callbacks registered with object.addEventListener() are executed by different threads,
 per object. i.e.

 object1.addEventListener(handler1) -> thread1 generating events
 object2.addEventListener(handler2) -> thread2 generating events

 And

 in both handler1 and handler2, we access a global variable g_var
 then we need to have synchronizing primitive inside both handler1 and handler2

 Now let say handler1 executes and acquires the lock in the context of thread1,
 while handler2 executes and tries to acquire the same lock in the context of thread2,
 the thread2 will block.

 Instead we can just have a main event loop thread with events queue and both threads 1 and 2
 post the event as messages to that queue and continue their work. The main loop can then consume
 those events, as per its convenience.

 This achieves sort of a separation of concerns, where events are generated independently
 from their consumption

 Possible API?
 EventLoop.post(Event)
 EventLoop.remove(Event)?

 Event contains a callback

 A generic callback taking event as argument
 object.addEventListener(eventid, callback);

 */
void onNewConnection(EventPtr e) {
	auto& conn_event = dynamic_cast<NewConnectionEvent&>(*e);
	std::cout << "Thread id: " << this_thread::get_id() << " new Connection event received" << std::endl;

	std::cout  << conn_event.connection;
	TcpSocket& sock = conn_event.connection->getTcpSocket();

	sock.asyncRecv([conn_event](Socket& sk, const string& msg) {
		cout << "Received message on socket: " << sk.handle() << endl
			 <<	msg << endl;

		string resp{R"MSG(
HTTP/1.1 200 OK

<!DOCTYPE html>
<html>
	<head>
	</head>
	<body>
		Hello from the webserver
	</body>
</html>
)MSG"};
		cout << "Sending response " << resp << endl;

		write(sk, resp.c_str(), resp.length());
		TcpSocketServer* server = conn_event.server;
		server->closeConnection(conn_event.connection->getTcpSocket());
	});
}

int main(int argc, char* argv[]) {

	using namespace std::string_view_literals;

	Port p1{8080};
	Port p2{"1080"};

	TcpSocketServer server{};

	server.addEventListener(TcpServerEvents::newConnection, onNewConnection);

	cout << "Main thread id: " << this_thread::get_id() << endl;
//	server.listen(Port{5555}, HostAddress{"localhost"}); // start listening in new background thread
	server.listen(Port{9999}); // start listening in new background thread

	getchar();

	//EventLoop loop;

	//loop.exec();

}

