/*
🧠 Algorithm (Steps):
Set low = 0, high = n - 1.

While low <= high:

mid = (low + high) / 2

If arr[mid] == target → return mid

If arr[mid] < target → search in right half (low = mid + 1)

Else → search in left half (high = mid - 1)

If not found → return -1


*/

/*
       Algorithms:


       int binarySearch(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array

    int low = 0, high = n - 1;

    // Perform the steps:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) return mid;
        else if (target > nums[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}





*/

// 
#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    int low = 0, high = n - 1;

    // Perform the steps:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) return mid;
        else if (target > nums[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;
    int ind = binarySearch(a, target);
    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: "
                  << ind << endl;
    return 0;
}


