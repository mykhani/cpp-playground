/*
 * EventEmitter.cpp
 *
 *  Created on: 16 Jun 2021
 *      Author: ykhan
 */
#include "EventEmitter.h"

void EventEmitter::addEventListener(const int& eventId,
		std::shared_ptr<EventCallback> handler) {
	eventHandlers[eventId].push_back(handler);
}

void EventEmitter::emit(const int& eventId, const Event& event) {
	const auto &handlers = eventHandlers[eventId];
	for (const auto &handler : handlers) {
		(*handler)(event);
	}
}

