//  Given the row number n. Print the n-th row of Pascal’s triangle.

/*
========================
Brute Force
=========================

Observation:
The n-th row of Pascal’s Triangle contains exactly n elements.

For each column c from 1 to n:

Use the combination formula to calculate the element at position (n, c) as (n-1)C(c-1).

Print each element to form the row.

Approach
Loop through c = 1 to n.

Set n_val = n - 1 and r = c - 1.

Calculate combination using:

Initialize res = 1.

Loop i = 0 to r - 1:

res *= (n_val - i)

res /= (i + 1)

Print each calculated res.

================================================================================

✅ Optimal Approach Summary
💡 Intuition:
Each element in Pascal’s triangle (from column 1 onward) can be
 calculated using the previous element:

Current element= previous element*(n-i)/i

​
This avoids calculating factorials or full combinations repeatedly.
--------------------------
⚙️ Algorithm Steps:
Start by printing the first element 1 manually.

Use a loop from i = 1 to n - 1 (0-based indexing).

In each iteration:

Compute the next element using:
                      
                      elemant=prev*(n-i)/i

 Print/store the element.

Continue until the entire row is built.                  

------------------------------------------------------

Complexity Analysis
Time Complexity: O(N) where N = given row number. Here we are using only a single loop.

Space Complexity: O(1) as we not using any extra space.
*/
\
#include <bits/stdc++.h>
using namespace std;

void pascalTriangle(int n) {
    long long ans = 1;
    cout << ans << " "; // printing 1st element

    //Printing the rest of the part:
    for (int i = 1; i < n; i++) {
        ans = ans * (n - i);
        ans = ans / i;
        cout << ans << " ";
    }
    cout << endl;
}

int main()
{
    int n = 5;
    pascalTriangle(n);
    return 0;
}
