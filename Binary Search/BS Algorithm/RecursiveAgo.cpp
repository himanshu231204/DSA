/*🔁 Recursive Binary Search – Pseudocode
  

     function binarySearchRecursive(arr, low, high, target):
    if low > high:
        return -1  // base case: target not found

    mid = (low + high) // 2

    if arr[mid] == target:
        return mid

    else if arr[mid] < target:
        return binarySearchRecursive(arr, mid + 1, high, target)

    else:
        return binarySearchRecursive(arr, low, mid - 1, target)

*/


#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& nums, int low, int high, int target) {

    if (low > high) return -1; //Base case.

    // Perform the steps:
    int mid = (low + high) / 2;
    if (nums[mid] == target) return mid;
    else if (target > nums[mid])
        return binarySearch(nums, mid + 1, high, target);
    return binarySearch(nums, low, mid - 1, target);
}

int search(vector<int>& nums, int target) {
    return binarySearch(nums, 0, nums.size() - 1, target);
}

int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;
    int ind = search(a, target);
    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: "
                  << ind << endl;
    return 0;
}

