//Kth Missing Positive Number
//Problem Statement: You are given a strictly increasing array ‘vec’ and a positive integer 'k'. Find the 'kth' positive integer missing from 'vec'.

/*==========================================================
🧠 Naive Approach – Simple Loop-Based Solution
=================================================================

📌 Core Idea:
- Traverse the array from left to right.
- If the current element is ≤ k, it means one missing number is already "covered".
- So, increment k.
- If an element > k is found, we stop — because k is the smallest missing number.

📋 Algorithm:
1. Iterate through the array `vec`.
2. For each element:
   - If vec[i] <= k: increment k by 1 (as this value is covered).
   - Else: break (we've found the gap).
3. Return k as the missing value.

✅ Example:
vec = [1, 2, 3, 4], k = 2
→ Pass 1: 1 ≤ 2 → k = 3
→ Pass 2: 2 ≤ 3 → k = 4
→ Pass 3: 3 ≤ 4 → k = 5
→ Pass 4: 4 ≤ 5 → k = 6
→ Final result = 6

🕒 Time Complexity: O(N)
📦 Space Complexity: O(1)

⚠️ Note:
- Works only when the array is sorted in increasing order.
- Stops at the first gap greater than k — ensures optimality within a naive framework.
-------------------------------------




#include <bits/stdc++.h>
using namespace std;

int missingK(vector < int > vec, int n, int k) {
    for (int i = 0; i < n; i++) {
        if (vec[i] <= k) k++; //shifting k
        else break;
    }
    return k;
}


int main()
{
    vector<int> vec = {4, 7, 9, 10};
    int n = 4, k = 4;
    int ans = missingK(vec, n, k);
    cout << "The missing number is: " << ans << "\n";
    return 0;
}


*/


/*==============================================================
🔍 Optimal Approach (Using Binary Search)
===================================================================

📌 Core Idea:
We cannot apply binary search directly on the array, as it's not sorted by missing numbers.
Instead, we:
➡️ Apply binary search on array indices.
➡️ At each index, count how many numbers are missing until that point.
➡️ Narrow down the search to find the closest number in the array **just before** the K-th missing one.

📐 Key Observation:
Number of missing numbers up to index `i`:
    missing = vec[i] - (i + 1)

💡 Binary Search Insight:
- If missing < k ⇒ the kth missing number lies **after** index `mid` (low = mid + 1)
- Else ⇒ it lies **before or at** index `mid` (high = mid - 1)

🧮 How to get the kth missing number:
Once binary search ends, `high` will point to the **last index** before the K-th missing number.
→ Total missing numbers till that index = vec[high] - (high + 1)
→ So, the remaining to reach K = k - missing
→ Answer = vec[high] + (k - missing)
         = k + high + 1

📋 Algorithm Steps:
1. Initialize: low = 0, high = n - 1
2. While low <= high:
    a. mid = (low + high) / 2
    b. missing = vec[mid] - (mid + 1)
    c. If missing < k → low = mid + 1
       Else → high = mid - 1
3. Return: k + high + 1

🧠 Example:
vec = [2, 3, 4, 7, 11], k = 5
→ Missing counts at indices: [1, 1, 1, 3, 6]
→ high will end up at index 3 (value 7), which has 3 missing numbers before
→ kth missing = 7 + (5 - 3) = 9

🕒 Time Complexity: O(log N)
📦 Space Complexity: O(1)
*/




#include <bits/stdc++.h>
using namespace std;

int missingK(vector < int > vec, int n, int k) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int missing = vec[mid] - (mid + 1);
        if (missing < k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return k + high + 1;
}

int main()
{
    vector<int> vec = {4, 7, 9, 10};
    int n = 4, k = 4;
    int ans = missingK(vec, n, k);
    cout << "The missing number is: " << ans << "\n";
    return 0;
}



