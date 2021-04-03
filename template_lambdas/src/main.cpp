//============================================================================
// Name        : templates.cpp
// Author      : Yasir Khan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include "utils.h"
#include <vector>
#include <initializer_list>
#include <utility>

using namespace std;

//Return largest element
//T Max(T, T);
//Return true if first argument is greater than the second
//bool Greater(T, T) ;
//Return true if first argument is less than the second
//bool Less(T, T) ;
//Accept iterators of any container and return the largest and smallest element from that container.
//pair<T,T> MinMax(ItrBegin, ItrEnd) ;

template <typename T>
struct Max {
	T operator() (const T& a, const T& b) {
		return a > b ? a : b;
	}
};

template <typename T>
struct Greater {
	bool operator() (const T& a, const T& b) {
		return a > b;
	}
};

template <typename T>
struct Less {
	bool operator() (const T& a, const T& b) {
		return a < b;
	}
};

template <typename Iter>
struct MinMax {
	using IterType = typename std::iterator_traits<Iter>::value_type;

	std::pair<IterType,IterType> operator() (Iter begin, Iter end) {
		IterType min = *begin;
		IterType max = *begin;

		while (begin != end) {
			if (*begin > max)
				max = *begin;
			if (*begin < min)
				min = *begin;

			begin++;
		}

		return {min, max};
	}
};

int main() {
	int arr[] = {5, 4, 3, 2, 1};

	auto max = [](const auto &a, const auto &b) {
		return a > b ? a : b;
	};

	auto greater = [](const auto& first, const auto& second) {
		return first > second;
	};

	auto less = [](const auto& first, const auto& second) {
		return first < second;
	};

	auto minmax = [](auto begin, auto end) {
		auto min = *begin;
		auto max = *begin;

		while (begin != end) {
			if (*begin > max)
				max = *begin;

			if (*begin < min)
				min = *begin;

			begin++;
		}

		return std::pair<decltype(min), decltype(max)>{min, max};
	};

	cout << max(4, 5) << endl;
	cout << boolalpha << greater("yasir", "sosin") << endl;
	cout << less(10, 5) << endl;
	auto res = minmax(std::begin(arr), std::end(arr));
	cout << res.first << ", " << res.second <<  endl;

	cout << endl;

	cout << Max<int>{}(4, 5) << endl;
	cout << Greater<string>{}("yasir", "sosin") << endl;
	cout << Less<int>{}(10, 5) << endl;
	auto res2 = MinMax<int *>{}(arr, arr + 5);
	cout << res2.first << ", " << res2.second <<  endl;

	vector<string> names{"yasir", "sosin", "awais"};
	auto res3 = MinMax<vector<string>::iterator>{}(names.begin(), names.end());
	cout << res3.first << ", " << res3.second <<  endl;

	return 0;
}
