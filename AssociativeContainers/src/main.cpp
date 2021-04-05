/*
 * main.cpp
 *
 *  Created on: 5 Apr 2021
 *      Author: ykhan
 */

#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// custom class
struct Object {
	int id;
	std::string name;
	Object() = default;

	Object(int _id, std::string _name = "") : id{_id}, name{_name} {
		cout << "Object Constructor. id: " << id << ", name: " << name << endl;
	}
	~Object() {
//		cout << "Object Destructor. id: " << id << ", name: " << name << endl;
	}
	// copy constructor
	Object(const Object& other) : id{other.id}, name{other.name} {

	}
	// copy assignment
	Object& operator=(const Object& other) {
		id = other.id;
		name = other.name;
		return *this;
	}

	// move constructor
	Object(Object&& other) : id{other.id}, name{other.name} {}

	// move assignment
	Object& operator=(Object&& other) {
		id = other.id;
		name = other.name;
		return *this;
	}

	bool operator <(const Object& rhs) {
		return id < rhs.id;
	}
};

std::ostream& operator<<(std::ostream& os, const Object& obj) {
	os << "{";
	os << "\tid : " << obj.id << endl;
	os << "\tname : " << obj.name << endl;
	os << "}";

	return os;
}

std::ostream& operator<<(std::ostream& os, const vector<Object>& objs) {
	os << "[" << endl;
	for (const auto& obj : objs)
		os << obj << ", " << endl;
	os << "]";

	return os;
}

struct ObjectHasher {
	size_t operator ()(const Object& object) const {
		auto hashId = std::hash<int>{}(object.id);
		auto hashName = std::hash<std::string>{}(object.name);

		return hashId ^ hashName;
	}
};

struct ObjectEquality {
	bool operator ()(const Object& a, const Object& b) const {
		return a.id == b.id;
	}
};

std::ostream& operator<<(std::ostream& os, std::map<int, std::string>& m) {
	os << "{";
	for (const auto& item : m) {
		os << "\t" << item.first << ": " << item.second << endl;
	}
	os << "}";

	return os;
}

void UnorderedSet() {
// initialization
	std::unordered_set<std::string> heroes{"Hulk", "Batman", "Green Lantern"};

	// inserting items
	heroes.insert("Wonder Woman");

	// get the bucket count for the hash table
	std::cout << "Bucket count: " << heroes.bucket_count() << std::endl;
	// number of elements
	std::cout << "Number of elements: " << heroes.size() << std::endl;
	// Load factor
	std::cout << "Load factor: " << heroes.load_factor() << std::endl;
}

void UnorderedSetCustomObject() {
// initialization
	std::unordered_set<Object, ObjectHasher, ObjectEquality> objects;

	Object obj1{1, "Obj1"};
	Object obj2{2, "Obj2"};

	objects.insert(obj1);
	objects.insert(obj2);
	objects.insert(Object{3, "Obj3"});

	// get the bucket count for the hash table
	std::cout << "Bucket count: " << objects.bucket_count() << std::endl;
	// number of elements
	std::cout << "Number of elements: " << objects.size() << std::endl;
	// Load factor
	std::cout << "Load factor: " << objects.load_factor() << std::endl;

	auto it = objects.find(obj2);

	if (it != objects.end())
		std::cout << "Found Object: " << *it << endl;
	else
		std::cout << "Object not found" << endl;

	it = objects.find(Object{3, "Obj3"});
	if (it != objects.end())
		std::cout << "Found Object: " << *it << endl;
	else
		std::cout << "Object not found" << endl;
}

void StdMap() {
	// std::map<keyType, valueType, comparatorObjOptional, allocatorOptonal>

	std::map<int, std::string> fruits {
		{1, "Apple"},
		{2, "Banana"},
		{3, "Cherry"}
	};

	// insert an item
	fruits.insert(std::pair<int, std::string>{4, "Dragonfruit"});
	// or
	fruits.insert(std::make_pair(5, "Eggfruit"));
	// or use subscript operator
	fruits[6] = "Figs";

	cout << fruits << endl;

	// modify a value
	fruits[0] = "Apricot";

	cout << fruits << endl;

	// erase by key
	fruits.erase(2);

	cout << fruits << endl;

	// erase by iterator
	auto it = fruits.find(5);
	if (it != fruits.end()) {
		fruits.erase(it);
	}

	cout << fruits << endl;
}

void UnorderedMap() {
	std::unordered_map<int, Object> objects;

	objects.insert(std::pair<int, Object>{1, Object{1, "Obj1"}});

	cout << objects[1] << endl;

}

void Hashing() {
	std::hash<std::string> hasher;
	cout << "Hash: " << hasher("Hello") << endl;
}

void Sorting() {
	std::vector<Object> objects {
		Object{3, "Object3"},
		Object{2, "Object2"},
		Object{1, "Object1"},
	};

	cout << "Before sorting: " << objects << endl;

	std::sort(objects.begin(), objects.end());

	cout << "After sorting: " << objects << endl;
}

int main() {
	StdMap();
	UnorderedSet();
	UnorderedSetCustomObject();
	UnorderedMap();
	Hashing();
	Sorting();
	return 0;
}
