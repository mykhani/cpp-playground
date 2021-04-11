/*
 * main.cpp
 *
 *  Created on: 11 Apr 2021
 *      Author: ykhan
 */
#include <iostream>

using namespace std;

// without folding expressions
template <typename Acc, typename Op>
Acc reduce(Op op, Acc acc) {
	return acc;
}

template <typename Acc, typename First, typename ... Args, typename Op>
Acc reduce(Op op, Acc acc,  First f, Args ... args) {
	acc = op(acc, f);
	return reduce(op, acc, args...);
}

// Folding expression
template<typename ... Args>
	auto Sum(Args ... args) {
	return (... + args);
}

template<typename Predicate, typename ... Args>
	bool AnyOf(Predicate op, Args ... args) {
	// op(arg1) == 0 || (op(arg2) || op(arg3)
	return (... || op(args));
}

// binary folds
template<typename Init, typename ... Args>
	auto Sum2(Init i, Args ... args) {
	 // arg1 + (arg2 + arg3)
	 // right fold
	return (args + ... + i);
}

template<typename ... Args>
	void log(Args ... args) {
	 // oss << args1 << args2 << args3
	(cout << ... << args);
}

int main() {

	int sum = 0;

	auto adder = [](auto &a, auto &b) {
		return a + b;
	};

	cout << reduce(adder, sum, 1, 2, 3, 4, 5) << endl;
	cout << reduce([](auto &a, auto &b) {
		return a * b;
	}, 1, 1, 2, 3, 4, 5) << endl;

	cout << Sum(1, 2, 3, 4, 5) << endl;
	cout << Sum2(10, 1, 2, 3, 4, 5) << endl;
	cout << std::boolalpha << AnyOf([](auto &arg) {
		return arg % 2 == 0;
	}, 1, 2, 3, 4, 5, 6) << endl;

	cout << std::boolalpha << AnyOf([](auto &arg) {
		return arg % 10 == 0;
	}, 1, 2, 3, 4, 5, 6) << endl;

	return 0;
}
