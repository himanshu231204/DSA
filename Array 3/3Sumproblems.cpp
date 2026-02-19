//3 Sum : Find triplets that add up to a zero

/*
===============================
Brute Force Approach
===============================
🧠 Intuition (Brute Force – 3Sum Problem)
The idea is simple:

We use three nested loops to check all possible triplets in the array.

For each triplet, we check if their sum equals the target (typically 0).

Before adding a triplet to our result, we sort it to maintain a consistent order.

We store only unique triplets by ensuring no duplicates are included in the final answer.
-------------------------------------------------------------------------------------------------------------

🔁 Brute Force 3Sum – Algorithm Summary
Use three nested loops to check every possible triplet in the array.

For each triplet (i, j, k), check if the sum equals 0.

If it does:

Sort the triplet to ensure consistent order.

Insert it into a set to automatically handle duplicates.

After all iterations, return the unique triplets from the set.

⏱️ Time Complexity: O(n³)
🔁 Use Case: Best for understanding the problem; not efficient for large inputs.

---------------------------------------------------------------------------------------



#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplet(int n, vector<int> &arr) {
    set<vector<int>> st;

    // check all possible triplets:
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == 0) {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    //store the set elements in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}


int main()
{
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = triplet(n, arr);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}


*/


/*
========================================================================================
Better Approach
==========================================================

🔁 3Sum Using Hashing – Intuition & Optimization
In the brute-force method, we used 3 loops to check all triplets.

Now, we aim to reduce it to 2 loops by calculating the third number instead of looping for it.

For any triplet sum arr[i] + arr[j] + arr[k] = 0, we derive:

arr[k] = -(arr[i] + arr[j])

Instead of a third loop, use a HashSet to store elements between i and j, then check if -sum exists in the set.

This eliminates the third loop and improves efficiency.

❓ Why not use a global set for all elements?
Because we only want to find the third element among the remaining elements after i,
 not from the entire array — to avoid duplicate or invalid triplets.

--------------------------------------------------------------------------------
✅ Summary: Why Not Insert All Elements into the HashSet in 3Sum
If we insert all array elements into the HashSet, we might accidentally reuse an element that's already been chosen as arr[i] or arr[j].

📌 Example:
Array: {1, 2, -1, -2, 4, 0, -1}
If arr[i] = -2 and arr[j] = 4, then
arr[k] = -(arr[i] + arr[j]) = -2

If we search for -2 in a global set, we may pick the same -2 used as arr[i], creating an invalid triplet like [-2, 4, -2].

🛑 Hence, we only use a local HashSet starting after j to ensure we don’t reuse arr[i] or arr[j], maintaining triplet validity.
------------------------------------------------------------------------------------

✅ Summary: Two-Pointer + HashSet Approach for 3Sum
📌 Goal: Find all unique triplets with sum = 0 using 2 loops and a HashSet to reduce time complexity.

🔍 Algorithm Steps:

Use a Set to store unique triplets.

Loop i from 0 to n-1.

For each i, create a new HashSet to track elements between i and j.

Loop j from i+1 to n-1:

Compute the required third number: target = -(arr[i] + arr[j])

If target exists in the HashSet, sort the triplet [arr[i], arr[j], target] and add to the result set.

Add arr[j] to the HashSet (to ensure it's only used after i and before j).

Return all unique triplets from the set.

✅ Why It Works:
Prevents duplicate triplets and avoids reusing the same elements by building the HashSet dynamically during traversal.
---------------------------------------------------------------------------------------------------------------------------------


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplet(int n, vector<int> &arr) {
    set<vector<int>> st;

    for (int i = 0; i < n; i++) {
        set<int> hashset;
        for (int j = i + 1; j < n; j++) {
            //Calculate the 3rd element:
            int third = -(arr[i] + arr[j]);

            //Find the element in the set:
            if (hashset.find(third) != hashset.end()) {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }

    //store the set in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}


int main()
{
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = triplet(n, arr);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}
*/

/*
=========================================================
Optimal Solutions
=========================================================

Intuition:
This approach aims to eliminate:

The HashSet (used for third element lookup),

The Set (used for storing unique triplets).
---------------------------------------
How it works:

Sort the array first.

Fix one pointer i, then use two pointers j (i+1) and k (end of array) to find the other two elements.

Skip duplicates using the fact that the sorted array places them consecutively.

Move pointers smartly:

If sum < 0: increment j

If sum > 0: decrement k

If sum == 0: save the triplet, and skip duplicates

Why this works:

Sorting ensures duplicates are adjacent, so skipping them is easy.

Two-pointer technique eliminates the need for a lookup set.

No extra space is needed for duplicate checking.

➡️ This approach reduces both time complexity and space complexity, 
making it the most efficient version of the 3Sum solution.
----------------------------------------------------------------------------------------------

Approach Overview:

Sort the array to manage duplicates easily.

Use a fixed pointer i running from 0 to n-1.

Skip duplicates for i to avoid repeated triplets.

Initialize two pointers:

j = i + 1 (moves forward)

k = n - 1 (moves backward)

While j < k, calculate sum = arr[i] + arr[j] + arr[k]:

If sum > 0: Decrease k (need smaller value)

If sum < 0: Increase j (need larger value)

If sum == 0:

Store the triplet

Move both j and k while skipping duplicates

Continue until all unique triplets are found.

Why it's efficient:

Eliminates nested loops and extra sets

Handles duplicates cleanly by skipping them in a sorted array

Uses O(n²) time and O(1) extra space (ignoring output)
*/



#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplet(int n, vector<int> &arr) {
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        //remove duplicates:
        if (i != 0 && arr[i] == arr[i - 1]) continue;

        //moving 2 pointers:
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0) {
                j++;
            }
            else if (sum > 0) {
                k--;
            }
            else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                //skip the duplicates:
                while (j < k && arr[j] == arr[j - 1]) j++;
                while (j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }
    return ans;
}


int main()
{
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = triplet(n, arr);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}


/*
✅ Complexity Analysis Summary:
Time Complexity:
O(N log N + N²)

Sorting the array takes O(N log N).

For each element (N times), two pointers scan the array ⇒ O(N²) overall.

Space Complexity:
O(1) (excluding the output)

No extra space is used apart from the answer list.

So, constant auxiliary space.

🔁 Efficient in time, optimal in space!
*/


