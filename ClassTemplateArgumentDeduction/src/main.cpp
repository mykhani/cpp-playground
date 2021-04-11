/*
 * main.cpp
 *
 *  Created on: 8 Apr 2021
 *      Author: ykhan
 */
#include <iostream>

using namespace std;

template <typename T>
class Data {
	T val;
public:
	Data(const T& _val) : val{_val} {}
};

// Deduction guides
Data(const char* ) -> Data<std::string>;

int main() {
	Data d1{5};
	auto d2 = new Data{10};
	auto d3 = new Data{"hello"}; // creates Data<std::string>

	cout << typeid(d3).name() << endl;
}

