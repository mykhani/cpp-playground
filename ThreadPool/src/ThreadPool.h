/*
 * ThreadPool.h
 *
 *  Created on: 12 Apr 2021
 *      Author: ykhan
 */

#ifndef THREADPOOL_H_
#define THREADPOOL_H_

#include <thread>
#include <atomic>
#include <vector>
#include <future>
#include <memory>
#include <mutex>
#include <functional>
#include <type_traits>
#include "safe_queue.h"

#include "debug.h"

struct IWork {
	// must contain a packaged task
	virtual void execute() = 0;
};

template <typename T>
struct Work : public IWork {
	std::packaged_task<T> task;

	Work(std::packaged_task<T>&& _task) : task{std::move(_task)} {

	}

	void execute() override {
		task();
	}
};

using work_t = std::unique_ptr<IWork>;

class ThreadPool {
private:
	std::vector<std::thread> threads;
	safe_queue<work_t> workqueue;
	int num_threads;
	std::atomic<bool> done;

	void work_task() {

		while (!done) {
			auto work = std::move(*workqueue.wait_pop());
			work->execute();
			debug("Executed task in thread id: ", std::this_thread::get_id());
		}
	}

public:
	ThreadPool() : done{false} {
		// minus 1 for main thread
		num_threads = std::thread::hardware_concurrency() - 1;
		for (int i = 0; i < num_threads; i++) {
			 threads.push_back(std::thread{&ThreadPool::work_task, this}); // will immediately invoke it
		}

		debug("Created thread pool with ", num_threads, " threads");
	}

	~ThreadPool() {
		done = true;

		// push 4 dummy tasks so that threads can exit the wait_pop on the workqueue
		for (int i = 0; i < num_threads; i++) {
			submit([](){});
		}

		for (int i = 0; i < num_threads; i++) {
			if (threads[i].joinable()) {
				threads[i].join();
			}
		}
	}

	template <typename F, typename ... Args>
	std::future<typename std::result_of<F(Args...)>::type> submit(F f, Args ... args) {
		using R = typename std::result_of<F(Args...)>::type;

		auto task = std::packaged_task<R()>(std::bind(f, args...));

		auto fut = task.get_future();

		std::unique_ptr<IWork> work = make_unique<Work<R()>>(std::move(task));

		workqueue.push(std::move(work));

		return fut;
	}
};

#endif /* THREADPOOL_H_ */
