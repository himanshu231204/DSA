// Peak Elements in array

/*
Problem Statement: Given an array of length N.
 Peak element is defined as the element greater 
 than both of its neighbors. Formally, if 'arr[i]' is
  the peak element, 'arr[i - 1]' < 'arr[i]' and 'arr[i + 1]' < 'arr[i]'. 
  Find the index(0-based) of a peak element in the array. If there are multiple peak numbers,
   return the index of any peak number.
*/
/*
// ✅ Algorithm to Find Peak Element (LeetCode 162)
// Time Complexity: O(log n) - Binary Search Approach
// Space Complexity: O(1)

1. // Handle edge cases before entering Binary Search:
   - If the array has only one element → return index 0.
   - If the first element is greater than the second → return index 0.
   - If the last element is greater than the second last → return index n - 1.

2. // Initialize binary search boundaries:
   int low = 1;
   int high = n - 2;

3. // Binary Search Loop:
   while (low <= high):
       int mid = (low + high) / 2;

       // Check if mid is a peak:
       if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]):
           return mid;

       // If ascending slope → move right (peak lies ahead)
       else if (nums[mid] > nums[mid - 1]):
           low = mid + 1;

       // Else move left (descending slope or valley)
       else:
           high = mid - 1;
*/



#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &arr) {
    int n = arr.size(); //Size of array.

    // Edge cases:
    if (n == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[n - 1] > arr[n - 2]) return n - 1;

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;

        //If arr[mid] is the peak:
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            return mid;

        // If we are in the left:
        if (arr[mid] > arr[mid - 1]) low = mid + 1;

        // If we are in the right:
        // Or, arr[mid] is a common point:
        else high = mid - 1;
    }
    // Dummy return statement
    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int ans = findPeakElement(arr);
    cout << "The peak is at index: " << ans << "\n";
    return 0;
}

