// Count Subarray sum Equals K
//--------------------------------------------------

/*
================================================================
Problem Statement: Given an array of integers and an integer k,
 return the total number of subarrays whose sum equals k.

A subarray is a contiguous non-empty sequence of elements within an array.
==================================================================

*/

/*
==========================================
Brute Force 
================================================

✅  Algorithm / Intuition:
Goal: Count the number of subarrays whose sum equals a given value k.

🔍 Intuition:
We want to check all possible subarrays and see how many of them have a sum equal to k.

This is done by:

Fixing a start index i.

Trying every possible end index j from i to n-1.

Calculating the sum of elements from i to j using another loop.

🧠 Steps:
Loop i = 0 to n-1 → this sets the starting index.

Loop j = i to n-1 → this sets the ending index.

Loop from i to j to calculate the sum of the subarray.

If sum == k, increase the count.

⚠️ Time Complexity:
O(n^3) — because:

2 loops for start and end index (O(n^2)), and

1 loop for calculating sum for each subarray (O(n)).

---------------------------------------------------------------------


#include <bits/stdc++.h>
using namespace std;

int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int n = arr.size(); // size of the given array.
    int cnt = 0; // Number of subarrays:

    for (int i = 0 ; i < n; i++) { // starting index i
        for (int j = i; j < n; j++) { // ending index j

            // calculate the sum of subarray [i...j]
            int sum = 0;
            for (int K = i; K <= j; K++)
                sum += arr[K];

            // Increase the count if sum == k:
            if (sum == k)
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    vector<int> arr = {3, 1, 2, 4};
    int k = 6;
    int cnt = findAllSubarraysWithGivenSum(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
}

    */

/*
===============================================================
Better Approach
====================================================================

✅ Summary of the Algorithm / Intuition (Optimized Subarray Sum to K):
🔍 Intuition:
To avoid using three nested loops, we carry forward the sum of the subarray while moving the j pointer.

This way, we only use two loops.

🧠 Steps:
Loop i = 0 to n-1 → this sets the start index of the subarray.

Initialize sum = 0 for each i.

Loop j = i to n-1 → this extends the subarray one element at a time.

At each step, update sum = sum + arr[j].

If sum == k, increment the count.

🧠 Key Observation:
Instead of recalculating the sum from scratch, reuse the previously computed sum and just add the next element:
sum(arr[i..j]) = sum(arr[i..j-1]) + arr[j]

⚙️ Time Complexity:
O(n^2) — much better than the previous O(n^3) approach.
-------------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int n = arr.size(); // size of the given array.
    int cnt = 0; // Number of subarrays:

    for (int i = 0 ; i < n; i++) { // starting index i
        int sum=0;
        for (int j = i; j < n; j++) { // ending index j

            sum+=arr[j];
                

            // Increase the count if sum == k:
            if (sum == k)
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    vector<int> arr = {3, 1, 2, 4};
    int k = 6;
    int cnt = findAllSubarraysWithGivenSum(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
}
---------------------------------------------------------------------------------
*/    
/*
================================================
Optimal Approach
===========================================================
✅ Summary: Optimized Subarray Sum using Prefix Sum + Hash Map
🔍 Intuition:
Instead of checking all subarrays, we use the prefix sum
 and a hash map to efficiently count subarrays with sum equal to k.

🧠 Key Observation:
If:

Current prefix sum at index i = x,

And we want to find a subarray ending at i with **sum = k`,

Then we need to find how many times prefix sum = x - k has occurred before.

Because:

If prefixSum[i] - prefixSum[j] == k,
=> prefixSum[j] == prefixSum[i] - k
This means the subarray [j+1 to i] has sum k.
===========================
⚙️ Approach:
Initialize prefixSum = 0 and map to store count of each prefix sum.

Iterate through the array:

Add current element to prefixSum.

If (prefixSum - k) exists in map, add its frequency to the count.

Store/update prefixSum in map.

Repeat for every index.
-----------------------------------------------
🧮 Why it works:
You're not directly looking for subarrays with sum = k.

Instead, you're checking how many prefixes existed such that removing them gives you sum k.

⏱️ Time Complexity:
O(n) — Much faster than O(n^2) or O(n^3).
*/

#include <bits/stdc++.h>
using namespace std;

int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int n = arr.size(); // size of the given array.
    map<int,int> mpp;
    int preSum = 0, cnt = 0;

    mpp[0] = 1; // Setting 0 in the map.

    for (int i = 0; i < n; i++) {
        // add current element to prefix Sum:
        preSum += arr[i];

        // Calculate x-k:
        int remove = preSum - k;

        // Add the number of subarrays to be removed:
        cnt += mpp[remove];

        // Update the count of prefix sum
        // in the map.
        mpp[preSum] += 1;
    }
    return cnt;
}

int main()
{
    vector<int> arr = {3, 1, 2, 4};
    int k = 6;
    int cnt = findAllSubarraysWithGivenSum(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
}


/*
✅ Summary: Why Initialize Prefix Sum Map with {0: 1}

🔍 Problem:
When checking for subarrays with sum = k using the prefix sum method, we calculate:
prefixSum - k
and look up its frequency in a map. But if this value is 0 and it hasn't been initialized,
 it might falsely indicate no valid subarray exists.




 ⚠️ Example:
For array: [3, -3, 1, 1, 1] and k = 3

At index 0: prefixSum = 3

Required: prefixSum - k = 0

But if map doesn’t contain 0, the answer will remain 0 
(i.e. no subarray found), which is incorrect, since [3] itself is a valid subarray.


✅ Solution:
Initialize the map as:

unordered_map<int, int> prefixSumCount;
prefixSumCount[0] = 1;

This means there's one subarray with sum = 0 before starting, which allows correctly counting subarrays starting from index 0.

🧠 Intuition:
It handles cases where the entire subarray from the start sums to k.
*/

