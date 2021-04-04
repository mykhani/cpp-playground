/*
 * main.cpp
 *
 *  Created on: 4 Apr 2021
 *      Author: ykhan
 */
#include <array>
#include <iostream>
#include "SharedPointer.h"
#include <memory>

using namespace std;

struct Integer {
	int val;
	Integer(int _val) : val{_val}  {
		cout << "Integer constructor, val: " << val << endl;
	}
	~Integer() {
		cout << "Integer destructor, val: " << val << endl;
	}
};

ostream& operator<<(ostream& os, const Integer& i) {
	os << i.val;
}

void test_std_shared_ptr() {
	cout << "Using stl shared_ptr" << endl;

	shared_ptr<Integer> ptr1{new Integer{10}};
	shared_ptr<Integer> ptr2 = ptr1;

	cout << "shared_ptr ptr2 use count: " << ptr2.use_count()
		 << ", addr: " << ptr2.get() << ", val: " << *ptr2 << endl;

	shared_ptr<Integer> ptr3 = std::move(ptr2);
	cout << "shared_ptr ptr3 use count: " << ptr3.use_count()
			 << ", addr: " << ptr3.get() << ", val: " << *ptr3 << endl;

	shared_ptr<int[]> ptr4{new int[5]{1, 2, 3, 4, 5}};
	cout << "shared_ptr ptr4 use count: " << ptr4.use_count()
				 << ", addr: " << ptr4.get() << ", val: ";

	for (int i = 0; i < 5; i++) {
		cout << ptr4[i] << ", ";
	}

	cout << endl;

	shared_ptr<Integer> ptr5{new Integer{500}};
	cout << "shared_ptr ptr5 use count: " << ptr5.use_count()
		 << ", addr: " << ptr5.get() << ", val: " << ptr5->val << endl;

}

void test_custom_shared_ptr() {
	cout << "Using Custom SharedPointer" << endl;

	SharedPointer<Integer> ptr1{new Integer{10}};
	SharedPointer<Integer> ptr2 = ptr1;

	cout << "SharedPointer ptr2 use count: " << ptr2.use_count()
		 << ", addr: " << ptr2.get() << ", val: " << *ptr2 << endl;

	SharedPointer<Integer> ptr3 = std::move(ptr2);
	cout << "SharedPointer ptr3 use count: " << ptr3.use_count()
			 << ", addr: " << ptr3.get() << ", val: " << *ptr3 << endl;

	SharedPointer<int[]> ptr4{new int[5]{1, 2, 3, 4, 5}};
	cout << "SharedPointer ptr4 use count: " << ptr4.use_count()
				 << ", addr: " << ptr4.get() << ", val: ";

	for (int i = 0; i < 5; i++) {
		cout << ptr4[i] << ", ";
	}

	cout << endl;

	SharedPointer<Integer> ptr5{new Integer{500}};
	cout << "SharedPointer ptr5 use count: " << ptr5.use_count()
		 << ", addr: " << ptr5.get() << ", val: " << ptr5->val << endl;

}

int main() {
	test_std_shared_ptr();
	test_custom_shared_ptr();

    cout << "Ending " << endl;
    return 0;
}
