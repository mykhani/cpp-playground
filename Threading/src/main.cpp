/*
 * main.cpp
 *
 *  Created on: 5 Apr 2021
 *      Author: ykhan
 */

#include <thread>
#include <mutex>
#include <iostream>
#include <future>

using namespace std;

std::mutex console;

void thread_fn(int &counter) {
	for (int i = 0; i < 5; i++) {
		counter++;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	std::lock_guard<std::mutex> lg { console };
	cout << "Finished thread_fn " << endl;
}

struct Callable {
	void operator()(int &counter) {
		for (int i = 0; i < 5; i++) {
			counter++;
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}

		std::lock_guard<std::mutex> lg { console };
		cout << "Finished Callable object " << endl;
	}
};

void thread_concurrency() {
	int counter1 = 100;
	int counter2 = 200;
	int counter3 = 300;

	cout << endl;
	cout << "Executing thread based concurrency test" << endl;

	std::thread t1 { thread_fn, std::ref(counter1) };
	std::thread t2 { Callable { }, std::ref(counter2) };
	std::thread t3 { [](int &counter) {
		for (int i = 0; i < 5; i++) {
			counter++;
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}

		std::lock_guard<std::mutex> lg { console };
		cout << "Finished lambda " << endl;

	}, std::ref(counter3) };

	//cout << "Hardware threads: " << t1.hardware_concurrency() << endl;
	// same as
	cout << "Hardware threads: " << std::thread::hardware_concurrency() << endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(4000));
	std::lock_guard<std::mutex> lg { console };
	cout << "In main thread" << "counter1: " << counter1 << ", " << "counter2: "
			<< counter2 << ", " << "counter3: " << counter3 << endl;

	t1.join();
	t2.join();
	t3.join();

	cout << "Finished thread based concurrency test" << endl;
}

using namespace std::chrono_literals;

bool do_work(std::future<bool> start) {
	// wait for the start command
	cout << "Waiting for the start command from main thread" << endl;
	bool go = start.get();
	if (go) {
		cout << "Start command received from main thread" << endl;
		std::this_thread::sleep_for(4s);
		return true;
	}

	return false;
}

void task_concurrency() {
	cout << endl;
	cout << "Executing task based concurrency test" << endl;

	std::promise<bool> start;
	std::future<bool> result = std::async(std::launch::async, do_work, start.get_future());
	bool done = false;

	std::this_thread::sleep_for(2s);

	cout << "Main thread sending start command" << endl;
	start.set_value(true);

	cout << "Main thread waiting for the result " << endl;
	if (result.valid())
		done = result.get();

	cout << "async operation result: " << done << endl;

	cout << "Finished task based concurrency test" << endl;
}

int main() {
	thread_concurrency();
	task_concurrency();
}
