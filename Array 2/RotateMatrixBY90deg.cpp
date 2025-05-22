//Problem Statement: Given a matrix, your task is to rotate the matrix 90 degrees clockwise.

/*
=====================================================
Brute Force Approach
==============================================================
🔄 Approach: Rotate a Matrix 90° Clockwise Using a Dummy Matrix
Step-by-step Explanation:

Create a dummy matrix of the same size.

Copy elements from the original matrix to the dummy such that:

First row → Last column

Second row → Second last column

...

i-th row → (n−i−1)-th column


📌 Intuition:
You're pulling columns from the original matrix
 and reversing them to become rows in the new matrix.




#include <iostream>
#include <vector>
using namespace std;

void rotateMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    // Create a new matrix to store rotated values
    vector<vector<int>> rotated(n, vector<int>(n));

    // Fill the rotated matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            rotated[j][n - 1 - i] = matrix[i][j];
        }
    }

    // Copy rotated matrix back to original
    matrix = rotated;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:\n";
    printMatrix(mat);

    rotateMatrix(mat);

    cout << "\nRotated Matrix (90° clockwise):\n";
    printMatrix(mat);

    return 0;
}


Complexity Analysis

Time Complexity: O(N*N) to linearly iterate and put it into some other matrix.

Space Complexity: O(N*N) to copy it into some other matrix.
*/


/*
===============================================================
Optimal Solutions
====================================================================

🔍 Intuition:
When we rotate a matrix 90° clockwise:

The first column of the original becomes the first row of the rotated matrix (but in reverse order).

So, we can achieve this by first transposing the matrix and then reversing each row.

🔁 Approach:

Transpose the matrix: Convert rows to columns.   swap(matrix[i][j], matrix[j][i])

Reverse each row: To complete the 90° clockwise rotation.

📦 Space Complexity:

O(1) — Because all operations are done in-place (on the original matrix).

*/

#include<bits/stdc++.h>

using namespace std;
void rotate(vector < vector < int >> & matrix) {
    int n = matrix.size();
    //transposing the matrix
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
        swap(matrix[i][j], matrix[j][i]);
    }
    }
    //reversing each row of the matrix
    for (int i = 0; i < n; i++) {
    reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
    vector < vector < int >> arr;
    arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(arr);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[0].size(); j++) {
        cout << arr[i][j] << " " ;
    }
    cout << " "<< endl;
    }

}

/*

Complexity Analysis

Time Complexity: O(N*N) + O(N*N).One O(N*N) is for transposing the matrix and the other is for reversing the matrix.

Space Complexity: O(1).
*/

