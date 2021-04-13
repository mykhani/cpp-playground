/*
 * debug.h
 *
 *  Created on: 13 Apr 2021
 *      Author: ykhan
 */

#ifndef DEBUG_H_
#define DEBUG_H_

#include <iostream>
#include <mutex>

using namespace std;

static std::mutex m;

template <typename ... Args>
void debug(Args ... args) {
	// binary left folding expression
	// (init op ... op pack)
	std::lock_guard<std::mutex> lg{m};
	(cout << ... << args);
	cout << endl;
}

#endif /* DEBUG_H_ */
