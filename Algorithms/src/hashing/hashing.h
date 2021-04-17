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
    Node* next{nullptr};
    
    Node(int _val) : val{_val} {
        cout << "Creating node with val: " << val << endl;
    }
    ~Node() {
        cout << "Deleting node with val: " << val << endl;
    }
};

// Hashtable with chaining to handle collisions
class HashTableChaining {
    vector<Node *> buckets;
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
// * quadratic probing
// * double hashing

template <typename Key>
class HashTableOpenAddressing {
protected:
	vector<Key> values;
	int slots;

public:
	HashTableOpenAddressing(int _slots) : values(_slots, Key{}), slots{_slots} {}

	virtual void insert(Key key) = 0;
	virtual void remove(Key key) = 0;
	virtual bool search(Key key) = 0;

	virtual ~HashTableOpenAddressing() = default;
};


// Linear probing
// problem with linear probing is clusters
// to spread out these clusters, use quadratic probing (instead of searching consecutive
// positions, search every next, fourth, 9th i.e i^2 element
// The disadvantage of quadratic probing is that it might miss empty
// slots even if they are available
// Mathematically, it has been proven that to not skip any empty
// slots using quadratic probing,
// if load factor < 0.5 and number of slots m is a prime number, only
// then quadratic probing guarantees that it won't skip any empty slots
// lf = entries / m; so m should be > double the entries for quadratic
// probing to work
// quadratic probing also has secondary clusters but it is still better than
// clusters using linear probing
template <typename Key>
class HashTableOpenAddressingLinearProbing : public HashTableOpenAddressing<Key> {

	enum class SlotStatus {
		EMPTY,
		OCCUPIED,
		DELETED
	};

private:
	vector<SlotStatus> slotStatus;
public:
	int hash(Key k);
	int findEmptyOrDeleted(int begin);
	int findOccupied(int begin, Key k);

	HashTableOpenAddressingLinearProbing(int _slots)
		: HashTableOpenAddressing<Key>(_slots), slotStatus(_slots, SlotStatus::EMPTY)  {}

	~HashTableOpenAddressingLinearProbing() = default;

	void insert(Key key) override;
	void remove(Key key) override;
	bool search(Key key) override;
};

template<typename Key>
inline void HashTableOpenAddressingLinearProbing<Key>::insert(Key key) {
	int slot = hash(key);

	if (slotStatus[slot] == SlotStatus::OCCUPIED) {
		slot = findEmptyOrDeleted(slot + 1);
	}

	if (slot >= 0) {
		this->values[slot] = key;
		this->slotStatus[slot] = SlotStatus::OCCUPIED;
	}
}

template<typename Key>
inline void HashTableOpenAddressingLinearProbing<Key>::remove(Key key) {
	int slot = hash(key);

	if (this->slotStatus[slot] == SlotStatus::EMPTY)
		return;

	// OCCUPIED or DELETED
	if (this->values[slot] != key) {
		slot = findOccupied(slot + 1, key);
	}

	if (slot >= 0) {
		this->slotStatus[slot] = SlotStatus::DELETED;
	}
}

template<typename Key>
inline int HashTableOpenAddressingLinearProbing<Key>::hash(Key k) {
	// TODO: check if Key type is int
//	return k % HashTableOpenAddressing<Key>::slots;
	// slots is not detected without this-> prefix
	// see https://stackoverflow.com/questions/1120833/derived-template-class-access-to-base-class-member-data
	return k % this->slots;
}

template<typename Key>
inline int HashTableOpenAddressingLinearProbing<Key>::findEmptyOrDeleted(int begin) {
	for (int i = 0; i < this->slots; i++) { // circular search
		int index = (begin + i) % this->slots;
		if (slotStatus[index] == SlotStatus::EMPTY || slotStatus[index] == SlotStatus::DELETED)
			return index;
	}
	return -1;
}

template<typename Key>
inline int HashTableOpenAddressingLinearProbing<Key>::findOccupied(int begin, Key k) {
	for (int i = 0; i < this->slots; i++) { // circular search
		int index = (begin + i) % this->slots;
		// if an empty slot found no need to search further
		if (this->slotStatus[index] == SlotStatus::EMPTY)
			return -1;

		if (this->values[index] == k) {
			if (this->slotStatus[index] == SlotStatus::OCCUPIED) {
				return index;
			} else {
				return -1;
			}
		}
	}
	return -1;
}

template<typename Key>
inline bool HashTableOpenAddressingLinearProbing<Key>::search(Key key) {
	int slot = hash(key);

	// return if the key doesn't exist at all
	if (this->slotStatus[slot] == SlotStatus::EMPTY)
		return false;

	if (this->values[slot] == key) {
		return true;
	}

	slot = findOccupied(slot + 1, key);
	if (slot >= 0)
		return true;

	return false;
}

#endif
