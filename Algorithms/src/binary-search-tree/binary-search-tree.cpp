/*
 * binary-search-tree.cpp
 *
 *  Created on: 16 Jun 2021
 *      Author: ykhan
 */
#include "binary-search-tree.h"

// find the null node and create a new node at its place
static std::shared_ptr<TreeNode<int>> insertHelper(
		std::shared_ptr<TreeNode<int>> root, int n) {
	if (!root) {
		return std::make_shared<TreeNode<int>>(n);
	}

	if (n < root->key) {
		root->left = insertHelper(root->left, n);
	} else if (n > root->key) {
		root->right = insertHelper(root->right, n);
	}

	return root;
}

void BST::insert(int n) {
	root = insertHelper(root, n);
}

void BST::insertIter(int n) {
	if (!root) {
		root = std::make_shared<TreeNode<int>>(n);
		return;
	}

	std::shared_ptr<TreeNode<int>> curr = root;
	std::shared_ptr<TreeNode<int>> prev{nullptr};

	while (curr) {
		if (n < curr->key) {
			prev = curr;
			curr = curr->left;
		} else if (n > curr->key) {
			prev = curr;
			curr = curr->right;
		}
	}

	if (n < prev->key) {
		prev->left = std::make_shared<TreeNode<int>>(n);
	} else if (n > prev->key) {
		prev->right = std::make_shared<TreeNode<int>>(n);
	}
}

std::shared_ptr<TreeNode<int> > BST::getRoot() {
	return root;
}

static bool searchHelper(std::shared_ptr<TreeNode<int>> root, int n) {
	if (!root)
		return false;

	if (root->key == n) {
		return true;
	} else if (n < root->key) {
		return searchHelper(root->left, n);
	} else if (n > root->key) {
		return searchHelper(root->right, n);
	}
}

// Time O(logn) space O(height)
bool BST::search(int n) {
	return searchHelper(root, n);
}

// Time O(logn) space O(1)
bool BST::searchIter(int n) {
	auto curr = root;

	while (curr) {
		if (curr->key == n)
			return true;
		else if (n < curr->key) {
			curr = curr->left;
		} else if (n > curr->key) {
			curr = curr->right;
		}
	}

	return false;
}

