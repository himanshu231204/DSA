/*
Length of the longest subarray with zero Sum

Problem Statement: Given an array containing both positive and negative integers,
 we have to find the length of the longest subarray with the sum of all elements equal to zero.
*/

/*
================================
Brute Forec
===============================
🔍 Intuition:
Goal: Find the longest subarray whose elements sum up to zero.

Basic idea: Check all possible subarrays and track the maximum length among those that have a sum of zero.

🧠 Approach (Brute-force):
Initialize max = 0 to store the length of the longest valid subarray.

Outer loop: Iterate through the array with index i.

Set sum = 0 at the start of each new subarray.

Inner loop: From index j = i to end of array:

Add arr[j] to sum.

If sum == 0, check the subarray length (j - i + 1):

If this length is greater than max, update max.

After checking all subarrays, return max.
------------------------------------------
Complexity Analysis

Time Complexity: O(N^2) as we have two loops for traversal

Space Complexity: O(1) as we aren’t using any extra space.
*/



#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& a) {
    int maxLen = 0;
    unordered_map<int, int> sumIndexMap;
    int sum = 0;

    for (int i = 0; i < a.size(); i++) {
        sum += a[i];

        if (sum == 0) {
            maxLen = i + 1;
        } else if (sumIndexMap.find(sum) != sumIndexMap.end()) {
            maxLen = max(maxLen, i - sumIndexMap[sum]);
        } else {
            sumIndexMap[sum] = i;
        }
    }

    return maxLen;
}

int main() {
    vector<int> a = {9, -3, 3, -1, 6, -5};
    cout << solve(a) << endl;

    return 0;
}


