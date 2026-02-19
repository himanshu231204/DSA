// Minimise Maximum Distance between Gas Stations

/*
Problem Statement: You are given a sorted array ‘arr’ of length ‘n’, 
which contains positive integer positions of ‘n’ gas stations on the X-axis.
 You are also given an integer ‘k’. You have to place 'k' new gas stations on the X-axis. 
 You can place them anywhere on the non-negative side of the X-axis, even on non-integer positions.
  Let 'dist' be the maximum value of the distance between adjacent gas stations after adding k new gas stations.
Find the minimum value of ‘dist’.

Note: Answers within 10^-6 of the actual answer will be accepted.
 For example, if the actual answer is 0.65421678124, it is okay to return 0.654216.
  Our answer will be accepted if that is the same as the actual answer up to the 6th decimal place.
*/
//======================================================================================================================================================================
/*
# 🚗 Minimize Maximum Distance to Gas Stations – Summary

## 🧩 Problem Statement
You're given a **sorted array `arr`** of length `n` where each element represents the position of an existing gas station along the X-axis. You're also given an integer `k`, the number of **new gas stations** to add.

You can place the new stations **anywhere (even at non-integer positions)**. Your goal is to **minimize the maximum distance** between two adjacent gas stations after placing all `k` stations.

---

## ✅ Key Observations

1. **New stations should only be placed between existing ones.**
   - Placing them before the first or after the last gas station does **not** reduce the max gap.

2. **We are minimizing the "maximum" distance** → This is a **binary search on answers** pattern.

3. The problem accepts answers **within 1e-6** precision.

---

## 🧠 Three Main Approaches

### 1. Brute Force
- Try placing all `k` stations in each segment and keep track of the max gap.
- **Time Complexity:** Exponential, not feasible for large inputs.

---

### 2. Better Approach – Using Heap (Greedy + Priority Queue)
- Use a **Max Heap** to always split the segment with the current largest distance.
- Track how many new stations you place in each segment.
- Keep inserting new segment distances into the heap.

```cpp
new_dist = (arr[i+1] - arr[i]) / (howMany[i] + 1)


3. Optimal Approach – Binary Search on Answer (Decimals)
We search the space of possible values of dist (not index).

Range: [0, max distance between any two adjacent stations]

      modified binary search

      while(high - low > 1e-6):
    mid = (low + high) / 2
    if (stations_needed <= k):
        high = mid
    else:
        low = mid

numberOfGasStationsRequired(dist, arr)

stations_needed = (arr[i] - arr[i-1]) / dist
// If perfectly divisible, subtract 1 (no need to place at the boundary)


📈 Final Complexity
Time Complexity: O(n × log(len of answer space))

Space Complexity: O(1) (heap method takes O(n))

*/




#include <bits/stdc++.h>
using namespace std;

int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
    int n = arr.size(); // size of the array
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
        if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}

long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size(); // size of the array
    long double low = 0;
    long double high = 0;

    //Find the maximum distance:
    for (int i = 0; i < n - 1; i++) {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    //Apply Binary search:
    long double diff = 1e-6 ;
    while (high - low > diff) {
        long double mid = (low + high) / (2.0);
        int cnt = numberOfGasStationsRequired(mid, arr);
        if (cnt > k) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    return high;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    long double ans = minimiseMaxDistance(arr, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}


