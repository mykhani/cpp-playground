/*
 * greedy.h
 *
 *  Created on: 30 May 2021
 *      Author: ykhan
 */

#ifndef GREEDY_GREEDY_H_
#define GREEDY_GREEDY_H_

#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include "../tree/tree.h"

using namespace std;

/*
 * Greedy algorithms are suitable to solve optimization problems
 * Optimization problems -> minimize or maximize something
 *
 * Greedy algorithms might not always work.
 * E.g from coins {18, 10, 1} find minimum coins that make
 * 20 returns 3 i.e. 1 coin of 18 and 2 coins of 1 instead
 * of returning 2 for 2 coins of 10
 *
 * General pattern
 * from a list of items:
 *     select an item
 *     check if it is feasible (at this point contributes to optimal solution
 *
 * Greedy algorithm doesn't consider big picture, only the current point in time
 *
 * Applications
 * Finding optimal solutions
 * * Activity Selection
 * * Fractional Knapsack
 * * Job sequencing
 * * Prim's algorithm
 * * Kruskal's algorithm
 * * Dijkstra's algorithm
 * * Huffman coding (optimal loss-less compression)
 *
 * Find close to optimal solutions for NP hard problems like
 * * Traveling salesman problem
 *
 * There are some problems in CS called NP hard problems for which
 * no solution exists with a polynomial time complexity
 */

// find the minium number of coins that makeup a value
int minimumCoins(std::vector<int> coins, int value) {
	// sort in decreasing order
	std::sort(coins.begin(), coins.end(), [](const int& a, const int& b) {
		return a > b;
	});

	int count = 0;

	for (int i = 0; i < coins.size() && value; i++) {
		if (coins[i] <= value) {
			count += value / coins[i];
			value = value % coins[i];
		}
	}

	// if all coins checked and value is still > 0 it means
	// the value cannot be achieved through coins
	if (value)
		return -1;

	return count;
}

// select maximum activities possible
// time  O(nlogn), space O(1)
int maximumActivities(std::vector<std::pair<int, int>> activities) {
	// sort according to the increasing order of finish time
	// O(nlogn)
	std::sort(activities.begin(), activities.end(),
			[](std::pair<int, int>& a, std::pair<int, int>& b) {
				return a.second < b.second;
			});

	auto prev = activities[0];
	int count = 1;
	int maxCount = 0;

	// count non-overlapping O(n)
	for (int i = 1; i < activities.size(); i++) {
		auto curr = activities[i];
		if (curr.first >= prev.second) {
			count++;
			maxCount = std::max(maxCount, count);
			prev = curr;
		}
	}

	return maxCount;
}

// time O(nlogn) space O(1)
int fractionalKnapsack(vector<std::pair<int, int>> items, int capacity) {
	// sort according to per unit cost
	std::sort(items.begin(), items.end(), [](const auto& a, const auto& b) {
		int cost_a = a.second / a.first;
		int cost_b = b.second / b.first;

		return cost_a > cost_b;
	});

	int result = 0;

	for (int i = 0; i < items.size() && capacity > 0; i++) {
		const auto &[weight, values] = items[i];

		if (capacity >= weight) {
			result += values;
			capacity -= weight;
		} else {
			// fractional part
			result += static_cast<int>(values
					* (static_cast<float>(capacity) / weight));
			capacity = 0;
		}
	}

	return result;
}

/* Find the optimal sequence of jobs to return the maximum profit
 * Rules:
 * * Each job takes one unit of time
 * * Only one job can be assigned at a time
 * * time starts with 0
 *
 * The vector jobs is a pair of deadline and profit.
 * Deadline is the time by which a job must finish
 */
int jobSequencing(std::vector<std::pair<int, int>> jobs) {
	// sort the jobs in increasing order of profits
	// O(nlogn)
	std::sort(jobs.begin(), jobs.end(), [](const auto& job1, const auto& job2) {
		auto &[deadline1, profit1] = job1;
		auto &[deadline2, profit2] = job2;

		return profit1 > profit2;
	});

	// O(n)
	int maxDeadline = std::accumulate(jobs.begin(), jobs.end(), 0,
			[](const auto& a, const auto& b) {
				return std::max(a, b.first);
			});

	int result = 0;

	// create slots upto maxDeadline
	// iterate over jobs, find an empty slot, add profit
	vector<bool> slotsAvailable(maxDeadline, true);

	// O(n^2)

	// TODO: use union-find or disjoint sets to reduce time complexity
	// for finding an empty slot
	// see https://www.geeksforgeeks.org/job-sequencing-using-disjoint-set-union/
	// and https://www.geeksforgeeks.org/union-find/
	for (int i = 0; i < jobs.size(); i++) {
		int desiredSlot = jobs[i].first - 1;
		for (int j = desiredSlot; j >= 0; j--) {
			if (slotsAvailable[j]) {
				slotsAvailable[j] = false;
				result += jobs[i].second;
				break;
			}
		}
	}

	return result;
}

/*
 * Huffman coding is a popular lossless compression technique
 * Lossless: decoding the encoded data results in the original data
 * There are some lossy compression algorithms as well which are used
 * for encoding videos.
 *
 * It is variable length encoding e.g. instead of using fixed 8-bits
 * to represent a character in ASCII, the length of encoding may vary
 *
 * Let say you have 100 characters long string abaabaca
 * Frequencies: a = 70, b = 20, c = 10
 *
 * Greedy (optimization): assign the smallest length code to the character
 * with maximum frequency. For e.g a occurs 70 times. If we assign 2-bit
 * code to represent a, that will optimize the space
 *
 * The important criteria for an encoding to be valid is that none of the
 * code should be a prefix of another code. E.g lets say 1 represents a and 11
 * represents b. Then if we encounter 111 during decompression, it could
 * be read as aaa or ab or ba.
 */
struct Huffman {
	int frequency;
	char code;

	Huffman(char c, int f) :
			code {c}, frequency {f} {
	}
};

std::shared_ptr<TreeNode<Huffman>> buildHuffmanTree(
		std::vector<std::pair<char, int>> frequency) {
	// sort according to increasing frequency
	std::sort(frequency.begin(), frequency.end(),
			[](const auto& a, const auto& b) {
				return a.second > b.second;
			});

	int total = std::accumulate(frequency.begin(), frequency.end(), 0,
			[](const int a, const auto b) {
				return a + b.second;
			});

	// TODO: study MinHeap to build the Huffman tree. Come back later

	return {};
}

#endif /* GREEDY_GREEDY_H_ */
