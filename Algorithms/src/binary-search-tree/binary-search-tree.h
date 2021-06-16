/*
 * binarysearchtree.h
 *
 *  Created on: 16 Jun 2021
 *      Author: ykhan
 */

#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

#include "../tree/tree.h"
#include <utility>
/*
 * Background on Binary Search Tree
 * Time complexities of various operations for different datastructures
 * 					Array (Unsorted)	Array(Sorted)	Linkedlist	BST(balanced)	Hashtable
 * Search			O(n)				O(logn)			O(n)		O(logn)			O(1)
 * Insert			O(1)				O(n)			O(1)		O(logn)			O(1)
 * Delete			O(n)				O(n)			O(n)		O(logn)			O(1)
 * Find closest		O(n)				O(logn)			O(n)		O(logn)			O(n)
 * Sorted traversal O(nlogn)			O(n)			O(nlogn)	O(n)			O(nlogn)
 */

class BST {
	std::shared_ptr<TreeNode<int>> root{nullptr};
public:
	BST() = default;
	void insert(int n);
	void insertIter(int n);
	bool search(int n);
	bool searchIter(int n);
	std::shared_ptr<TreeNode<int>> getRoot();
};

#endif /* BINARY_SEARCH_TREE_H_ */
