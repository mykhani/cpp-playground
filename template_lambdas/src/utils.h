/*
 * utils.h
 *
 *  Created on: 1 Apr 2021
 *      Author: ykhan
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>
#include <cstring>

using namespace std;

//Return the sum of two elements
template <typename T>
T Add(const T& x,const T& y)
{
	return x + y;
}

//Returns the sum of array elements
template <typename T, int size>
T ArraySum(T (&pArr)[size])
{
	cout << "arrSize " << size << endl;

	T result{};

	for (int i = 0; i < size; i++) {
		result += pArr[i];
	}

	return result;
}
//
template <int size>
char* ArraySum(const char* (&arr)[size]) {
	char *result = new char[100];
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			strcpy(result, arr[i]);
		} else {
			strcat(result, arr[i]);
		}
	}

	return result;
}

template <int size>
string ArraySum(string (&arr)[size]) {
	string result;
	for (int i = 0; i < size; i++) {
		result += arr[i];
	}

	return result;
}

template <int size>
void Print() {
	cout << "Size is " << size << endl;
}

template <typename T, int size>
T Sum(T (&arr)[size])
{
	T result{};

	for (int i = 0; i < size; i++) {
		result += arr[i];
	}

	return result;
}


#endif /* UTILS_H_ */
