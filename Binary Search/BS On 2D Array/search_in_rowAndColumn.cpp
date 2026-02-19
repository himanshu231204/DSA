//Search in a row and column-wise sorted matrix
/*
Problem Statement: You have been given a 2-D array 'mat' of size 'N x M' where 'N' and 'M' denote the number of rows and columns, respectively. The elements of each row and each column are sorted in non-decreasing order.
But, the first element of a row is not necessarily greater than the last element of the previous row (if it exists).
You are given an integer ‘target’, and your task is to find if it exists in the given 'mat' or not.

Pre-requisite: Search in a 2D sorted matrix
*/



/*
=====================
Brute Force
=====================
/*
🔍 Intuition:
In this type of matrix:
- Each row is sorted left to right ✅
- Each column is sorted top to bottom ✅
BUT ❌ the matrix is **not globally sorted** (i.e., matrix[i][0] may not be > matrix[i-1][n-1])

So, we **cannot apply simple binary search** across the full matrix.
The most basic way is to check each element manually.

📌 Algorithm (Brute Force):
1. Loop through each row using index `i`
2. Inside that loop, loop through each column using index `j`
3. Check if matrix[i][j] == target
   - If yes → return true
4. If the entire matrix is traversed and target not found → return false

🕒 Time Complexity: O(m × n)  
📦 Space Complexity: O(1) – No extra space used

-----------------------------------------
bool searchElement(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();

    //traverse the matrix:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == target)
                return true;
        }
    }


*/


/*
==========================
Better Solutions
===========================

/*
🔍 Intuition:
Each row in the matrix is sorted in non-decreasing order.
So instead of checking each column manually, we can apply **Binary Search** on every row to improve efficiency.

➡️ This helps eliminate half of the columns per row and reduces time complexity from O(m × n) to O(m × log n).

📌 Algorithm:
1. Loop through each row using index `i`
2. For each row:
   - Apply Binary Search on matrix[i]
   - If target is found → return true
3. If all rows are traversed and target not found → return false

🕒 Time Complexity: O(m × log n)  
   (m = number of rows, n = number of columns)

📦 Space Complexity: O(1) – No extra space used

--------------
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

bool searchElement(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
        bool flag =  binarySearch(matrix[i], target);
        if (flag) return true;
    }
    return false;
}

*/


/*
==================================
Optimal Solutions
===================================
/*
🔍 Intuition:
The matrix has:
- Each row sorted in non-decreasing order →
- Each column sorted in non-decreasing order ↓
BUT the matrix is not globally sorted — so no flattening or full binary search.

➡️ We can optimize search by starting from the **top-right (0, m-1)** or **bottom-left (n-1, 0)** cell.
These positions allow us to eliminate rows or columns based on comparison with the target.

🧭 Why (0, m-1) is ideal:
- If current element > target → Move left (col--) → Eliminate column
- If current element < target → Move down (row++) → Eliminate row

📌 Algorithm (Staircase Search):
1. Initialize:
   - row = 0
   - col = m - 1

2. While (row < n && col >= 0):
   a. If matrix[row][col] == target → return true
   b. If matrix[row][col] > target → move left (col--)
   c. If matrix[row][col] < target → move down (row++)

3. If loop ends, target not found → return false

🕒 Time Complexity: O(m + n)  
📦 Space Complexity: O(1) – No extra space used

✅ Efficient and elegant method for sorted row + column matrices!

------------------------------------------------------------------------------------------------------


*/

#include <bits/stdc++.h>
using namespace std;

bool searchElement(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int row = 0, col = m - 1;

    //traverse the matrix from (0, m-1):
    while (row < n && col >= 0) {
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) row++;
        else col--;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    searchElement(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
}











