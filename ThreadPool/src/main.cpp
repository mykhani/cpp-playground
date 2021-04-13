/*
 * main.cpp
 *
 *  Created on: 12 Apr 2021
 *      Author: ykhan
 */

#include "ThreadPool.h"

#include <cmath>
#include <iostream>

using namespace std;

#define TEST_SIZE 100

int Sum(int a, int b) {
	return a + b;
}

int main() {
	using namespace std::chrono_literals;

	{
		ThreadPool pool;

		vector<int> args1(TEST_SIZE, 0);
		vector<int> args2(TEST_SIZE, 0);
		vector<std::future<int>> sums;
		vector<std::future<int>> products;

		for (int i = 0; i < TEST_SIZE; i++) {
			args1[i] = i + 1;
			args2[i] = i + 1;
			sums.push_back(pool.submit(Sum, args1[i], args2[i]));
			products.push_back(pool.submit([](int x, int y) {
				return x * y;
			}, args1[i], args2[i]));
		}

		debug("Submitted tasks");

		for (int i = 0; i < TEST_SIZE; i++) {
			debug(args1[i], " + ", args2[i], " = ", sums[i].get());
			debug(args1[i], " * ", args2[i], " = ", products[i].get());
		}
		debug("After result, wait 3s");

		std::this_thread::sleep_for(3s);

		debug("Destroying thread pool");
	}

	debug("Exiting main thread");
	getchar();
	return 0;
}


