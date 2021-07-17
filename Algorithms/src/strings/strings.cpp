/*
 * strings.cpp
 *
 *  Created on: 29 Jun 2021
 *      Author: ykhan
 */

#include "strings.h"
#include <climits>

std::vector<std::pair<char, int>> frequencyOfCharactersLowercaseString(
		std::string s) {
	// there could be only 26 lower case characters
	std::vector<int> freq(26, 0);

	for (const auto &c : s) {
		int offset = c - 'a';
		freq[offset]++;
	}

	std::vector<std::pair<char, int>> result;
	for (int i = 0; i < freq.size(); i++) {
		if (freq[i] > 0) {
			result.push_back({'a' + i, freq[i]});
		}
	}

	return result;
}

bool isPalindrome(const std::string& s) {
	int left = 0;
	int right = s.length() - 1;

	while (left < right) {
		if (s[left] != s[right]) {
			return false;
		}
		left++;
		right--;
	}

	return true;
}

bool isSubsequence(const std::string& s1, const std::string& s2) {
	// pick the smaller of the two
	if (s1.length() < s2.length()) {
		return isSubsequence(s2, s1);
	}

	int matchIdx = 0;

	for (int i = 0; i < s1.length() && matchIdx < s2.length(); i++) {
		if (s1[i] == s2[matchIdx]) {
			matchIdx++;
		}
	}

	return matchIdx == s2.size();
}

// O(n)
std::pair<int, int> findSubstring(const std::string& s,
		const std::string& pattern) {
	// using sliding window method
	int start = -1;
	int end = -1;
	int matchIdx = 0;
	int matchLength = pattern.length();

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == pattern[matchIdx]) {
			if (start == -1) // first character matched
				start = i;

			matchIdx++;
		} else { // reset
			matchIdx = 0;
			start = -1;
		}

		if (start >= 0 && i - start + 1 == matchLength) {
			end = i;
			break;
		}
	}

	return {start, end};
}

// Time O(n) space O(1)
std::vector<int> findPatternDistinct(const std::string& text,
		const std::string& pattern) {
	std::vector<int> result;

	int m = pattern.length();
	int n = text.length();

	for (int i = 0; i <= n - m;) {
		int j;

		for (j = 0; j < m; j++) {
			if (text[i + j] != pattern[j]) {
				break;
			}
		}

		if (j == m) {
			result.push_back(i);
		}

		if (j == 0) {
			i++;
		} else {
			i += j;
		}
	}

	return result;
}

std::vector<int> findPatternNaive(const std::string& text,
		const std::string& pattern) {
	std::vector<int> result;

	int m = pattern.length();
	int n = text.length();

	// To search for pattern AA (m=2) in text AAAA (n=4)
	// We need to perform (n-m+1) comparisons i.e. AA AA AA
	for (int i = 0; i < n - m + 1; i++) {
		int j;
		for (j = 0; j < m; j++) {
			if (text[i + j] != pattern[j]) {
				break;
			}
		}

		if (j == m) {
			// match found
			result.push_back(i);
		}
	}

	return result;
}

bool isAnagram(const std::string& s1, const std::string& s2) {
	if (s1.length() != s2.length())
		return false;
	// To store 256 ASCII characters
	std::vector<int> freq(256, 0);

	for (int i = 0; i < s1.size(); i++) {
		freq[s1[i]]++;
		freq[s2[i]]--;
	}

	for (int i = 0; i < freq.size(); i++) {
		if (freq[i] != 0)
			return false;
	}

	return true;
}

int leftMostRepeating(const std::string& s) {
	// traverse string from the right
	// maintain the count of character or visited status
	// if count becomes greater than 1 or visited is true,
	// select as possible result
	std::vector<bool> visited(256, false);
	int result = -1;

	for (int i = s.length() - 1; i >= 0; i--) {
		if (visited[s[i]])
			result = i;
		else
			visited[s[i]] = true;
	}

	return result;
}

int leftMostNonRepeating(const std::string& s) {

	// status of the character
	// -1: not visited
	// -2: repeated
	// positive value: index
	int status[256];

	std::fill(status, status + 256, -1);

	for (int i = 0; i < s.length(); i++) {
		if (status[s[i]] == -1) {
			status[s[i]] = i;
		} else {
			status[s[i]] = -2;
		}
	}
	// pick the minium index
	int result = INT_MAX;
	for (int i = 0; i < 256; i++) {
		if (status[i] >= 0) {
			result = std::min(result, status[i]);
			break;
		}
	}

	return result == INT_MAX ? -1 : result;
}

void reverseString(std::string& s, int start, int end) {
	while (start < end) {
		std::swap(s[start], s[end]);
		start++;
		end--;
	}
}

std::string reverseWords(std::string s) {
	int idx = 0;

	reverseString(s, 0, s.length() - 1);

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			reverseString(s, idx, i - 1);
			idx = i + 1;
		}
	}

	if (idx < s.length()) {
		reverseString(s, idx, s.length() - 1);
	}

	return s;
}

std::vector<int> findPatternRabinCarp(const std::string& text,
		const std::string& pattern) {

	// This alogrithm maintains a rolling hash function and compares
	// the piece from text with a pattern only when its hash matches
	// the hash of the pattern
	// The simplest form of calculating hash is XOR but it is not
	// effective as two different strings but with repeated
	// characters e.g. aaaa & bbbbb will have the same hash
	// Another hash function of simply adding the ASCII values is
	// also not effective as all permutations of the pattern
	// will have same hash, e.g. for pattern abc, cba, cab both
	// will match. So a better hashing function is the weighted
	// sum of characters. Consider a weight factor d = 5, and pattern
	// length l = 4 for pattern abcd for text = acdabcd
	// the hash of first pattern length slice acda can be calculated as
	// h_0 = 5^3 * a + 5^2* c + 5^1 * d + a
	// To find the rolling hash for character i, we can use this formula
	// h_i = (h_i-1 - text[i-1]*d^(l-1)) + text[i]*d^(l-1)
	// e.g for above example
	// h_1 = h_0 - a * 5^3 + c * 5^3

	std::vector<int> result;
	int n = text.length();
	int m = pattern.length();

	int patternHash = 0;

	for (int i = 0; i < m; i++) {
		patternHash ^= pattern[i];
	}

	int hash = 0;

	for (int i = 0; i < n; i++) {
		if (i >= m) {
			// hash now contains items from 0 to m - 1
			if (hash == patternHash) {
				int j;
				for (j = 0; j < m; j++) {
					if (text[i - m + j] != pattern[j]) {
						break;
					}
				}
				if (j == m) {
					result.push_back(i - m);
				}
			}
			// remove the left most item
			hash ^= text[i - m];
		}

		hash ^= text[i];
	}

	if (hash == patternHash) {
		int j;
		for (j = 0; j < m; j++) {
			if (text[n - m + j] != pattern[j]) {
				break;
			}
		}
		if (j == m) {
			result.push_back(n - m);
		}
	}

	return result;
}
/*
 * Longest prefix which is also suffix without any overlap
 * Input : aabcdaabc
 * Output : 4
 * The string "aabc" is the longest
 * prefix which is also suffix.

 * Input : abcab
 * Output : 2

 * Input : aaaa
 * Output : 2
*/
// Time O(n/2) ~ O(n), space O(1)
int longestPrefixSuffix(std::string s) {
	// split the string in the middle, compare left and right parts
	int n = s.length();

	if (n < 2) {
		return -1; // need at least two chars to be both prefix/suffix
	}

	int i = n / 2;
	int len = 0; // length of the prefix/suffix

	while (i < n) {
		if (s[i] == s[len]) { // left part and right part index matches
			len++;
			i++;
		} else {
			// consider AAACAAAA
			// mistmach found, reset
			i = i - len + 1; // reduce the right part
			len = 0;
		}
	}

	return len;
}
