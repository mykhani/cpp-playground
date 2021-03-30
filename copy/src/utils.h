/*
 * utils.h
 *
 *  Created on: 30 Mar 2021
 *      Author: ykhan
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <fstream>
#include <iostream>

#include <experimental/filesystem>
using namespace std::experimental::filesystem;

namespace utils {

bool is_binary_file(const path& filename);
int copy(const path& src, const path&dst);
int copy_file(const path& src, const path& dst);
int copy_directory(const path& src, const path& dst);
int copy_text_file(const path& src, const path& dst);
int copy_binary_file(const path& src, const path& dst);

}

#endif /* UTILS_H_ */
