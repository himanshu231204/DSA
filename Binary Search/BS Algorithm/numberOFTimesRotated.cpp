//Find out how many times the array has been rotated

/*
Problem Statement: Given an integer array arr of size N,
 sorted in ascending order (with distinct values). Now the
  array is rotated between 1 to N times which is unknown.
   Find how many times the array has been rotated
*/

/*
============
Brute Force
========



#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &arr) {
    int n = arr.size(); //size of array.
    int ans = INT_MAX, index = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] < ans) {
            ans = arr[i];
            index = i;
        }
    }
    return index;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = findKRotation(arr);
    cout << "The array is rotated " << ans << " times.\n";
    return 0;
}



*/

/*
================
Optimal Solutions(using Binary Search)
===============
/*
    🔄 Find Minimum in Rotated Sorted Array (With Duplicates)

    ✅ Approach: Binary Search with Duplicate Handling

    Step 1: Initialize
    ------------------
    int ans = INT_MAX;      // To store minimum value
    int index = -1;         // To store index of the minimum
    int low = 0;
    int high = n - 1;

    Step 2: Binary Search Loop
    --------------------------
    while (low <= high) {
        int mid = (low + high) / 2;

        Case 1: Fully Sorted Segment
        ----------------------------
        if (arr[low] <= arr[high]) {
            // Array is fully sorted from low to high
            // arr[low] is the minimum
            if (arr[low] < ans) {
                ans = arr[low];
                index = low;
            }
            break;
        }

        Case 2: Left Half Sorted
        ------------------------
        if (arr[low] <= arr[mid]) {
            // Left part is sorted
            if (arr[low] < ans) {
                ans = arr[low];
                index = low;
            }
            // Eliminate the left half
            low = mid + 1;
        }

        Case 3: Right Half Sorted
        -------------------------
        else {
            // Right part is sorted
            if (arr[mid] < ans) {
                ans = arr[mid];
                index = mid;
            }
            // Eliminate the right half
            high = mid - 1;
        }
    }

    Step 3: Return Result
    ---------------------
    return index;   // Index of minimum element
*/






#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        //search space is already sorted
        //then arr[low] will always be
        //the minimum in that search space:
        if (arr[low] <= arr[high]) {
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }
            break;
        }

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            // keep the minimum:
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }

            // Eliminate left half:
            low = mid + 1;
        }
        else { //if right part is sorted:

            // keep the minimum:
            if (arr[mid] < ans) {
                index = mid;
                ans = arr[mid];
            }

            // Eliminate right half:
            high = mid - 1;
        }
    }
    return index;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = findKRotation(arr);
    cout << "The array is rotated " << ans << " times.\n";
    return 0;
}

