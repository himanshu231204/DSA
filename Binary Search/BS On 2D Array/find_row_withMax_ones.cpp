// Find the row with maximum number of 1's

/*
🔍 Problem Summary:
You're given a non-empty 2D grid mat of size n x m, where:

Each element is either 0 or 1

Each row is sorted in ascending order (all 0s come before 1s)

🎯 Goal:
Find the index of the row that has the maximum number of 1s.

📌 Conditions:

If two rows have the same number of 1s → return the row with the smaller index

If no row contains any 1, return -1


*/


/*
================
Brute Force
=================
1. go in each row
2. find sum of each row
3. retur the index of max row sum


#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int index = 0;
        int max_count = 0;

        for (int i = 0, n = mat.size(); i < n; i++) {
            int count = accumulate(mat[i].begin(), mat[i].end(), 0);
            if (count > max_count) {
                index = i;
                max_count = count;
            }
        }

        return {index, max_count};
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {{0, 1}, {1, 0}};
    vector<int> result = sol.rowAndMaximumOnes(mat);

    cout << "Row Index: " << result[0] << ", Max 1s: " << result[1] << endl;
    return 0;
}
*/


/*
=====================================
Optimal  solutions ( Binary search)
=============================================

🔹 Goal:
  Find the row with the maximum number of 1s in a binary matrix (each row is sorted in ascending order).

🔹 Why Binary Search?
  - Binary Search helps eliminate half of the search space efficiently.
  - We can't optimize row traversal, but we can optimize the 1's counting in each row.

🔹 Optimization:
  - Instead of counting 1s directly, we compute:
      Number_of_ones = m - (first occurrence of 1)
        → where `m` = number of columns.

🔹 How to find the first occurrence of 1?
  Since each row is sorted (0s followed by 1s), we can use:
    ✅ lower_bound(1)         // Preferred here
    ✅ upper_bound(0)
    ✅ firstOccurrence(1)

🔹 Benefits:
  - Reduces time complexity from O(n * m) to O(n * log m)
  - Uses properties of sorted arrays for efficient search

*/
#include <iostream>
#include <vector>
#include <algorithm> // for lower_bound
using namespace std;

int rowWithMax1s(vector<vector<int>> &arr) {
    int n = arr.size();          // number of rows
    int m = arr[0].size();       // number of columns

    int cntmax = 0;
    int index = -1;

    for (int i = 0; i < n; i++) {
        // Use lower_bound to find first occurrence of 1 in the row
        int pos = lower_bound(arr[i].begin(), arr[i].end(), 1) - arr[i].begin();
        int cnt_ones = m - pos;

        if (cnt_ones > cntmax) {
            cntmax = cnt_ones;
            index = i;
        }
    }

    return index;
}

int main() {
    vector<vector<int>> matrix = {
        {0, 0, 0, 1},
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {0, 0, 0, 0}
    };

    int result = rowWithMax1s(matrix);
    cout << "Row with maximum 1's: " << result << endl;

    return 0;
}
