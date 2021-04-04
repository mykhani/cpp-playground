/*
 * SharedPointer.h
 *
 *  Created on: 4 Apr 2021
 *      Author: ykhan
 */

#ifndef SHAREDPOINTER_H_
#define SHAREDPOINTER_H_

#include <iostream>
#include <utility>
#include <type_traits>

using namespace std;

// To remove [] brackets e.g.
// when T = int[], PType = int*
// when T = int, PType = int*

template <typename T>
using PType = typename std::remove_extent<T>::type;

template <typename T>
class SharedPointer {
	PType<T>* data;
	int* refCount;
public:
	explicit SharedPointer(PType<T>* _data = nullptr);
	// copy constructor
	SharedPointer(const SharedPointer& other);
	// copy assignment
	SharedPointer& operator =(const SharedPointer& other);
	// move constructor
	SharedPointer(SharedPointer&& other);
	// move assignment
	SharedPointer& operator =(SharedPointer&& other);

	int use_count() const;
	PType<T>* get() const;

	// * operator
	PType<T>& operator *() {
		return *data;
	}

	// -> operator
	PType<T>* operator ->() {
		return data;
	}

	// [] operator
	PType<T>& operator [](int index) {
		return data[index];
	}

	virtual ~SharedPointer();
};

template<typename T>
inline SharedPointer<T>::SharedPointer(const SharedPointer &other)
	: data{other.data}, refCount{other.refCount} {
	if (data)
		(*refCount)++;

	cout << "SharedPointer copy constructor, ref count" << *refCount << endl;
}

template<typename T>
inline SharedPointer<T>& SharedPointer<T>::operator =(const SharedPointer &other) {
	refCount = other.refCount;
	data = other.data;
	if (data)
		(*refCount)++;

	cout << "SharedPointer copy assignment, ref count" << *refCount << endl;
}

template<typename T>
inline SharedPointer<T>::SharedPointer(SharedPointer &&other)
	: data{other.data}, refCount{other.refCount} {
	other.data = nullptr;
	other.refCount = nullptr;
	cout << "SharedPointer move constructor, ref count" << *refCount << endl;
}

template<typename T>
inline SharedPointer<T>& SharedPointer<T>::operator =(SharedPointer &&other) {
	refCount = other.refCount;
	data = other.data;
	other.data = nullptr;
	other.refCount = nullptr;
	cout << "SharedPointer move assignment, ref count" << *refCount << endl;
}

template<typename T>
inline SharedPointer<T>::SharedPointer(PType<T>*_data)
	: data{std::move(_data)}, refCount{new int{}} {
	if (data)
		(*refCount)++;

	cout << "SharedPointer constructor, ref count" << *refCount << endl;
}

template<typename T>
inline int SharedPointer<T>::use_count() const {
	return *refCount;
}

template<typename T>
inline PType<T>* SharedPointer<T>::get() const {
	return data;
}

template<typename T>
inline SharedPointer<T>::~SharedPointer() {

	if (!refCount)
		return;

	cout << "SharedPointer destructor: ref_count " << *refCount << endl;
	// decrement ref count
	if (refCount)
		(*refCount)--;

	if (*refCount == 0) {
		cout << "Ref count is 0, deallocating object " << data << endl;
		// check whether to call delete or delete []
		if (std::is_array<T>::value) {
			cout << "Calling delete []" << endl;
			delete [] data;
		}
		else {
			cout << "Calling delete" << endl;
			delete data;
		}
	}
}

#endif /* SHAREDPOINTER_H_ */
