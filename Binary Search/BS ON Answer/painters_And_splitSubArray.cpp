// Painters And split subarray problem

/*
🖌️ Painter’s Partition Problem — Summary
Goal:
You are given N boards, each with a certain length. There are K painters available. Each painter can paint only continuous boards, and 1 unit length takes 1 unit time.

Task:
Find the minimum time required to paint all boards by distributing the work among K painters, while respecting the continuity constraint.

Key Constraint:
A painter can’t skip boards — they must paint a block of boards that are next to each other.

Objective:
Minimize the maximum time taken by any single painter.
*/

/*
🔀 Split Array Largest Sum — Summary
Goal:
Given an array A of size N and an integer K, split the array into K non-empty contiguous subarrays.

Task:
Minimize the largest sum among all the K subarrays.

Key Constraints:

Subarrays must be continuous (no skipping elements).

Each subarray must be non-empty.

The objective is to balance the partition so no single subarray has a significantly large sum.

Objective:
Return the minimum possible value of the maximum subarray sum after the split.
*/

// These two problem is exactly same as book Allocation problems


/*
📝 Problem Summary: Book Allocation | Painter's Partition | Split Array Largest Sum

🔁 Common Pattern:
- Divide the array into K contiguous parts
- Minimize the maximum sum/time/pages in any part
- Use Binary Search on the answer


// ✅ Utility Function: Count how many partitions needed if limit is the max allowed sum

int countPartitions(vector<int> &arr, int limit) {
    int count = 1, sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (sum + arr[i] <= limit) {
            sum += arr[i]; // add to current partition
        } else {
            count++;        // start a new partition
            sum = arr[i];   // current element starts new partition
        }
    }
    return count;
}

// ✅ Main Solver Function for all 3 problems

int minimizeMaxSum(vector<int> &arr, int k) {
    int low = *max_element(arr.begin(), arr.end());      // lowest possible answer
    int high = accumulate(arr.begin(), arr.end(), 0);    // highest possible answer

    while (low <= high) {
        int mid = (low + high) / 2;
        int parts = countPartitions(arr, mid);

        if (parts > k) {
            low = mid + 1;   // too many partitions, increase limit
        } else {
            high = mid - 1;  // valid, but try for smaller maximum
        }
    }
    return low; // minimized largest sum/time/pages
}

/*
🧠 Mapping to Different Problems:

1. 📚 Book Allocation:
   - arr: pages of books
   - k: number of students
   - minimize max pages any student gets

2. 🖌️ Painter's Partition:
   - arr: lengths of boards
   - k: number of painters
   - minimize time taken (1 unit length = 1 unit time)

3. 🧮 Split Array Largest Sum:
   - arr: any array
   - k: number of subarrays
   - minimize max sum of any subarray

🟢 All solved using the same logic.
*/




#include <bits/stdc++.h>
using namespace std;

int countPartitions(vector<int> &a, int maxSum) {
    int n = a.size(); //size of array.
    int partitions = 1;
    long long subarraySum = 0;
    for (int i = 0; i < n; i++) {
        if (subarraySum + a[i] <= maxSum) {
            //insert element to current subarray
            subarraySum += a[i];
        }
        else {
            //insert element to next subarray
            partitions++;
            subarraySum = a[i];
        }
    }
    return partitions;
}

int largestSubarraySumMinimized(vector<int> &a, int k) {
    int low = *max_element(a.begin(), a.end());
    int high = accumulate(a.begin(), a.end(), 0);
    //Apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        int partitions = countPartitions(a, mid);
        if (partitions > k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    vector<int> a = {10, 20, 30, 40};
    int k = 2;
    int ans = largestSubarraySumMinimized(a, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}


