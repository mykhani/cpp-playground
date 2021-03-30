/*
 * utils.cpp
 *
 *  Created on: 30 Mar 2021
 *      Author: ykhan
 */

#include "utils.h"

using namespace std;

namespace utils {

int copy_text_file(const path &src, const path &dst) {
	// check if outfile already exists
	if (exists(dst)) {
		cout << "Destination file " << dst << " already exists" << endl;
		return -1;
	}

	std::ifstream inFile{src};
	if (!inFile) {
		cout << "Source file " << src << " does not exist!" << endl;
		return -1;
	}

	std::ofstream outFile{dst};
	if (!outFile) {
		cout << "Failed to create " << dst << endl;
		return -1;
	}

	std::string line;
	while (getline(inFile, line)) {
		outFile << line << endl;
	}

	inFile.close();
	outFile.close();

	cout << "Copied " << src << " to " << dst << " successfully!" << endl;
	return 0;
}

bool is_binary_file(const path &filename) {
	return filename.extension() == ".bin";
}

int copy_binary_file(const path &src, const path &dst) {
	// check if out file already exists
	if (exists(dst)) {
		cout << "Destination file " << dst << " already exists" << endl;
		return -1;
	}

	std::ifstream ibinstream{src, std::ios::binary};
	if (!ibinstream) {
		cout << "Source file " << src << " does not exist!" << endl;
		return -1;
	}

	std::ofstream obinstream{dst, std::ios::binary};
	if (!obinstream) {
		cout << "Failed to create " << dst << endl;
		return -1;
	}

	// get the size of the file
	char byte; // read byte and end when fail
	while(!ibinstream.read(&byte, 1).fail()) {
		obinstream.write(&byte, 1);
	}

	ibinstream.close();
	obinstream.close();
}

int copy_file(const path &src, const path &dst) {
	cout << "Copying file " << src << " to " << dst << endl;

	// check the type of the file (text or binary)
	if (is_binary_file(src)) {
		copy_binary_file(src, dst);
	} else {
		copy_text_file(src, dst);
	}
}

int copy_directory(const path &src, const path &dst) {
	directory_iterator dirent{src};
	directory_iterator end{}; // empty

	path srcDirname{src.filename()};
	path destDirname{dst.filename()};

	cout << "creating directory: " << dst << endl;
	if (!create_directory(dst)) {
		cout << "Failed to create the dir: " << dst << ", exiting!" << endl;
		return -1;
	}

	while (dirent != end) {
	    path filename{dirent->path().filename()};

	    if (is_directory(*dirent)) {
	    	utils::copy_directory(*dirent, dst / filename);
	    } else {
	    	utils::copy_file(*dirent, dst / filename);
	    }

	    dirent++;
	}

	return 0;
}

int copy(const path &src, const path &dst) {
	int ret;

	if (is_directory(src))
		ret = utils::copy_directory(src, dst);
	else
		ret = utils::copy_file(src, dst);

	return ret;
}

} // namespace utils
