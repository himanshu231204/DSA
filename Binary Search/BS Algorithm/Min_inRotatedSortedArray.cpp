/* Minimum in Rotated Sorted Array

Problem Statement: Given an integer array arr of size N,
 sorted in ascending order (with distinct values). 
 Now the array is rotated between 1 to N times which is unknown. 
 Find the minimum element in the array. 
*/

/*
=========================
Brute Force ( simple linaer search)
=============================
int findMin(vector<int>& arr) {
    int n = arr.size(); // size of the array.
    int mini = INT_MAX;
    for (int i = 0; i < n; i++) {
        // Always keep the minimum.
        mini = min(mini, arr[i]);
    }
    return mini;
}
*/

/*
====================
Optimal ( Binary Search)
=========================
/*
Rotated Sorted Array - Binary Search Approach

Key Observation:
- In a rotated and sorted array, at any index, one of the two halves is always sorted.

Approach:
1. Use Binary Search to identify the sorted half at each step.
2. Decide whether the target lies in the sorted half:
   - If yes, discard the other half.
   - If no, discard the sorted half.

Identifying the Sorted Half:
- If arr[low] <= arr[mid], then the left half is sorted.
- Else if arr[mid] <= arr[high], then the right half is sorted.

Finding the Minimum Element:
- The leftmost element in the sorted half is the smallest in that half.
- During each step:
   a. Track the leftmost element of the sorted half.
   b. Update the answer as: ans = min(ans, leftmost_element).
   c. Discard the sorted half and continue the search.

Note:
- If both halves are sorted (rare due to duplicates or perfect rotation), 
  we can choose either half to eliminate.
- The algorithm naturally handles such cases without special conditions.

Use Case:
- This logic is used to:
  1. Search for a target in a rotated sorted array.
  2. Find the minimum element in such an array efficiently.
*/



#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            // keep the minimum:
            ans = min(ans, arr[low]);

            // Eliminate left half:
            low = mid + 1;
        }
        else { //if right part is sorted:

            // keep the minimum:
            ans = min(ans, arr[mid]);

            // Eliminate right half:
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = findMin(arr);
    cout << "The minimum element is: " << ans << "\n";
    return 0;
}

