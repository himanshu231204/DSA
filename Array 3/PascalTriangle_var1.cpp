//Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.

/*
✅ Summary: Naive Approach to Find Element in Pascal's Triangle

Problem: Given a row r and column c, find the element at position (r, c) in Pascal’s Triangle.

🔹 Naive Approach 1:
Generate the entire Pascal’s Triangle and then access element at position (r, c).

Time-consuming and space-heavy.
------------------------------------------------

🔹 Naive Approach 2 (Better Way):
Use combinatorics:
Element at (r, c) = (r-1)C(c-1)

Formula:

nCr= n!/r!(n-r)!
where n = r - 1, r = c - 1

Steps:

Calculate n!, r!, and (n - r)! separately

Compute nCr

Time Complexity:
O(n) + O(r) + O(n - r)

​📌 This approach is better than generating the full
 triangle but still not optimized due to repeated factorial calculations.
 -----------------------------------------------------------------------------

 🔹 Optimized Combination (nCr) Formula – 
✅ What is it?
To find:
nCr = Combination of n things taken r at a time

🧠 Optimized Formula:
Instead of calculating full factorials, we use:

nCr = (n * (n - 1) * (n - 2) * ... * (n - r + 1)) 
        ----------------------------------------
               (1 * 2 * 3 * ... * r)

⚡ Why use this?
Avoids large factorials.

Reduces time complexity from O(n!) to O(r).

Faster and avoids integer overflow in some cases.

🔍 Example:
Find 6C3
= (6 × 5 × 4) / (3 × 2 × 1)
= 120 / 6
= 20


⏱ Time Complexity:
O(r) → Only r multiplications/divisions.


-------------------------------------------------------------

Approach to Calculate Combination (nCr):
Set n = r - 1 and r = c - 1.

Initialize result = 1.

Run a loop from i = 0 to r - 1:

Multiply result by (n - i).

Divide result by (i + 1).

After the loop ends, result holds the value of nCr.
*/


#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

int pascalTriangle(int r, int c) {
    int element = nCr(r - 1, c - 1);
    return element;
}

int main()
{
    int r = 5; // row number
    int c = 3; // col number
    int element = pascalTriangle(r, c);
    cout << "The element at position (r,c) is: "
            << element << "n";
    return 0;
}
        
        