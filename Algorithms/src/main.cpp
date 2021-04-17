
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstdint>

#include "arrays/arrays.h"
#include "bit-magic/bit-magic.h"
#include "hashing/hashing.h"
#include "mathematical/mathematical.h"
#include "matrix/matrix.h"
#include "recursion/recursion.h"
#include "searching/searching.h"
#include "sorting/sorting.h"

using namespace std;

template <typename T>
std::ostream& operator<<(std::ostream& os, vector<T> vec)
{
    ssize_t size = vec.size();
    
    os << "[";
    for (int i = 0; i < size; i++) {
        os << vec[i];
        if (i < size - 1)
            os << ", ";
    }
    
    os << "]" << endl;

    return os;
}

std::ostream& operator<<(std::ostream& os, std::pair<int, int> p)
{
    os << "(" << p.first << ", " << p.second << ")" << endl;
    return os;
}

int main() {
    cout << "Digit count in 9235 is " << count_digits(9235) << endl;
    cout << "Digit count in -9235 is " << count_digits(-9235) << endl;
    cout << "Is 78987 palindrome? " << is_palindrome(78987) << endl;
    cout << "Is 123 palindrome? " << is_palindrome(123) << endl;
    cout << "Factorial of 10 is " << factorial(10) << endl;
    cout << "Factorial of 0 is " << factorial(0) << endl;
    cout << "Trailing zeroes in factorial(100) is " << trailing_zeroes_in_factorial(100) << endl;
	cout << "GCD of 4 and 6 is " << find_gcd(4, 6) << endl;
	cout << "LCM of 4 and 6 is " << find_lcm(4, 6) << endl;
    
    for (int i = 1; i <= 100; i++) {
        cout << "Number " << i << (is_prime(i) == true ? " is prime" : " is composite") << endl;
    }
    
    vector<int> result = prime_factors(12);
    cout << "Prime factors of " << 12 << result;
    
    result = prime_factors(13);
    cout << "Prime factors of " << 13 << result;
    
    
    result = prime_factors(84);
    cout << "Prime factors of " << 84 << result;
    
    result = prime_factors(450);
    cout << "Prime factors of " << 450 << result;
    
    
    result = factors(15);
    cout << "Factors of " << 15 << result;
        
    result = factors(100);
    cout << "Factors of " << 100 << result;
    
    
    result = range_prime(10);
    cout << "Prime numbers upto " << 10 << result;

    result = range_prime(100);
    cout << "Prime numbers upto " << 100 << result;

    cout << "pow(2, 3) is " << pow(2, 3) << endl;
    cout << "pow(4, 2) is " << pow(4, 2) << endl;
    cout << "pow(4, 0) is " << pow(4, 0) << endl;
    cout << "pow(5, 1) is " << pow(5, 1) << endl;
    cout << "pow(3, 3) is " << pow(3, 3) << endl;
   
    cout << "Bit 1 of 5 is " << check_bit(5, 1) << endl;
    cout << "Bit 2 of 8 is " << check_bit(8, 2) << endl;
    try {
        cout << "Bit 33 of 0 is " << check_bit(0, 33) << endl;
    } catch (std::exception &e) {
        cout << e.what() << endl;
    }
    
    try {
        cout << "Bit 0 of 0 is " << check_bit(0, 0) << endl;
    } catch (std::exception &e) {
        cout << e.what() << endl;
    }
    
    cout << "Set bits in 5 is " << count_set_bits(5) << endl;
    cout << "Set bits in 7 is " << count_set_bits(7) << endl;
    cout << "Set bits in 13 is " << count_set_bits(13) << endl;
    cout << "Set bits in 0 is " << count_set_bits(0) << endl;
    cout << "4 is power of 2 " << isPow2(4) << endl;
    cout << "6 is power of 2 " << isPow2(6) << endl;
    cout << "0 is power of 2 " << isPow2(0) << endl;
    cout << "1 is power of 2 " << isPow2(1) << endl;
    
    vector<int> vec1 = {4, 3, 4, 4, 4, 5, 5};
    cout << "Odd occuring in " << vec1 << " is " << find_odd_occurring(vec1) << endl; 
    
    vector<int> vec2 = {8, 7, 7, 8, 8};
    cout << "Odd occuring in " << vec2 << " is " << find_odd_occurring(vec2) << endl; 
    
    vector<int> vec3 = {1, 4, 3};
    cout << "The missing number in " << vec3 << " is " << find_missing_number(vec3) << endl;
    
    vector<int> vec4 = {1, 5, 3, 2};
    cout << "The missing number in " << vec4 << " is " << find_missing_number(vec4) << endl;
    
    vector<int> vec5 = {3, 4, 3, 4, 5, 4, 4, 6, 7, 7};
    cout << "The two odd occuring numbers in " << vec5 << " are " << find_two_odd_occurring(vec5) << endl;
    
    vector<int> vec6 = {20, 14, 20, 16};
    cout << "The two odd occuring numbers in " << vec6 << " are " << find_two_odd_occurring(vec6) << endl;
    
    vector<int> vec7 = {20, 14, 20, 14};
    cout << "The two odd occuring numbers in " << vec7 << " are " << find_two_odd_occurring(vec7) << endl;
    
    std::string s1 = "abc";
    cout << "Powerset of " << s1 << " is " << create_powerset(s1) << endl;
    
    cout << "Print 1 to 16 is " << print_1_to_n(16) << endl;
    cout << "Print 16 to 1 is " << print_n_to_1(16) << endl;
    
    string s2 = "abbcbba";
    cout << "Is " << s2 << " palindrom: " << is_palindrome(s2) << endl;
    
    string s3 = "geeks";
    cout << "Is " << s3 << " palindrom: " << is_palindrome(s3) << endl;
    
    cout << "Recurssive factorial of 10 is " << factorial_rec(10) << endl;
    
    cout << "fibonacci(4) is " << fibonacci(4) << endl;
    cout << "fibonacci(0) is " << fibonacci(0) << endl;
    cout << "fibonacci(1) is " << fibonacci(1) << endl;
    
    cout << "Sum of first 2 natural numbers " << sum_natural_numbers(2) << endl;
    cout << "Sum of first 4 natural numbers " << sum_natural_numbers(4) << endl;
    cout << "Sum of first 5 natural numbers " << sum_natural_numbers(5) << endl;
    cout << "Sum of digits for 253: " << sum_digits(253) << endl;
    cout << "Sum of digits for 9987: " << sum_digits(9987) << endl;
    cout << "Sum of digits for 10: " << sum_digits(10) << endl;
    
    cout << "Rope len 5, sizes(2,5,1) : max slices: " << cut_rope(5, {2, 5, 1}) << endl;
    cout << "Rope len 23, sizes(12,9,11) : max slices: " << cut_rope(23, {12, 9, 11}) << endl;
    cout << "Rope len 5, sizes(4,2,6) : max slices: " << cut_rope(5, {4, 2, 6}) << endl;
    cout << "Rope len 9, sizes(2,2,2) : max slices: " << cut_rope(9, {2, 2, 2}) << endl;
    cout << "Generated subsets for ABC : " << generate_subsets("ABC") << endl;
 
    vector<string> v1 = {"", "a" , "b"};
    vector<string> v2 = {"c", "ab" , "bc"};
    v1.insert(v1.end(), v2.begin(), v2.end());
    
    cout << "testing vector concat " << v1 << endl;
    
    cout << "Tower hanoi move(1) " << endl;
    move(1, 'A', 'C', 'B');
    
    cout << "Tower hanoi move(2) " << endl;
    move(2, 'A', 'C', 'B');
    
    cout << "Tower hanoi move(3) " << endl;
    move(3, 'A', 'C', 'B');
    
    cout << "Tower hanoi move(4) " << endl;
    move(4, 'A', 'C', 'B');
    
    cout << "Josephus(7, 3)" << josephus(7, 3) << endl;
    
    vector<int> set1 = {1, 2, 3};
    int sum = 4;
    cout << "Subsets in set " << set1 << " with sum " << sum << " are " << subsets_with_sum(set1, sum) << endl;
    
    set1 = {10, 5, 2, 3, 6};
    sum = 8;
    cout << "Subsets in set " << set1 << " with sum " << sum << " are " << subsets_with_sum(set1, sum) << endl;
    
    set1 = {10, 20, 15};
    sum = 37;
    cout << "Subsets in set " << set1 << " with sum " << sum << " are " << subsets_with_sum(set1, sum) << endl;
    
    set1 = {10, 20, 15};
    sum = 0;
    cout << "Subsets in set " << set1 << " with sum " << sum << " are " << subsets_with_sum(set1, sum) << endl;
    
    string str1 = "ABC";
    cout << "Permutations for string " << str1 << " are " << permutations(str1) << endl;
    
    str1 = "AB";
    cout << "Permutations for string " << str1 << " are " << permutations(str1) << endl;
    
    str1 = "A";
    cout << "Permutations for string " << str1 << " are " << permutations(str1) << endl;
    
    str1 = "";
    cout << "Permutations for string " << str1 << " are " << permutations(str1) << endl;
    
    str1 = "ABCD";
    cout << "Permutations for string " << str1 << " are " << permutations(str1) << endl;
    
    vec1 = {10, 5, 8, 20};
    cout << "Vector " << vec1 << endl;
    cout << "The largest element: " << largest(vec1) << endl;
    cout << "The largest element index: " << largestIndex(vec1) << endl;
    cout << "The second largest element: " << secondLargest(vec1) << endl;
    cout << "The second largest element index: " << secondLargestIndex(vec1) << endl;
    
    
    vec1 = {20, 10 ,20, 8 , 12};
    cout << "Vector " << vec1 << endl;
    cout << "The largest element: " << largest(vec1) << endl;
    cout << "The largest element index: " << largestIndex(vec1) << endl;
    cout << "The second largest element: " << secondLargest(vec1) << endl;
    cout << "The second largest element index: " << secondLargestIndex(vec1) << endl;
    
    vec1 = {10, 10, 10};
    cout << "Vector " << vec1 << endl;
    cout << "The largest element: " << largest(vec1) << endl;
    cout << "The largest element index: " << largestIndex(vec1) << endl;
    cout << "The second largest element: " << secondLargest(vec1) << endl;
    cout << "The second largest element index: " << secondLargestIndex(vec1) << endl;
    
    vec1 = {10, 20, 30, 40, 50};
    cout << "Vector " << vec1 << endl;
    cout << "Sorted in ascending order? " << isSorted(vec1, true) << endl;
    cout << "Sorted in descending order? " << isSorted(vec1, false) << endl;
    
    vec1 = {50, 40, 30, 20, 10};
    cout << "Vector " << vec1 << endl;
    cout << "Sorted in ascending order? " << isSorted(vec1, true) << endl;
    cout << "Sorted in descending order? " << isSorted(vec1, false) << endl;
    
    
    vec1 = {50, 50, 50, 50, 50};
    cout << "Vector " << vec1 << endl;
    cout << "Sorted in ascending order? " << isSorted(vec1, true) << endl;
    cout << "Sorted in descending order? " << isSorted(vec1, false) << endl;
    
    vec1 = {1, 2, 3, 4, 5};
    cout << "Original vec " << vec1 << endl;
    cout << "Reversed vec " << reverse(vec1) << endl;
    
    vec1 = {1};
    cout << "Original vec " << vec1 << endl;
    cout << "Reversed vec " << reverse(vec1) << endl;
    
    vec1 = {1, 2, 3, 4, 5, 6};
    cout << "Original vec " << vec1 << endl;
    cout << "Reversed vec " << reverse(vec1) << endl;
    
    vec1 = {1, 2, 2, 3, 3, 3, 4, 5, 4, 4, 4, 5};
    cout << "Original vec " << vec1 << endl;
    cout << "After removing duplicates " << removeDuplicates(vec1) << endl;
    
    vec1 = {10, 20};
    cout << "Original vec " << vec1 << endl;
    cout << "Zeroes to end vec " << moveZeroesToEnd(vec1) << endl;
    
    vec1 = {0, 0, 0, 10, 0, 0, 20};
    cout << "Original vec " << vec1 << endl;
    cout << "Zeroes to end vec " << moveZeroesToEnd(vec1) << endl;

    vec1 = {0, 0, 0, 0};
    cout << "Original vec " << vec1 << endl;
    cout << "Zeroes to end vec " << moveZeroesToEnd(vec1) << endl;
    
    vec1 = {1, 2, 3, 4, 5};
    cout << "Original vec " << vec1 << endl;
    cout << "After left rotate by one, vec " << leftRotateByOne(vec1) << endl;
    
    try {
    
        vec1 = {1, 2, 3, 4, 5};
        cout << "Original vec " << vec1 << endl;
        cout << "After left rotate by 3 places, vec " << leftRotate(vec1, 3) << endl;
        
        vec1 = {1, 2, 3, 4, 5};
        cout << "Original vec " << vec1 << endl;
        cout << "After left rotate by 5 places, vec " << leftRotate(vec1, 5) << endl;
    
    
        vec1 = {1, 2, 3, 4, 5};
        cout << "Original vec " << vec1 << endl;
        cout << "After left rotate by 8 places, vec " << leftRotate(vec1, 8) << endl;
        
        vec1 = {1, 2, 3, 4, 5};
        cout << "Original vec " << vec1 << endl;
        cout << "After left rotate by 13 places, vec " << leftRotate(vec1, 13) << endl;
        
    } catch (std::exception &e) {
        cout << e.what() << endl;
    }
    
    cout << "1023 align 4 is " << align(1023, 4) << endl;
    cout << "1023 align 2 is " << align(1023, 2) << endl;
    cout << "1023 align 1024 is " << align(1023, 1024) << endl;
    

    cout << "4 align_pow2 2 is " << align_pow2(4, 2) << endl;
    cout << "1023 align_pow2 10 is " << align_pow2(1023, 10) << endl;
    cout << "11 align_pow2 2 is " << align_pow2(11, 2) << endl;
    
    vec1 = {7, 10 ,4, 3, 6, 5, 2};
    cout << "Leaders in " << vec1 << " are " << leaders(vec1) << endl;
    
    vec1 = {10, 20, 30};
    cout << "Leaders in " << vec1 << " are " << leaders(vec1) << endl;
    
    vec1 = {30, 20, 10};
    cout << "Leaders in " << vec1 << " are " << leaders(vec1) << endl;
    
    vec1 = {2, 3, 10, 6, 4, 8, 1};
    cout << "Max difference in " << vec1 << " is " << maxDifference(vec1) << endl;
    
    vec1 = {7, 9, 5, 6, 3, 2};
    cout << "Max difference in " << vec1 << " is " << maxDifference(vec1) << endl;
    
    vec1 = {10, 20 ,30};
    cout << "Max difference in " << vec1 << " is " << maxDifference(vec1) << endl;
    
    vec1 = {30, 10, 8, 2};
    cout << "Max difference in " << vec1 << " is " << maxDifference(vec1) << endl;
    
    vec1 = {10, 10, 10, 25, 30, 30};
    cout << "Frequencies in sorted array " << vec1 << frequenciesSorted(vec1) << endl;
    
    vec1 = {10, 10, 10, 10};
    cout << "Frequencies in sorted array " << vec1 << frequenciesSorted(vec1) << endl;
    
    vec1 = {10, 20, 30};
    cout << "Frequencies in sorted array " << vec1 << frequenciesSorted(vec1) << endl;
    
    vec1 = {10};
    cout << "Frequencies in sorted array " << vec1 << frequenciesSorted(vec1) << endl;
    
    vec1 = {1, 5, 3, 8, 12};
    cout << "Max profit in stocks " << vec1 << " is " << maxProfitStocks(vec1) << endl;
    
    vec1 = {2, 0, 2};
    cout << "Trapped water inside " << vec1 << " is " << trappedRainWater(vec1) << endl;
    
    vec1 = {3, 0, 1, 2, 5};
    cout << "Trapped water inside " << vec1 << " is " << trappedRainWater(vec1) << endl;
    
    vec1 = {1, 2, 3};
    cout << "Trapped water inside " << vec1 << " is " << trappedRainWater(vec1) << endl;
    
    vec1 = {3, 2, 1};
    cout << "Trapped water inside " << vec1 << " is " << trappedRainWater(vec1) << endl;
    
    vec1 = {5, 0, 6, 2, 3};
    cout << "Trapped water inside " << vec1 << " is " << trappedRainWater(vec1) << endl;
    
    vec1 = {0, 1, 1, 0, 1, 0};
    cout << "Max consecutive 1's in " << vec1 << " is " << maxConsecutiveOnes(vec1) << endl;
    
    vec1 = {1, 1, 1, 1};
    cout << "Max consecutive 1's in " << vec1 << " is " << maxConsecutiveOnes(vec1) << endl;
    
    vec1 = {0, 0, 0};
    cout << "Max consecutive 1's in " << vec1 << " is " << maxConsecutiveOnes(vec1) << endl;
    
    vec1 = {2, 3, -8, 7, -1, 2, 3};
    cout << "Max subarray sum " << vec1 << " is " << maxSubarraySum(vec1) << endl;
    
    vec1 = {5, 8, 3};
    cout << "Max subarray sum " << vec1 << " is " << maxSubarraySum(vec1) << endl;
    
    vec1 = {-6, -1, -8};
    cout << "Max subarray sum " << vec1 << " is " << maxSubarraySum(vec1) << endl;
    
    vec1 = {10, 12, 14, 7, 8};
    cout << "Max even-odd array in " << vec1 << " is " << maxEvenOddArray(vec1) << endl;
    
    vec1 = {7, 10, 13, 14};
    cout << "Max even-odd array in " << vec1 << " is " << maxEvenOddArray(vec1) << endl;
    
    vec1 = {10, 12, 8, 4};
    cout << "Max even-odd array in " << vec1 << " is " << maxEvenOddArray(vec1) << endl;
    
    vec1 = {10, 5, -5};
    cout << "Max circular subarray sum in " << vec1 << " is " << maxCircularSubarraySum(vec1) << endl;
    
    vec1 = {5, -2, 3, 4};
    cout << "Max circular subarray sum in " << vec1 << " is " << maxCircularSubarraySum(vec1) << endl;
    
    vec1 = {2, 3, -4};
    cout << "Max circular subarray sum in " << vec1 << " is " << maxCircularSubarraySum(vec1) << endl;
    
    vec1 = {8, -4, 3, -5, 4};
    cout << "Max circular subarray sum in " << vec1 << " is " << maxCircularSubarraySum(vec1) << endl;
    
    vec1 = {-3, 4, 6, -2};
    cout << "Max circular subarray sum in " << vec1 << " is " << maxCircularSubarraySum(vec1) << endl;
    
    vec1 = {-8, 7, 6};
    cout << "Max circular subarray sum in " << vec1 << " is " << maxCircularSubarraySum(vec1) << endl;
    
    vec1 = {3, -4, 5, 6, -8, 7};
    cout << "Max circular subarray sum in " << vec1 << " is " << maxCircularSubarraySum(vec1) << endl;
    
    vec1 = {8, 3, 4, 8, 8};
    cout << "Majority element in " << vec1 << " is " << findMajorityElement(vec1) << endl;
    
    vec1 = {3, 7, 4, 7, 7, 5};
    cout << "Majority element in " << vec1 << " is " << findMajorityElement(vec1) << endl;
    
    vec1 = {20, 30, 40, 50, 50, 50, 50};
    cout << "Majority element in " << vec1 << " is " << findMajorityElement(vec1) << endl;
   
    int k;
    
    vec1 = {1, 8, 30, -5, 20, 7};
    k = 3;
    cout << "Max sum of " << k << " elements in " << vec1 << " is " << maxSumKConsecutive(vec1, k) << endl;

    vec1 = {5, -10, 6, 90, 3};
    k = 2;
    cout << "Max sum of " << k << " elements in " << vec1 << " is "  << maxSumKConsecutive(vec1, k) << endl;

    int target;
    
    vec1 = {1, 4, 20, 3, 10, 5};
    target = 33;
    cout << vec1 << " contains sum " << target << " : " << std::boolalpha << subarrayWithSum(vec1, target) << endl;
 
    vec1 = {1, 4, 0, 0, 3, 10, 5};
    target = 7;
    cout << vec1 << " contains sum " << target << " : " << std::boolalpha << subarrayWithSum(vec1, target) << endl;
 
    vec1 = {2, 4};
    target = 3;
    cout << vec1 << " contains sum " << target << " : " << std::boolalpha << subarrayWithSum(vec1, target) << endl;
 
    cout << "First 8 3-bonnaci numbers " << computeKNBonnaci(3, 8) << endl;
    cout << "First 10 4-bonnaci numbers " << computeKNBonnaci(4, 10) << endl;
    
    vec1 = {1, 2, 1, 3, 4, 3, 3};
    cout << "Distinct elements in " << vec1 << " with window size 4 is " << distinctElementsWindowSizeK(vec1, 4) << endl;
    
    vec1 = {1, 1, 0, 0, 0, 1};
    cout << "Min group flips for " << vec1 << " are " << miniumGroupFlips(vec1) << endl;
    
    vec1 = {1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1};
    cout << "Min group flips for " << vec1 << " are " << miniumGroupFlips(vec1) << endl;
    
    vec1 = {1, 1, 1};
    cout << "Min group flips for " << vec1 << " are " << miniumGroupFlips(vec1) << endl;
    
    vec1 = {0, 1};
    cout << "Min group flips for " << vec1 << " are " << miniumGroupFlips(vec1) << endl;
    
    vec1 = {1, 0, 0, 1, 1, 0, 0, 0, 0};
    cout << "Min group flips for " << vec1 << " are " << miniumGroupFlips(vec1) << endl;
 
    vec1 = {2, 8, 3, 9, 6, 5, 4};
    cout << "Sum 0 to 2 in " << vec1 << " is " << getSum(vec1, 0, 2) << endl;
    cout << "Sum 1 to 3 in " << vec1 << " is " << getSum(vec1, 1, 3) << endl;
    cout << "Sum 2 to 6 in " << vec1 << " is " << getSum(vec1, 2, 6) << endl;
   
    vec1 = {3, 4, 8, -9, 20, 6};
    cout << "Equilibirium exists in " << vec1 << " ? " << std::boolalpha << equilibriumExisits(vec1) << endl;
   
    vec1 = {4, 2, -2};
    cout << "Equilibirium exists in " << vec1 << " ? " << std::boolalpha << equilibriumExisits(vec1) << endl;
   
    vec1 = {4, 2, 2};
    cout << "Equilibirium exists in " << vec1 << " ? " << std::boolalpha << equilibriumExisits(vec1) << endl;
   
    vector<int> left = {1, 2, 5, 15};
    vector<int> right = {5, 8, 7, 18};
    
    cout << "Max occuring in ranges " << left << right << " is " << maxOccuringInRanges(left, right) << endl;
    
    vec1 = {10, 20, 30, 40, 50, 60};
    int x = 20;
    cout << "Check whether " << x << " exists in " << vec1 << binarySearchIter(vec1, x) << endl;
    
    vec1 = {5, 15, 25};
    x = 25;
    cout << "Check whether " << x << " exists in " << vec1 << binarySearchIter(vec1, x) << endl;
    
    vec1 = {5, 10, 15, 25, 35};
    x = 20;
    cout << "Check whether " << x << " exists in " << vec1 << binarySearchIter(vec1, x) << endl;
    
    vec1 = {10, 10};
    x = 10;
    cout << "Check whether " << x << " exists in " << vec1 << binarySearchIter(vec1, x) << endl;
    
    vec1 = {10, 20, 30, 40, 50, 60};
    x = 20;
    cout << "Binary search recursive, check whether " << x << " exists in " << vec1 << binarySearchRec(vec1, x, 0, vec1.size() - 1) << endl;
    
    vec1 = {5, 15, 25};
    x = 25;
    cout << "Binary search recursive, check whether " << x << " exists in " << vec1 << binarySearchRec(vec1, x, 0, vec1.size() - 1) << endl;
    
    vec1 = {5, 10, 15, 25, 35};
    x = 20;
    cout << "Binary search recursive, check whether " << x << " exists in " << vec1 << binarySearchRec(vec1, x, 0, vec1.size() - 1) << endl;
    
    vec1 = {10, 10};
    x = 10;
    cout << "Binary search recursive, check whether " << x << " exists in " << vec1 << binarySearchRec(vec1, x, 0, vec1.size() - 1) << endl;
    
    vec1 = {1, 10, 10, 10, 20, 20, 40};
    x = 20;
    cout << "Find first occurence of " << x << " in " << vec1 << findIndexFirstOccurrence(vec1, x) << endl;
   
    vec1 = {10, 20, 30};
    x = 15;
    cout << "Find first occurence of " << x << " in " << vec1 << findIndexFirstOccurrence(vec1, x) << endl;
   
    vec1 = {15, 15, 15};
    x = 15;
    cout << "Find first occurence of " << x << " in " << vec1 << findIndexFirstOccurrence(vec1, x) << endl;
   
    vec1 = {10, 15, 20, 20, 40, 40};
    x = 20;
    cout << "Find last occurence of " << x << " in " << vec1 << findIndexLastOccurrence(vec1, x) << endl;
   
    vec1 = {5, 8, 8, 10, 10};
    x = 10;
    cout << "Find last occurence of " << x << " in " << vec1 << findIndexLastOccurrence(vec1, x) << endl;
   
    vec1 = {8, 10, 10, 12};
    x = 7;
    cout << "Find last occurence of " << x << " in " << vec1 << findIndexLastOccurrence(vec1, x) << endl;
   
    vec1 = {10, 10, 10, 10};
    x = 10;
    cout << "Find last occurence of " << x << " in " << vec1 << findIndexLastOccurrence(vec1, x) << endl;
   
    vec1 = {10};
    x = 10;
    cout << "Find last occurence of " << x << " in " << vec1 << findIndexLastOccurrence(vec1, x) << endl;
   
    vec1 = {10, 20, 20, 20, 30, 30};
    x = 20;
    cout << "Total occurences of " << x << " in " << vec1 << findTotalOccurrences(vec1, x) << endl;
    
    vec1 = {10, 10, 10, 10, 10};
    x = 10;
    cout << "Total occurences of " << x << " in " << vec1 << findTotalOccurrences(vec1, x) << endl;
    
    vec1 = {5, 8, 10};
    x = 7;
    cout << "Total occurences of " << x << " in " << vec1 << findTotalOccurrences(vec1, x) << endl;
    
    vec1 = {30};
    x = 30;
    cout << "Total occurences of " << x << " in " << vec1 << findTotalOccurrences(vec1, x) << endl;
    
    vec1 = {0, 0, 0, 1, 1, 1, 1};
    cout << "Count of ones in " << vec1 << " is " << countOnes(vec1) << endl;
    
    vec1 = {1, 1, 1, 1, 1};
    cout << "Count of ones in " << vec1 << " is " << countOnes(vec1) << endl;
    
    vec1 = {0, 0, 0, 0, 0};
    cout << "Count of ones in " << vec1 << " is " << countOnes(vec1) << endl;
    
    x = 4;
    cout << "Square root of " << x << " is " << squareRoot(x) << endl;
    
    x = 0;
    cout << "Square root of " << x << " is " << squareRoot(x) << endl;
    
    x = 1;
    cout << "Square root of " << x << " is " << squareRoot(x) << endl;
    
    x = 3;
    cout << "Square root of " << x << " is " << squareRoot(x) << endl;
    
    x = 5;
    cout << "Square root of " << x << " is " << squareRoot(x) << endl;
    
    x = 9;
    cout << "Square root of " << x << " is " << squareRoot(x) << endl;
    
    x = 25;
    cout << "Square root of " << x << " is " << squareRoot(x) << endl;
    
    x = 14;
    cout << "Square root of " << x << " is " << squareRoot(x) << endl;
    
    vec1 = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    x = 4;
    cout << "Index of " << x << " in " << vec1 << " using unbounded binary search: " << findIndexInfiniteArray(vec1, x) << endl;
    
    vec1 = {1, 2, 3, 4, 5, 6, 7, 100};
    x = 100;
    cout << "Index of " << x << " in " << vec1 << " using unbounded binary search: " << findIndexInfiniteArray(vec1, x) << endl;
    
    vec1 = {2, 3, 4, 5, 6, 7, 100};
    x = 1;
    cout << "Index of " << x << " in " << vec1 << " using unbounded binary search: " << findIndexInfiniteArray(vec1, x) << endl;
   
    vec1 = {500, 400, 300, 200, 100};
    x = 500;
    cout << "Index of " << x << " in " << vec1 << " is " << findIndexSortedRotatedArray(vec1, x) << endl;
   
    vec1 = {10, 20, 30, 40, 50, 8, 9};
    x = 30;
    cout << "Index of " << x << " in " << vec1 << " is " << findIndexSortedRotatedArray(vec1, x) << endl;
    
    vec1 = {100, 200, 300, 10, 20};
    x = 40;
    cout << "Index of " << x << " in " << vec1 << " is " << findIndexSortedRotatedArray(vec1, x) << endl;
    
    
    vec1 = {500, 400, 300, 200, 500};
    x = 500;
    cout << "Index of " << x << " in " << vec1 << " is " << findIndexSortedRotatedArray(vec1, x) << endl;
    
    vec1 = {5, 10, 20, 15, 7};
    cout << "Peak element in " << vec1 << " is " << findPeakElement(vec1) << endl;
    
    vec1 = {10, 20, 15, 23, 90, 67};
    cout << "Peak element in " << vec1 << " is " << findPeakElement(vec1) << endl;
    
    vec1 = {80, 70, 60};
    cout << "Peak element in " << vec1 << " is " << findPeakElement(vec1) << endl;
    
    vec1 = {10};
    cout << "Peak element in " << vec1 << " is " << findPeakElement(vec1) << endl;
    
    vec1 = {2, 5, 8, 12, 30};
    x = 17;
    cout << "Pair for sum " << x << " in " << vec1 << " is " << findPairWithSum(vec1, x) << endl;
    
    vec1 = {3, 8, 13, 18};
    x = 14;
    cout << "Pair for sum " << x << " in " << vec1 << " is " << findPairWithSum(vec1, x) << endl;
    
    vec1 = {1, 2, 3, 4, 5};
    x = 9;
    cout << "Triplet with sum " << x << " in " << vec1 << " is " << findTripletWithSum(vec1, x) << endl;
    
    vec1 = {2, 3, 4, 8, 9, 20, 40};
    x = 32;
    cout << "Triplet with sum " << x << " in " << vec1 << " is " << findTripletWithSum(vec1, x) << endl;
    
    vec1 = {10, 20, 30, 40, 50};
    vec2 = {5, 15, 25, 35, 45};
    cout << "Median of two sorted arrays: " << vec1 << " and " << vec2 << " is " << findMedianTwoSortedArrays(vec1, vec2) << endl;
    
    vec1 = {1, 2, 3, 4, 5, 6};
    vec2 = {10, 20, 30, 40, 50};
    cout << "Median of two sorted arrays: " << vec1 << " and " << vec2 << " is " << findMedianTwoSortedArrays(vec1, vec2) << endl;
    
    vec1 = {0, 1, 2, 3, 4, 4};
    cout << "The repeating element in " << vec1 << " is " << findRepeatingElement(vec1) << endl;
    
    int arr[] = {5, 4, 3, 2, 1};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: " << endl;
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << endl;
    }
    
    sortArraySTL(arr, arrSize);
    
    cout << "Array after sorting: " << endl;
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << endl;
    }
    
    auto decreasing = [](int a, int b) {
        return a > b;
    };
    sortArraySTL(arr, arrSize, decreasing);
    
    cout << "Array after sorting to descending order: " << endl;
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << endl;
    }
    
    vec1 = {2, 10, 8, 7};
    cout << "Original array : " << vec1 << ", bubble sorted: " << bubbleSort(vec1) << endl;
    
    vec1 = {10, 5, 8, 20, 2, 18};
    cout << "Original array : " << vec1 << ", selection sorted: " << selectionSort(vec1) << endl;
    
    vec1 = {5, 4, 3, 2, 1};
    cout << "Original array: " << vec1 << ", insertion sorted: " << insertionSort(vec1) << endl;
    
    vec1 = {10, 15, 20, 11, 30};
    cout << "Original array: " << vec1 << ", merged: " << merge(vec1, 0, 2, 4) << endl;
    
    vec1 = {5, 4, 3, 2, 1};
    cout << "Original array: " << vec1 << ", merge sorted: " << mergeSort(vec1) << endl;

    vec1 = {3, 5, 10, 10, 10, 15, 15, 20};
    vec2 = {5, 10, 10, 15, 30};
    cout << "Intersection of vectors " << vec1 << " and " << vec2 << " is " << interSectionSortedArrays(vec1, vec2) << endl;
    
    vec1 = {1, 1, 3, 3, 3};
    vec2 = {1, 1, 1, 1, 3, 5, 7};
    cout << "Intersection of vectors " << vec1 << " and " << vec2 << " is " << interSectionSortedArrays(vec1, vec2) << endl;
    
    vec1 = {3, 5, 8};
    vec2 = {2, 8, 9, 10, 15};
    cout << "Union of vectors " << vec1 << " and " << vec2 << " is " << unionSortedArrays(vec1, vec2) << endl;
    
    vec1 = {2, 3, 3, 3, 4, 4};
    vec2 = {4, 4};
    cout << "Union of vectors " << vec1 << " and " << vec2 << " is " << unionSortedArrays(vec1, vec2) << endl;

    vec1 = {2, 4, 1, 3, 5};
    cout << "Original array: " << vec1 << ", count inversions: " << countInversions(vec1) << endl;

    vec1 = {40, 30, 20, 10};
    cout << "Original array: " << vec1 << ", count inversions: " << countInversions(vec1) << endl;

    vec1 = {10, 20, 30, 40};
    cout << "Original array: " << vec1 << ", count inversions: " << countInversions(vec1) << endl;

    vec1 = {3, 8, 6, 12, 10, 7};
    cout << "Original array: " << vec1 << ", qsort using lomuto partitioning: ";
    qSortLomuto(vec1, 0, vec1.size() - 1);
    cout << vec1 << endl;
   
    vec1 = {3, 8, 6, 12, 10, 7};
    cout << "Original array: " << vec1 << ", qsort using hoare partitioning: ";
    qSortHoare(vec1, 0, vec1.size() - 1);
    cout << vec1 << endl;
   
    vector<vector<int>> matrix;
    
    for (int i = 0; i < 4; i++) {
        vector<int> row;
        for (int j = 0; j < 4; j++) {
            row.push_back(j + 1 + i * 4);
        }
        matrix.push_back(row);
    }
   
    printMatrix(matrix);
    printMatrixSpiral(matrix);
    printMatrixSnakePattern(matrix);
    printMatrixBorder(matrix);
    printMatrix(transposeMatrix(matrix));
    printMatrix(rotateMatrix90((matrix)));
   
    matrix = {
        {1, 2, 3, 4}
    };
    
    printMatrix(matrix);
    printMatrixSpiral(matrix);
    printMatrixSnakePattern(matrix);
    printMatrixBorder(matrix);
    printMatrix(transposeMatrix(matrix));
   
    matrix = {
        {1},
        {2},
        {3}
    };
    
    printMatrix(matrix);
    printMatrixSpiral(matrix);
    printMatrixSnakePattern(matrix);
    printMatrixBorder(matrix);
    printMatrix(transposeMatrix(matrix));
   
    matrix = {
        {1, 2},
        {3, 4},
        {5, 6}
    };
    
    printMatrix(matrix);
    printMatrixSpiral(matrix);
    printMatrixSnakePattern(matrix);
    printMatrixBorder(matrix);
    printMatrix(transposeMatrix(matrix));
   
    DirectAddressTable dat{100, 199};
    
    dat.insert(101);
    dat.insert(199);
    
    cout << dat.search(101) << " " << dat.search(199) << " " << dat.search(100) << endl;
    dat.remove(199);
    cout << dat.search(101) << " " << dat.search(199) << " " << dat.search(100) << endl;
    {
    HashTableChaining hashTbl{7};
    
    hashTbl.insert(70);
    hashTbl.insert(70);
    hashTbl.insert(71);
    hashTbl.insert(9);
    hashTbl.insert(56);
    hashTbl.insert(72);
    
    cout << "Searching for 56: " << hashTbl.search(56) << endl;
    cout << "Searching for 57: " << hashTbl.search(57) << endl;
    cout << "Searching for 70: " << hashTbl.search(70) << endl;
    hashTbl.remove(70);
    cout << "Searching for 70: " << hashTbl.search(70) << endl;
    }

    HashTableOpenAddressingLinearProbing<int> hashTblLinear{7};

    hashTblLinear.insert(48);
    hashTblLinear.insert(42);
    hashTblLinear.insert(50);
    hashTblLinear.insert(55);
    hashTblLinear.insert(53);

    cout << "Searching for 48: " << hashTblLinear.search(48) << endl;
    cout << "Searching for 42: " << hashTblLinear.search(42) << endl;
    cout << "Searching for 50: " << hashTblLinear.search(50) << endl;
    cout << "Searching for 55: " << hashTblLinear.search(55) << endl;
    hashTblLinear.remove(55);
    cout << "Searching for 55: " << hashTblLinear.search(55) << endl;

    getchar();
	return 0;
}