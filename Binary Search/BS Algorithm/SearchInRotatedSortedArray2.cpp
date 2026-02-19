//Search Element in Rotated Sorted Array II( may contain duplicate values)


/*
===================
Brute Force
================

Do linaer search

bool searchInARotatedSortedArrayII(vector<int>&arr, int k) {
    int n = arr.size(); // size of the array.
    for (int i = 0; i < n; i++) {
        if (arr[i] == k) return true;
    }
    return false;
}
*/
/*
===============================
Optimal solutions
==============================

Using binary Search
---------------------

/*
🔁 Binary Search in Rotated Sorted Array with Duplicates – Summary

1. Initialize Pointers:
   - low = 0, high = n - 1

2. Loop Until Found or Exhausted:
   - Compute mid = (low + high) // 2
   - If arr[mid] == target, return mid

3. Handle Duplicates Edge Case:
   - If arr[low] == arr[mid] == arr[high]:
       → Increment low and decrement high (low++, high--)
       → Skip sorted half checks until this condition is broken

4. Determine Sorted Half:
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

5. End Condition:
   - Loop continues until low > high
   - If not found, return -1
*/


#include <bits/stdc++.h>
using namespace std;

bool searchInARotatedSortedArrayII(vector<int>&arr, int k) {
    int n = arr.size(); // size of the array.
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if mid points the target
        if (arr[mid] == k) return true;

        //Edge case:
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low = low + 1;
            high = high - 1;
            continue;
        }

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
    return false;
}

int main()
{
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int k = 3;
    bool ans = searchInARotatedSortedArrayII(arr, k);
    if (!ans)
        cout << "Target is not present.\n";
    else
        cout << "Target is present in the array.\n";
    return 0;
}

