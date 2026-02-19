//  Brute Force 

/*
Algorithm / Intuition
Brute Force: Finding all possible permutations. 

Approach :

Step 1: Find all possible permutations of elements present and store them.

Step 2: Search input from all possible permutations.

Step 3: Print the next permutation present right after it.

Note: do not code only explain the approach and TC to interviwer
====================================================


🧠 Note:
This approach has very high time complexity: O(n! * n log n) due to generating and sorting all permutations.

It's not recommended for n > 6.

*/
//==============================================




// Better solutions:

/*
Using in-built function

C++ provides an in-built function called next_permutation() which 
directly returns the lexicographically next greater permutation of the input.

=============================================

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int arr[] = {1,3,2};
    
    next_permutation(arr,arr+3);//using in-built function of C++
    
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2];
    
    return 0;
}
*/

// noiw Explaining the optimal solutions

/*
Observationa 1

🔄 Next Permutation (Observation + Break-point)
✅ Lexicographical Order Logic:
Like dictionary words → compare from left to right at first unequal element.

📌 Key Insight:
In any permutation, if we scan from right:

We find a point where arr[i] < arr[i+1] → this is the break-point.

Elements after this point are in descending order.

To get next permutation → we need to slightly increase the current arrangement starting from break-point.

🔍 Steps to Find Break-point:

Traverse from back, find index i where arr[i] < arr[i+1].

Swap arr[i] with next greater element on right.

Reverse the part after index i.

📘 Example:
For [1, 2, 3] → Next = [1, 3, 2]
For [3, 2, 1] → Next = [1, 2, 3] (last permutation → reset to smallest)

=======================================================================================

Observations 2:

🔁 Observation 2 – No Break-point (Last Permutation)
📌 If No Break-point Found (ind = -1):

The array is sorted in descending order → this is the last permutation.

There is no arr[i] < arr[i+1] from right → can't go further lexicographically.

✅ What to Do?
➡️ Just reverse the entire array to get the first (smallest) permutation.

📘 Example:
[3, 2, 1] → Reverse → [1, 2, 3]

==================================================================================

🔁 Observation 3 – Finding the Next Greater Element for Break-point
📌 After finding the break-point (i):

Left half (0 to i–1) stays unchanged.

In the right half, find the smallest element greater than arr[i] (i.e., the next greater element).

🎯 Goal:
Swap arr[i] with the next greater element in the right half to move to the next permutation.

🧠 How to Find It?

Traverse from the back.

Find first arr[j] > arr[i].

Swap arr[i] ↔ arr[j].

📘 Why?
Because the right part is in descending order, traversing 
from the back gives the correct next greater element.

=======================================================================================================

Algorithm Approach


✅ Steps to Generate the Next Lexicographical Permutation:

Find Break-point (i):
Traverse from right → find first i such that arr[i] < arr[i+1].
(This is where the ascending order breaks.)

If No Break-point (i = -1):
→ Array is in descending order (last permutation).
→ Reverse the entire array → gives the first permutation.
✅ Done.

If Break-point Exists:

Traverse from right again → find first j such that arr[j] > arr[i].

Swap arr[i] and arr[j].

Reverse the subarray from i+1 to end
→ This gives the next smallest lexicographical permutation.


TC=O(n)

=========================================================================================================
*/




#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterPermutation(vector<int> &A) {
    int n = A.size(); // size of the array.

    // Step 1: Find the break point:
    int ind = -1; // break point
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] < A[i + 1]) {
            // index i is the break point
            ind = i;
            break;
        }
    }

    // If break point does not exist:
    if (ind == -1) {
        // reverse the whole array:
        reverse(A.begin(), A.end());
        return A;
    }

    // Step 2: Find the next greater element
    //         and swap it with arr[ind]:

    for (int i = n - 1; i > ind; i--) {
        if (A[i] > A[ind]) {
            swap(A[i], A[ind]);
            break;
        }
    }

    // Step 3: reverse the right half:
    reverse(A.begin() + ind + 1, A.end());

    return A;
}

int main()
{
    vector<int> A = {2, 1, 5, 4, 3, 0, 0};
    vector<int> ans = nextGreaterPermutation(A);

    cout << "The next permutation is: [";
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << "]n";
    return 0;
}




