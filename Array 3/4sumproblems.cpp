/*
===================================
Brute force 
======================================
🔹 Naive Approach (Brute-force) – 4Sum Problem
🧠 Intuition:
Check all possible quadruplets using 4 nested loops (similar to 3Sum). Keep only those whose sum matches the target, ensuring uniqueness by storing sorted quadruplets in a set.

📌 Steps:

Use a set to store unique quadruplets.

Run four nested loops (i, j, k, l) to explore all combinations:

i = 0 to n-1

j = i+1 to n-1

k = j+1 to n-1

l = k+1 to n-1

For each quadruplet, check:
arr[i] + arr[j] + arr[k] + arr[l] == target

If true, sort the quadruplet and add it to the set.

Convert the set to a list and return the result.

⏱️ Time Complexity: O(n⁴)
💾 Space Complexity: O(number of unique quadruplets)



#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    set<vector<int>> st;

    //checking all possible quadruplets:
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    // taking bigger data type
                    // to avoid integer overflow:
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main()
{
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = fourSum(nums, target);
    cout << "The quadruplets are: \n";
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}

*/

/*
==========================================
Better Approach
===========================================
🧠 Intuition:
Instead of 4 loops, use 3 nested loops to select nums[i], nums[j], and nums[k], and calculate the fourth element as:
🔸 nums[l] = target - (nums[i] + nums[j] + nums[k])

Then, search for nums[l] in a HashSet containing elements between j and k.

📌 Steps:

Use 3 nested loops to pick triplets nums[i], nums[j], nums[k].

Calculate the required 4th element:
required = target - (nums[i] + nums[j] + nums[k])

Use a HashSet to check if required exists between j and k.

If it does, store the sorted quadruplet to ensure uniqueness.
----------------------------------------------------------------------

# pseudo Code

📌 Steps:

Initialize a set to store unique quadruplets.

Use 2 nested loops to fix nums[i] and nums[j].

Before the 3rd loop, initialize a HashSet to track elements between indices j and k.

In the 3rd loop, for each k:

Compute the 4th number:
required = target - (nums[i] + nums[j] + nums[k])

If required exists in the HashSet, form the quadruplet, sort it, and add to the set.

Add nums[k] to the HashSet (to be used in future iterations).

Return all unique quadruplets from the set.

🧠 Key Insight:
HashSet helps us efficiently check for the 4th number, avoiding the need for a 4th loop.

⏱ Time Complexity: O(n³)
💾 Space Complexity: O(n) (for HashSet)
--------------------------------------------------------

❌ Why Not Insert All Elements into HashSet?
If we insert all array elements into the HashSet before the third loop, we might re-use the same element (nums[k]) as the fourth element, leading to invalid quadruplets like {i, j, k, k}.

🧠 Example Insight:
Given: arr = {1, 2, -1, -2, 2, 0, -1}, target = 0
If nums[i]=1, nums[j]=-1, nums[k]=0 → 4th element = 0 - (1 - 1 + 0) = 0
If all elements are in the HashSet, it might pick the same 0 from index k again.

🔒 Solution: Only insert elements between j and k (i.e., before k), so we avoid reusing the current element nums[k].


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    set<vector<int>> st;

    //checking all possible quadruplets:
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            set<long long> hashset;
            for (int k = j + 1; k < n; k++) {
                // taking bigger data type
                // to avoid integer overflow:
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                long long fourth = target - sum;
                if (hashset.find(fourth) != hashset.end()) {
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)(fourth)};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                // put the kth element into the hashset:
                hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main()
{
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = fourSum(nums, target);
    cout << "The quadruplets are: \n";
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}


*/

/*
=============================================
Optimal Approach
===============================================

✅ Optimal 4-Sum Approach (Two Pointers)
✨ Key Idea:

Eliminate the use of HashSet (for lookup) and set (for storing unique quads).

Use sorting + two fixed + two moving pointers, similar to the 3-sum optimal approach.

🔁 Steps:
Sort the array to simplify duplicate handling and two-pointer logic.

Fix two pointers i and j using nested loops:

Skip duplicates to avoid repeating the same quadruplet.

Use two pointers k (from j+1) and l (from end of array):

Check sum = nums[i] + nums[j] + nums[k] + nums[l]

If sum < target: increment k

If sum > target: decrement l

If sum == target: store the quadruplet and move both k and l, skipping duplicates.

Continue until all combinations are explored.

🎯 Why It's Efficient:
Sorting helps in skipping duplicates easily.

Two-pointer approach avoids the need for hash structures.

Time complexity is reduced to O(n³) compared to brute-force O(n⁴).



*/




#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    vector<vector<int>> ans;

    // sort the given array:
    sort(nums.begin(), nums.end());

    //calculating the quadruplets:
    for (int i = 0; i < n; i++) {
        // avoid the duplicates while moving i:
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n; j++) {
            // avoid the duplicates while moving j:
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            // 2 pointers:
            int k = j + 1;
            int l = n - 1;
            while (k < l) {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target) {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++; l--;

                    //skip the duplicates:
                    while (k < l && nums[k] == nums[k - 1]) k++;
                    while (k < l && nums[l] == nums[l + 1]) l--;
                }
                else if (sum < target) k++;
                else l--; // sum>target
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = fourSum(nums, target);
    cout << "The quadruplets are: \n";
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}




