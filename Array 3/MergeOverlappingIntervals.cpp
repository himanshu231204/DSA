/*
=======================================================================
Problem Statement: Given an array of intervals, merge all the overlapping 
intervals and return an array of non-overlapping intervals.
==========================================================================

Example 1: 

Input: intervals=[[1,3],[2,6],[8,10],[15,18]]

Output: [[1,6],[8,10],[15,18]]

Explanation: Since intervals [1,3] and [2,6] are overlapping we can merge them to form [1,6]
 intervals.
*/


/*
=============================
Brute Force
===============================

🔍 Intuition for Merging Intervals

💡 Key Idea:
Sort all intervals based on their starting points.

Merge overlapping intervals by checking if one can be merged into another.

⚙️ How It Works:
Sort the intervals.

Use a loop to pick each interval.

Use another loop to compare it with the next intervals.

If they overlap, merge them into one.

✅ Goal:
Combine all overlapping intervals into larger non-overlapping ones.
--------------------------------------------------
### ✅ **Complexity Analysis Summary:**


✅ Complexity Analysis Summary:
Time Complexity:
O(N log N + 2N) ≈ O(N log N)

O(N log N) for sorting the intervals.

O(2N) for traversing all intervals (each visited at most twice: once for checking, once for merging).

Space Complexity:
O(N)

To store the merged intervals in the result list.

No extra space is used beyond that.
------------------------------

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
    int n = arr.size(); // size of the array

    //sort the given intervals:
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) { // select an interval:
        int start = arr[i][0];
        int end = arr[i][1];

        //Skip all the merged intervals:
        if (!ans.empty() && end <= ans.back()[1]) {
            continue;
        }

        //check the rest of the intervals:
        for (int j = i + 1; j < n; j++) {
            if (arr[j][0] <= end) {
                end = max(end, arr[j][1]);
            }
            else {
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = mergeOverlappingIntervals(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}

*/

/*
==========================
Optimal Solutions
============================

✅ Summary of the Intuition: One-Loop Interval Merging
Instead of using nested loops to compare and merge intervals, this approach uses a single loop to do the same:

Start traversing the sorted interval list.

Insert the first interval into the answer list.

For every subsequent interval:

If it overlaps with the last interval in the answer list 
(i.e., current start ≤ last end), merge them by updating
 the end to max(current end, last end).

If it doesn't overlap, just add it as a new interval to the answer list.

--------------------------------
✅ Complexity Analysis Summary:
Time Complexity:
O(N log N) + O(N)

Sorting the intervals: O(N log N)

Merging using a single loop: O(N)

Total: O(N log N)

Space Complexity:
O(N)

Due to the answer list storing merged intervals.

No extra space beyond the output list is used.
*/




#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
    int n = arr.size(); // size of the array

    //sort the given intervals:
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        // if the current interval does not
        // lie in the last interval:
        if (ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        }
        // if the current interval
        // lies in the last interval:
        else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = mergeOverlappingIntervals(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}



