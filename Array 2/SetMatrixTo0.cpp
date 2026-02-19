//Problem Statement: Given a matrix if an element in the matrix is 0 then
// you will have to set its entire column and row to 0 and then return the matrix.

/*
================================================
Brute Force Approach
===============================================

💡 Intuition:
We simulate the exact requirement of the problem:

For each 0, all cells in its row and column should eventually become 0.

We mark cells with -1 first to avoid interfering with other original zeroes during traversal.

----------------------------------------------------------------------------

Algorithm Steps:

Traverse the matrix using nested loops.

For each cell (i, j) with value 0, mark all other cells in the same row and same column as -1 (but skip other zeroes).

Repeat step 2 for all zero-valued cells.

After processing, convert all -1 values in the matrix to 0.

⚠️ Assumption: The matrix contains no negative values. If negatives are present, use a different placeholder to mark.

------------------------------------------------------------------------------------------------------------------------------------
 // Traversing the matrix and accessing each element
    for (int i = 0; i < rows; i++) {         // Outer loop for rows
        for (int j = 0; j < cols; j++) {     // Inner loop for columns
            cout << "Element at [" << i << "][" << j << "] = " << matrix[i][j] << endl;
        }
    }
-------------------------------------------------------------------------------------------------------

🔍 Why not mark with 0 directly?
If we mark cells with 0 immediately, we might accidentally treat these newly marked 0s as original ones, leading to incorrect changes in the matrix.

🧠 Example problem:

Suppose you mark a row/column as 0 because of a 0 at (1,1).

Later, a cell like (1,2) (which was originally 1) becomes 0.

Your algorithm sees this new 0 and wrongly modifies its row and column.

❌ This leads to incorrect results.
---------------------------------------------------------------------------------------------------------

🔒 Why we use -1 instead of 0:
We use -1 as a temporary marker, assuming the matrix has no negative numbers.

This way, we can differentiate between:

Original 0 → used to mark rows/columns

Temporary mark → will become 0 later
-------------------------------------------------------------------------------------------------------------------

⚠️ Why not mark 0 cells with -1:
If we overwrite original 0s with -1, we lose the actual 0s that should influence row/column marking.

🧠 Example problem:

Suppose (1,3) was 0, but you changed it to -1.

Your algorithm misses it in the next pass.

❌ It fails to set row 1 and column 3 to 0.

------------------------------------------------------------------------
----------------------------------------------------------------------------------
 


#include <bits/stdc++.h>
using namespace std;

void markRow(vector<vector<int>> &matrix, int n, int m, int i) {
    // set all non-zero elements as -1 in the row i:
    for (int j = 0; j < m; j++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}


void markCol(vector<vector<int>> &matrix, int n, int m, int j) {
    // set all non-zero elements as -1 in the col j:
    for (int i = 0; i < n; i++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {

    // Set -1 for rows and cols
    // that contains 0. Don't mark any 0 as -1:

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                markRow(matrix, n, m, i);
                markCol(matrix, n, m, j);
            }
        }
    }

    // Finally, mark all -1 as 0:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);

    cout << "The Final matrix is: n";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "n";
    }
    return 0;
}

-----------------------------------------------------------

Time Complexity: O((N*M)*(N + M)) + O(N*M), where N = no. of rows in the matrix and M = no. of columns in the matrix.
Reason: Firstly, we are traversing the matrix to find the cells with the value 0. It takes O(N*M).
 Now, whenever we find any such cell we mark that row and column with -1. 
 This process takes O(N+M). So, combining this the whole process, finding and marking, takes O((N*M)*(N + M)).
Another O(N*M) is taken to mark all the cells with -1 as 0 finally.

Space Complexity: O(1) as we are not using any extra space.

    */

/*
=================================================================================================
Better solutions
=================================================================================================

✅  Intuition: / Algorithm

Instead of modifying the matrix while traversing (as we did in the previous approach using -1), we use two extra arrays:

row[] → marks which rows need to be zeroed

col[] → marks which columns need to be zeroed

💡 How It Works:
First pass:

Traverse the matrix.

If a cell (i, j) contains 0, mark row[i] = 1 and col[j] = 1.

Second pass:

Traverse the matrix again.

If row[i] == 1 or col[j] == 1, set matrix[i][j] = 0.

-------------------------------------------------------------------------------

  

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {

    int row[n] = {0}; // row array
    int col[m] = {0}; // col array

    // Traverse the matrix:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // mark ith index of row wih 1:
                row[i] = 1;

                // mark jth index of col wih 1:
                col[j] = 1;
            }
        }
    }

    // Finally, mark all (i, j) as 0
    // if row[i] or col[j] is marked with 1.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);

    cout << "The Final matrix is: ";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << " "<<endl;
    }
    return 0;
}
    ----------------------------------------

    Time Complexity: O(2*(N*M)), where N = no. of rows in the matrix and M = no. of columns in the matrix.
Reason: We are traversing the entire matrix 2 times and each traversal is taking O(N*M) time complexity.

Space Complexity: O(N) + O(M), where N = no. of rows in the matrix and M = no. of columns in the matrix.
Reason: O(N) is for using the row array and O(M) is for using the col array.

*/


/*
===================================================================
Optimal Approach
===================================================================

✅ Optimized Space Approach (Using First Row & Column as Markers)
Intuition:

Instead of using separate row[] and col[] arrays, we reuse the first row and first column of the matrix to mark which rows and columns should be zeroed.

Since matrix[0][0] is shared by both row and column, we use an extra variable col0 to track if the first column should be zeroed.

🔧 Key Idea:
If any cell in matrix[i][j] == 0:

Mark matrix[i][0] = 0 (row marker)

Mark matrix[0][j] = 0 (column marker)

If any cell in first column is 0, mark col0 = 0.

If any cell in first row is 0, mark matrix[0][0] = 0.

💡 Advantage:
Space Complexity is reduced to O(1) (in-place solution).

Maintains O(N*M) time complexity.

---------------------------------------------------------------
✅ Approach (In-place using 1st row, 1st column & a variable)
Steps:

First Pass – Marking Phase:

Traverse the matrix.

If matrix[i][j] == 0, mark:

matrix[i][0] = 0 (row marker)

matrix[0][j] = 0 (column marker)

Special Case:

If j == 0, set col0 = 0 instead of marking matrix[0][0].

Second Pass – Set cells (1,1) to (n-1,m-1):

Use the markers in the 1st row and 1st column to set inner cells to 0.

Avoid modifying 1st row and 1st column at this stage.

Final Step – Modify 1st row and 1st column:

If matrix[0][0] == 0, zero the entire 1st row (from (0,1) to (0,m-1)).

If col0 == 0, zero the entire 1st column (from (0,0) to (n-1,0)).

🔍 Observation:
We delay modifying the 1st row and 1st column because they are used as
 markers to update the rest of the matrix. Modifying them early would
 corrupt the markers and lead to incorrect results.

*/


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {

    // int row[n] = {0}; --> matrix[..][0]
    // int col[m] = {0}; --> matrix[0][..]

    int col0 = 1;
    // step 1: Traverse the matrix and
    // mark 1st row & col accordingly:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // mark i-th row:
                matrix[i][0] = 0;

                // mark j-th column:
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] != 0) {
                // check for col & row:
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    //step 3: Finally mark the 1st col & then 1st row:
    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

    return matrix;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);

    cout << "The Final matrix is: ";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << " "<<endl;
    }
    return 0;
}


// TC=Time Complexity: O(2*(N*M)), where N = no. of rows in the matrix and M = no. of columns in the matrix.

//SC=Space Complexity: O(1) as we are not using any extra space.



