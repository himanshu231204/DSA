//Search in a sorted 2D matrix

/*
Problem Statement: You have been given a 2-D array 'mat' of size 'N x M' where 'N' and 'M' denote the number of rows and columns,
 respectively. The elements of each row are sorted in non-decreasing order. Moreover, the first element of a row is greater than the last 
 element of the previous row (if it exists). You are given an integer ‘target’, and your task is to find if it exists in the given 'mat' or not.
*/

/*
==========================
Brute Force( )
=================================
Intuition:
Check every element one by one to see if it matches the target.

🔁 Algorithm Steps:
Loop through each row using index i.

For every row, loop through each column using index j.

Check if matrix[i][j] == target:

If yes, return true.

If entire matrix is traversed without finding the target, return false.


TC=O(n*m)
SC=O(1)
-----------------------------------------------------------------------
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();

    //traverse the matrix:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == target)
                return true;
        }
    }
    return false;
}
*/

/*
==========================
Optimising the brute force
===========================
/*
🔍 Intuition:
Instead of checking every element, we optimize the search using Binary Search.
Since each row is sorted, we can:
- First identify the row where the target could exist.
- Then apply Binary Search on that row.

✅ Key Check:
If (matrix[i][0] <= target && target <= matrix[i][n-1])
=> Target might be in row 'i'

📌 Algorithm:
1. Loop through each row (i):
    - Check if target lies between first and last element of the row.
2. If yes, apply binary search on that row.
    - If target is found → return true.
3. If no matching row or target not found → return false.

🕒 Time Complexity:
- Worst case: O(m * log n)
   (m = number of rows, n = number of columns)

📦 Space Complexity:
- O(1) – No extra space used

---------------------------------
bool binarySearch(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    int low = 0, high = n - 1;

    // Perform the steps:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) return true;
        else if (target > nums[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}


bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++) {
        if (matrix[i][0] <= target && target <= matrix[i][m - 1]) {
            return binarySearch(matrix[i], target);
        }
    }
    return false;
}

*/


/*
================================================================
Optimal Solutions( flatting the 2D matrix in 1D matrix)
===============================================================
🔍 Intuition:
We treat the 2D matrix as a virtual 1D sorted array to apply Binary Search.
Although actually flattening the matrix would take O(m × n) time and space,
we can simulate it using index mapping.

➡️ Key Insight:
We don’t flatten the matrix physically. Instead:
- We apply binary search on the range [0, m × n - 1] (virtual 1D array).
- Convert each 1D index to 2D: 
    row = index / n
    col = index % n

✅ This avoids extra space and achieves optimal time complexity.

📌 Algorithm:
1. Set two pointers:
   - low = 0
   - high = m × n - 1 (total number of elements)

2. While low ≤ high:
   a. mid = (low + high) / 2
   b. Convert mid to 2D indices:
      - row = mid / n
      - col = mid % n
   c. Compare matrix[row][col] with target:
      - If equal → return true
      - If smaller → search right half (low = mid + 1)
      - If greater → search left half (high = mid - 1)

3. If loop ends, target not found → return false

🕒 Time Complexity: O(log(m × n))
📦 Space Complexity: O(1) – No extra space used
*/




#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    //apply binary search:
    int low = 0, high = n * m - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int row = mid / m, col = mid % m;
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    searchMatrix(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
}


