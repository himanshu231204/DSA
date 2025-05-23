// Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.

/*
===================================
Brute Force
=====================================

✅ Naive Approach Summary
💡 Intuition:
This approach combines the naive method of calculating 
combinations with a nested loop to generate each row of Pascal’s Triangle.


⚙️ Algorithm Steps:
Run a loop for each row from 1 to n.

For each row, initialize a temporary list to store its elements.

For each column in the current row:

Let n = row - 1 and r = col - 1.

Compute the combination value using:

     res=1
     loop i=1 from to r
     res=res*(n-i)/i
Add the computed value to the temporary list.

After completing all columns in the row, add the list to the final answer list.

Return the answer list containing all rows.

-----------------------------------------------------

🧠 Complexity Analysis Summary
⏱ Time Complexity:
O(n³)

Reason:

Outer loop runs n times (for n rows).

For each row, we generate all elements using a nested loop that computes combinations.

Computing a single combination using the naive method takes O(r) time.

Overall → O(n × n × r) ≈ O(n³) in worst-case.

💾 Space Complexity:
O(1) (excluding the output list)

Reason:

No extra space is used apart from storing the final answer.

No recursive stack or auxiliary arrays.

-------------------------------------------------


#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i+1);
    }
    return (int)(res);
}

vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;

    //Store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        vector<int> tempLst; // temporary list
        for (int col = 1; col <= row; col++) {
            tempLst.push_back(nCr(row - 1, col - 1));
        }
        ans.push_back(tempLst);
    }
    return ans;
}

int main()
{
    int n = 5;
    vector<vector<int>> ans = pascalTriangle(n);
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "n"<<endl;
    }
    return 0;
}

*/

/*
==========================================
optimal solution
===========================================

✅ Optimal Pascal Triangle Generation – Summary
🔍 Intuition:

Use the optimized method (from variation 2) to generate each row in O(n) time.

Apply it row-by-row to construct the entire triangle.

⚙️ Approach:
Loop through rows from 1 to n.

For each row, call a generateRow() function.

Inside generateRow():

Start with the first element = 1.

Use a loop to generate the remaining elements using:
    current_element = previous_element × (row - col) / col

    Store each element in a temporary list.

Add the completed row to the final answer list.

Return the full Pascal Triangle.

Time Complexity: O(n2), where n = number of rows(given).
Reason: We are generating a row for each single row. 
The number of rows is n. And generating an entire row takes O(n) time complexity.

Space Complexity: In this case, we are only using space to store the answer. 
That is why space complexity can still be considered as O(1).
*/


#include <bits/stdc++.h>
using namespace std;

vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); //inserting the 1st element

    //calculate the rest of the elements:
    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;

    //store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        ans.push_back(generateRow(row));
    }
    return ans;
}

int main()
{
    int n = 5;
    vector<vector<int>> ans = pascalTriangle(n);
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "n"<<endl;
    }
    return 0;
}
