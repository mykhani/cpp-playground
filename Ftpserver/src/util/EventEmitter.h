/*
 * EventEmitter.h
 *
 *  Created on: 20 Apr 2021
 *      Author: ykhan
 */

#ifndef UTIL_EVENTEMITTER_H_
#define UTIL_EVENTEMITTER_H_

#include <functional>
#include <vector>
#include <memory>
#include <map>
#include <unordered_map>

#include <iostream>
using namespace std;

class Event {
private:
	int id;
public:
	Event(int _id) :
			id{id} {
	}
	virtual ~Event() = default;

	bool operator<(const Event& other) const {
		return id < other.id;
	}
};

class EventCallback {
public:
	virtual void operator()(const Event& event) = 0;
};

class EventEmitter {
private:
	std::map<int, std::vector<std::shared_ptr<EventCallback>>> eventHandlers;

public:
	void addEventListener(const int& eventId,
			std::shared_ptr<EventCallback> handler);

	void emit(const int& eventId, const Event& e);
};

#endif /* UTIL_EVENTEMITTER_H_ */
