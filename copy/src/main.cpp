/*
 * main.cpp
 *
 *  Created on: 30 Mar 2021
 *      Author: ykhan
 */
#include "utils.h"
#include <iostream>
#include <experimental/filesystem>

using namespace std;
using namespace utils;
using namespace std::experimental::filesystem;

int main(int argc, char *argv[])
{
	/* TODO
	 * A utility to copy both text and binary files
	 */
	path src{};
	path dst{};

	switch (argc) {
		case 1:
			cout << "missing file operand" << endl;
			return -1;
		case 2:
			cout << "missing destination file operand after " << argv[1] << endl;
			return -1;
		case 3:
			src = argv[1];
			dst = argv[2];
	}

	auto currentPath = current_path();
	cout << currentPath << endl;

	utils::copy(src, dst);
}
