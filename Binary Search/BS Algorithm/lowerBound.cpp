/* 🧠 Algorithm (Pseudo Code):
  
function lowerBound(arr, x):
    low = 0
    high = length(arr) - 1
    ans = length(arr)  // default if x is greater than all elements

    while low <= high:
        mid = low + (high - low) // 2

        if arr[mid] >= x:
            ans = mid        // potential answer, but check left
            high = mid - 1
        else:
            low = mid + 1

    return ans
---------------------
TC=O(logN)
SC=O(1)



*/
#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {3, 5, 8, 15, 19};
    int n = 5, x = 9;
    int ind = lowerBound(arr, n, x);
    cout << "The lower bound is the index: " << ind << "\n";
    return 0;
}

