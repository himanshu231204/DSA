// Longest Consecutive Sequence in an Array


//-------------------------------------------------------------------------------------------------
//Problem Statement: You are given an array of ‘N’ integers. 
//You need to find the length of the longest sequence which contains the consecutive elements.
//-----------------------------------------------------------------------------------------------------


//=================================

//Brute-force Approach: 

//==================================

/*
For each element in the array:

Try to find the next consecutive numbers (x+1, x+2, x+3, ...) using linear search.

Keep increasing the count (cnt) for each consecutive number found.

Stop when the next number is not found.

Repeat this for all elements and keep track of the maximum length found.

The maximum count from all these attempts is the final answer.

-------------------------------------------------------------------------
Complexity Analysis

Time Complexity: O(N2), N = size of the given array.
Reason: We are using nested loops each running for approximately N times.

Space Complexity: O(1), as we are not using any extra space to solve this problem.

-----------------------------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int>&a, int num) {
    int n = a.size(); //size of array
    for (int i = 0; i < n; i++) {
        if (a[i] == num)
            return true;
    }
    return false;
}
int longestSuccessiveElements(vector<int>&a) {
    int n = a.size(); //size of array
    int longest = 1;
    //pick a element and search for its
    //consecutive numbers:
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int cnt = 1;
        //search for consecutive numbers
        //using linear search:
        while (linearSearch(a, x + 1) == true) {
            x += 1;
            cnt += 1;
        }

        longest = max(longest, cnt);
    }
    return longest;
}

int main()
{
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}

*/



//=====================================================================

// Better Approach

//==============================================================================

/*

Optimized Approach (Using Sorting) – 
Variables used:

lastSmaller: stores the last element of the current sequence.

cnt: current sequence length.

longest: maximum sequence length found so far.

Steps:
Sort the array (to bring consecutive elements next to each other).

Initialize:

lastSmaller = INT_MIN

cnt = 0

longest = 1

Loop through the sorted array:

If arr[i] == lastSmaller + 1 → it's the next consecutive number:
→ Update lastSmaller = arr[i] and increment cnt.

If arr[i] == lastSmaller → duplicate element:
→ Skip it.

Else (gap found, not consecutive):
→ Start a new sequence: set lastSmaller = arr[i] and cnt = 1.

After each step, update longest = max(longest, cnt).

After the loop, longest holds the length of the longest consecutive subsequence.

✅ Time Complexity: O(n log n) due to sorting
⚠️ Modifies the original array
SC=O(1)

--------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int longestSuccessiveElements(vector<int>&a) {
    int n = a.size();
    if (n == 0) return 0;

    //sort the array:
    sort(a.begin(), a.end());
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;

    //find longest sequence:
    for (int i = 0; i < n; i++) {
        if (a[i] - 1 == lastSmaller) {
            //a[i] is the next element of the
            //current sequence.
            cnt += 1;
            lastSmaller = a[i];
        }
        else if (a[i] != lastSmaller) {
            cnt = 1;
            lastSmaller = a[i];
        }
        longest = max(longest, cnt);
    }
    return longest;

}

int main()
{
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}

*/


//===================================================================

// Optimal approach

//=============================================================================

/*
Optimal Approach (Using Set) – Summary

Idea:
Instead of checking sequences from every element (as in brute-force),
we only check for those elements which are potential starting points of sequences.

Steps:
1. Insert all elements of the array into a set for quick look-up.
2. For each element x in the set:
   - If (x - 1) does NOT exist in the set → x is a potential starting point.
   - From x, keep checking for consecutive numbers (x+1, x+2, ...) in the set.
   - Count how long the consecutive sequence continues.
   - Update the 'longest' sequence length if the current count is greater.

Variables:
- cnt → to store the current sequence length.
- longest → to store the maximum sequence length found so far.

Time Complexity: O(n)
Space Complexity: O(n)
*/

//-----------------------------------------




#include <bits/stdc++.h>
using namespace std;

int longestSuccessiveElements(vector<int>&a) {
    int n = a.size();
    if (n == 0) return 0;

    int longest = 1;
    unordered_set<int> st;
    //put all the array elements into set:
    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
    }

    //Find the longest sequence:
    for (auto it : st) {
        //if 'it' is a starting number:
        if (st.find(it - 1) == st.end()) {
            //find consecutive numbers:
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;

}

int main()
{
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}

