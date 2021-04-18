#ifndef HASHING_H
#define HASHING_H

/*
 Hashing mainly used to implement:
 * Dictionaries (key - values)
 * Sets
 Hashing advantages:
 * Search O(1)
 * Insert O(1)
 * Delete O(1)

 How does it compare with:
 Unsorted arrays:
 * Search O(n)
 * Insert O(1) // insert at end
 * Delete O(1) // just mark element as deleted (no need to adjust array)

 Sorted arrays:
 * Search O(logn)
 * Insert O(n)
 * Delete O(n)

 Self balance binary search trees (AVL and RB)
 * Search O(logn)
 * Insert O(logn)
 * Delete O(logn)

 * Hash table is good for finding exact match
 * Not good for cases where:
 * you need less than or greater than keys (use BST)
 * you need elements as sorted (use BST)

 Hashing applications:
 * Dictionaries
 * Database indexing
 * Cryptography
 * Caches
 * Symbol table in compiler/interpreters
 * Routers
 * Getting data from databases

 Hash function: convert a large value into a small value that can be
 used as an index

 Requirements for a hash function:
 * Everytime a hash function is applied to a key, it must generate the same hash value (index?) 
 * Should generate values from 0 to m - 1 where m is the size of hash table
 * Should be fast. O(1) for integers and O(len) for strings of length len
 * Should uniformly distribute large keys into hash table slots (to make sure each go into
 its own slot. Difficult to achieve and there would be cases where different keys result
 into a same hash value, which is called a collision.

 Example hashing functions:
 * hash(large_key) = large_key % m where m is the size of hash table. Ideally m is chosen
 as a prime number (less common factors) close to the size of hash table. Other bad
 value of m is 10^n e.g. 10^3. Here, the hash function only checks last 3 digits.
 or m = 2^3, where it checks only last 3 bits in the binary representation

 * for strings, weighted sum: str = "abcd";
 hash(str) = (str[0] * x^0 + str[1] * x^1 + str[2] * x^2....) % m;
 where x can be any numbe e.g. x = 33;

 if simple sum is used i.e. sum ASCII values of all characters and then take modulo m,
 there is a problem i.e. hash for "abcd" and "dcba" or any other permutation would be same.
 That is why weighted sum is used.

 * universal hashing
 You have a group of hash functions, and each time you pick one of them randomly.
 There is no pattern of data for which it will not result in uniform distribution

 Hashing collisions:
 * If we know keys in advance, then we can use perfect hashing (advanced technique)
 * If we do not know keys in advance, then we use one of the following:
 * Chaining // maintain an array of linkedlist. Each slot is a linkedlist
 that contains collided keys
 * Open Addressing:
 * Linear probing
 * Quadratic probing
 * Double hashing

 Chaining Performance:
 m = number of slots in hash table
 n = number of keys to be inserted
 load factor (alpha) = n / m; (C++ allows to set load factor for unordered_set, unordered_map)
 load factor determines how big you want your hash table to be. It is a trade-off between
 space and time. A higher load factor means smaller m (inversely proportional). smaller m
 means more collisions and hence, more time

 Expected chain length = n / m = load factor (alpha) (assuming an uniform distribution i.e. every key is equally likely
 to go into other slot i.e. probability for a key to to occupy any slot out of m slots is 1 / m)
 So the number of keys in a particular slot is n / m);

 Worst case: all keys go into a same slot.

 Expected time to search: O(1 + alpha). O(1) to find the slot and O(alpha) to search through the chain
 Expected time to insert/delete: O(1 + alpha)

 All the above works if the hashing function generates keys with uniform distribution

 Options of datastructures to implement chaining
 * linkedlist   
 * search O(l), insert/delete O(l)
 * not cache friendly
 * extra overhead for storing next pointers

 * vector (Dynamic arrays)
 * search O(l), insert O(l), delete O(l)
 * cache friendly

 * Self-balancing BST (AVL or RB)
 * search O(logl), insert O(logl), delete O(logl)
 * not cache friendly
 
 */
#include <vector>
#include <type_traits>
#include <iostream>
#include <stdexcept>

using namespace std;
/* 
 Drawbacks of using direct address table
 * array size could be very large
 * doesn't work when keys are floating points or strings
 */
class DirectAddressTable {
	vector<bool> tbl;
	int offset;
public:
	DirectAddressTable(int start, int end);
	void insert(int key);
	void remove(int key);
	bool search(int key);
};

struct Node;

struct Node {
	int val;
	Node *next { nullptr };

	Node(int _val) :
			val { _val } {
		cout << "Creating node with val: " << val << endl;
	}
	~Node() {
		cout << "Deleting node with val: " << val << endl;
	}
};

// Hashtable with chaining to handle collisions
class HashTableChaining {
	vector<Node*> buckets;
	int bucketSize;
public:
	HashTableChaining(int _bucketSize);
	~HashTableChaining();
	void insert(int key);
	void remove(int key);
	bool search(int key);
};

// Open addressing is another method to handle collisions
// Requirements: no of slots >= number of keys (or items) to be inserted
// Benefit: cache friendly

// multiple implementations of open-addressing:
// * linear probing - linearly search for the next empty spot after a collision is detected
// * quadratic probing - next probed position is the square of the collision.
//                       e.g if collision happens at position cur, then for 1st, 2nd and 3rd collision,
//                       probed positions are next cur + 1, cur + 4, cur + 9
//                       or hash(cur, i) for i >=1, cur + i^2
// * double hashing

enum class SlotStatus {
	EMPTY, OCCUPIED, DELETED
};

template<typename Key>
class HashTableOpenAddressing {
protected:
	int slots;
	vector<Key> values;
	vector<SlotStatus> slotStatus;

public:
	HashTableOpenAddressing(int _slots) :
			slots { _slots }, values(_slots, Key { }), slotStatus(_slots,
					SlotStatus::EMPTY) {
	}

	int hash(Key k);
	void insert(Key key);
	void remove(Key key);
	bool search(Key key);

	virtual int probe(Key key, bool search = false) = 0;

	virtual ~HashTableOpenAddressing() = default;
};

template<typename Key>
inline int HashTableOpenAddressing<Key>::hash(Key k) {
	// TODO: check if Key type is int
//	return k % HashTableOpenAddressing<Key>::slots;
	// slots is not detected without this-> prefix
	// see https://stackoverflow.com/questions/1120833/derived-template-class-access-to-base-class-member-data
	return k % this->slots;
}

template<typename Key>
inline void HashTableOpenAddressing<Key>::insert(Key key) {
	int slot = probe(key); // linear or quadratic probing

	if (slot >= 0) {
		this->values[slot] = key;
		this->slotStatus[slot] = SlotStatus::OCCUPIED;
	}
}

template<typename Key>
inline void HashTableOpenAddressing<Key>::remove(Key key) {
	int slot = probe(key, true);

	if (slot >= 0) {
		this->slotStatus[slot] = SlotStatus::DELETED;
	}
}

template<typename Key>
inline bool HashTableOpenAddressing<Key>::search(Key key) {
	int slot = probe(key, true);

	if (slot >= 0)
		return true;

	return false;
}

// Linear probing
// problem with linear probing is clusters
// to spread out these clusters, use quadratic probing (instead of searching consecutive
// positions, search every next, fourth, 9th i.e i^2 element
// The disadvantage of quadratic probing is that it might miss empty
// slots even if they are available
// Mathematically, it has been proven that to not skip any empty
// slots using quadratic probing,s
// if load factor < 0.5 and number of slots m is a prime number, only
// then quadratic probing guarantees that it won't skip any empty slots
// lf = entries / m; so m should be > double the entries for quadratic
// probing to work
// quadratic probing also has secondary clusters but it is still better than
// clusters using linear probing
template<typename Key>
class HashTableOpenAddressingLinearProbing: public HashTableOpenAddressing<Key> {

public:
	virtual int probe(Key key, bool search = false) override;

	// inherit ctor
	using HashTableOpenAddressing<Key>::HashTableOpenAddressing;

};

template<typename Key>
inline int HashTableOpenAddressingLinearProbing<Key>::probe(Key key,
		bool search) {
	//
	int i = 0;
	int start = this->hash(key);
	int pos = start + i;

	// if we are searching for a key, terminate search when key is found or an empty slot is encountered
	if (search) {
		do {
			if (this->slotStatus[pos] == SlotStatus::EMPTY)
				return -1;

			// Either occupied or deleted
			if (this->values[pos] == key) {
				if (this->slotStatus[pos] != SlotStatus::DELETED) {
					return pos;
				} else {
					return -1;
				}
			}

			i++;
			pos = (start + i) % this->slots;

		} while (this->slotStatus[pos] != SlotStatus::EMPTY && pos != start);
	// we are looking for a free position (empty or deleted)
	} else {
		do {
			if (this->slotStatus[pos] == SlotStatus::EMPTY
					|| this->slotStatus[pos] == SlotStatus::DELETED) {
				return pos;
			}

			i++;
			pos = (start + i) % this->slots;

		} while (pos != start);
	}

	return -1;
}

template<typename Key>
class HashTableOpenAddressingQuadraticProbing: public HashTableOpenAddressing<Key> {
public:
	virtual int probe(Key key, bool search = false) override;

	// inherit ctor
	using HashTableOpenAddressing<Key>::HashTableOpenAddressing;

};

template<typename Key>
inline int HashTableOpenAddressingQuadraticProbing<Key>::probe(Key key,
		bool search) {
	//
	int i = 0;
	int start = this->hash(key);
	int pos = start + i;

	// if we are searching for a key, terminate search when key is found or an empty slot is encountered
	if (search) {
		do {
			if (this->slotStatus[pos] == SlotStatus::EMPTY) {
				return -1;
			}
			// Either occupied or deleted
			if (this->values[pos] == key) {
				if (this->slotStatus[pos] != SlotStatus::DELETED) {
					return pos;
				} else {
					return -1;
				}
			}

			i++;
			pos = (start + i * i) % this->slots;

		} while (this->slotStatus[pos] != SlotStatus::EMPTY && pos != start);
	// we are looking for a free position
	} else {
		do {
			if (this->slotStatus[pos] == SlotStatus::EMPTY
					|| this->slotStatus[pos] == SlotStatus::DELETED) {
				return pos;
			}

			i++;
			pos = (start + i * i) % this->slots;

		} while (pos != start);
	}

	return -1;
}

#endif
