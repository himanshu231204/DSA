//Search Element in a Rotated Sorted Array

/*
Problem Statement: Given an integer array arr
 of size N, sorted in ascending order (with distinct values)
  and a target value k. Now the array is rotated at some pivot
   point unknown to you. Find the index at which k is present and
    if k is not present return -1.
*/

/*
===================
Brute Force
================

Do linaer search

int search(vector<int>& arr, int n, int k) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == k)
            return i;
    }
    return -1;
}
*/


/*
===============================
Optimal solutions
==============================

Using binary Search

🔍 Key Insight for Searching in a Rotated Sorted Array:

At any given index, one of the two halves is always sorted.

✅ Strategy:

Identify which half is sorted.

Check if the target lies within that sorted half:

If yes, search in that half.

If no, discard it and search in the other half.

This approach helps efficiently narrow down the search 
space using binary search, maintaining O(log n) complexity.
------------------------------


/*
🔁 Binary Search in Rotated Sorted Array – Summary Algorithm

1. Initialize Pointers:
   - low = 0, high = n - 1

2. Loop Until Found or Exhausted:
   - Compute mid = (low + high) // 2
   - If arr[mid] == target, return mid

3. Determine Sorted Half:
   - If left half is sorted (arr[low] <= arr[mid]):
       - If target lies in left half (arr[low] <= target <= arr[mid]):
           → search left: high = mid - 1
       - Else:
           → search right: low = mid + 1
   - Else (right half is sorted):
       - If target lies in right half (arr[mid] <= target <= arr[high]):
           → search right: low = mid + 1
       - Else:
           → search left: high = mid - 1

4. End Condition:
   - Loop continues until low > high
   - If not found, return -1
*/




#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& arr, int n, int k) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if mid points the target
        if (arr[mid] == k) return mid;

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) {
                //element exists:
                high = mid - 1;
            }
            else {
                //element does not exist:
                low = mid + 1;
            }
        }
        else { //if right part is sorted:
            if (arr[mid] <= k && k <= arr[high]) {
                //element exists:
                low = mid + 1;
            }
            else {
                //element does not exist:
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int n = 9, k = 1;
    int ans = search(arr, n, k);
    if (ans == -1)
        cout << "Target is not present.\n";
    else
        cout << "The index is: " << ans << "\n";
    return 0;
}


