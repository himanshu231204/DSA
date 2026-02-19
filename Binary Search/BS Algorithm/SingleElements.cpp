//Search Single Element in a sorted array

//Problem Statement: Given an array of N integers. Every number in the array except one appears twice. Find the single number in the array.

/*
==================
Optimal Solutions  (Binary Search)
================

🔍 Key Idea:
Use Binary Search to efficiently find the single element in O(log n) time.

✅ Edge Case Checks (Before Binary Search):
If n == 1: Return arr[0].

If arr[0] != arr[1]: Return arr[0].

If arr[n-1] != arr[n-2]: Return arr[n-1].

📌 Binary Search Setup:
Set low = 1, high = n - 2 (excluding already-checked edge elements).

🧠 Check if mid is the Single Element:
If arr[mid] != arr[mid - 1] and arr[mid] != arr[mid + 1], return arr[mid].

📚 Determine Which Half to Search:
🔹 Left Half Pattern: (even, odd)
If:

mid % 2 == 0 && arr[mid] == arr[mid+1] or

mid % 2 == 1 && arr[mid] == arr[mid-1]
→ We're in the left half, move to right: low = mid + 1

🔹 Right Half Pattern: (odd, even)
Else → We're in the right half, move to left: high = mid - 1


*/




#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& arr) {
    int n = arr.size(); //size of the array.

    //Edge cases:
    if (n == 1) return arr[0];
    if (arr[0] != arr[1]) return arr[0];
    if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if arr[mid] is the single element:
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
            return arr[mid];
        }

        //we are in the left:
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1])
                || (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
            //eliminate the left half:
            low = mid + 1;
        }
        //we are in the right:
        else {
            //eliminate the right half:
            high = mid - 1;
        }
    }

    // dummy return statement:
    return -1;
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int ans = singleNonDuplicate(arr);
    cout << "The single element is: " << ans << "\n";
    return 0;
}

