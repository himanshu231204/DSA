// Find the repeating and missing numbers

/*
Problem Statement: You are given a read-only 
array of N integers with values also in the range [1, N]
 both inclusive. Each integer appears exactly once except
  A which appears twice and B which is missing. The task is
   to find the repeating and missing numbers A and B where A 
   repeats twice and B is missing.
*/


/*
======================================
brute Force
========================================
Approach:
The steps are as follows:

We will run a loop(say i) from 1 to N.
For each integer, i, we will count its occurrence in the given array using linear search.
We will store those two elements that have the occurrence of 2 and 0.
Finally, we will return the elements.
------------------------
Time Complexity: O(N2), where N = size of the given array.
Reason: Here, we are using nested loops to count occurrences of every element between 1 to N.

Space Complexity: O(1) as we are not using any extra space.
---------------------------------------------



#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a) {
    int n = a.size(); // size of the array
    int repeating = -1, missing = -1;

    //Find the repeating and missing number:
    for (int i = 1; i <= n; i++) {
        //Count the occurrences:
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] == i) cnt++;
        }

        if (cnt == 2) repeating = i;
        else if (cnt == 0) missing = i;

        if (repeating != -1 && missing != -1)
            break;
    }
    return {repeating, missing};
}

int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}


*/

/*
============================
Better Solutions(Using hashing)
==============================
Intuition:
Instead of counting the occurrences every time, using the hashing technique,
 we will store the frequency of each element between 1 to N.
  Now, the element with frequency 2 will be the repeating number and
   the element with frequency 0 will be the missing number.

Note: Here, we can solve this problem using a hash array.

Approach:
The steps are as follows:

The range of the number is 1 to N. So, we need a hash array of size N+1 (as we want to store the frequency of N as well).
We will iterate all the elements of the given array and update the hash array accordingly i.e. hash[a[i]] = hash[a[i]]+1.
Now, we will iterate on the hash array and return the two elements with frequencies 2 and 0.

-----------------------------------------------------------------
Complexity Analysis

Time Complexity: O(2N), where N = the size of the given array.
Reason: We are using two loops each running for N times. So, the time complexity will be O(2N).

Space Complexity: O(N) as we are using a hash array to solve this problem.
------------------------------------------------------------------



#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a) {
    int n = a.size(); // size of the array
    int hash[n + 1] = {0}; // hash array

    //update the hash array:
    for (int i = 0; i < n; i++) {
        hash[a[i]]++;
    }

    //Find the repeating and missing number:
    int repeating = -1, missing = -1;
    for (int i = 1; i <= n; i++) {
        if (hash[i] == 2) repeating = i;
        else if (hash[i] == 0) missing = i;

        if (repeating != -1 && missing != -1)
            break;
    }
    return {repeating, missing};
}

int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}


*/


/*
=============================================
Optimal Solutions 1( using maths)
==============================================

Intuition:
We treat the problem mathematically using two equations with two unknowns:

Let X = Repeating number

Let Y = Missing number

Step 1 – Sum Equation:
Sum of first N natural numbers:
Sn = N * (N + 1) / 2
Let S be the actual sum of the given array.
Then,
S - Sn = X - Y → Equation ①

Step 2 – Square Sum Equation:
Sum of squares of first N natural numbers:
S2n = N * (N + 1) * (2N + 1) / 6
Let S2 be the sum of squares of elements in the array.
Then,
S2 - S2n = X² - Y² = (X + Y)(X - Y) → Equation ②

From Equation ①:
X - Y = S - Sn
From Equation ②:
X + Y = (S2 - S2n) / (X - Y)

Now using these two equations, we solve for X (repeating) and Y (missing).

-----------------------------
Approach:
Assume the repeating number to be X and the missing number to be Y.

The steps are as follows:

First, find out the values of S and Sn and then calculate S - Sn (Using the above formulas).
Then, find out the values of S2 and S2n and then calculate S2 - S2n.
After performing steps 1 and 2, we will be having the values of X + Y and X - Y. Now,
 by substitution of values, we can easily find the values of X and Y.


-------------------------------------------------------------------------------------------------------------------------------
Complexity Analysis

Time Complexity: O(N), where N = the size of the given array.
Reason: We are using only one loop running for N times. So, the time complexity will be O(N).

Space Complexity: O(1) as we are not using any extra space to solve this problem.

*/




#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a) {
    long long n = a.size(); // size of the array

    // Find Sn and S2n:
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6; // square 

    // Calculate S and S2:
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }

    //S-Sn = X-Y:
    long long val1 = S - SN;

    // S2-S2n = X^2-Y^2:
    long long val2 = S2 - S2N;

    //Find X+Y = (X^2-Y^2)/(X-Y):
    val2 = val2 / val1;

    //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
    // Here, X-Y = val1 and X+Y = val2:
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}

int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}






