/*
🔍 Prefix Sum kya hota hai?

Prefix sum ka matlab hota hai:
“Array ke har element tak ka total sum.”
--------------------------------------------------------------------------
🧠 Simple Example:
arr = [2, 4, 6, 1, 3]

Prefix Sum banayenge:
prefix[0] = 2                        // pehla element ka sum
prefix[1] = 2 + 4 = 6
prefix[2] = 2 + 4 + 6 = 12
prefix[3] = 2 + 4 + 6 + 1 = 13
prefix[4] = 2 + 4 + 6 + 1 + 3 = 16

Toh prefix sum array hoga:
prefix = [2, 6, 12, 13, 16]
-----------------------------------------
✅ Use of Prefix Sum:
Prefix sum ka use hota hai:

🔸 1. Subarray sum jaldi nikaalne ke liye
Agar tu koi subarray ka sum nikalna chahta hai, for example:
Sum of arr[1] to arr[3] → 4 + 6 + 1 = 11

Toh tu kar sakta hai
prefix[3] - prefix[0] = 13 - 2 = 11
Matlab:
Sum of arr[i...j] = prefix[j] - prefix[i-1]

Agar i = 0, toh prefix[j] hi answer hoga.
----------------------------------------------------------------------
🧠 Real-life Analogy:
Soch le ek dukan hai jahan har din ka paisa likha hai:
[100, 150, 200, 50]
Tu poochta hai: "Day 2 se Day 4 ka total kitna paisa aaya?"

Instead of counting again and again, dukan waala already total banakar rakhta hai:
Prefix Sum: [100, 250, 450, 500]
Toh wo bolega:
500 (day 4 tak) - 100 (day 1 tak) = 400

*/
#include <bits/stdc++.h>
using namespace std;

// function to find the prefix sum array
vector<int> findPrefixSum(vector<int> &arr) {
    int n = arr.size();
    
    // to store the prefix sum
    vector<int> prefixSum(n);

    // initialize the first element
    prefixSum[0] = arr[0];

    // Adding present element with previous element
    for (int i = 1; i < n; i++)
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    
    return prefixSum;
}

int main() {
    vector<int> arr = {10, 20, 10, 5, 15};
    vector<int> prefixSum = findPrefixSum(arr);
    for(auto i:prefixSum) {
        cout<<i<<" ";
    }
    return 0;
}

//======================================

/*
Time Complexity: O(n), as we are traversing the array only once.
Auxiliary Space: O(n), to create the array prefxSum[] of size n.
*/
//===============================================================================================


// 📘 PREFIX SUM - MOST COMMON USE CASES

/*
-----------------------------------------
🔹 1. Find Sum of Subarray (i to j) in O(1)
-----------------------------------------
> Use prefix[] where:
  prefix[i] = sum of elements from 0 to i

Subarray sum (i to j) = prefix[j] - prefix[i-1]

Example:
Input: arr = [1, 2, 3, 4, 5]
prefix = [1, 3, 6, 10, 15]
Sum from index 1 to 3 = prefix[3] - prefix[0] = 10 - 1 = 9
*/


/*
-----------------------------------------
🔹 2. Count Subarrays with Sum = K
-----------------------------------------
> Use prefix sum + hashmap (store count of prefix sums)

Example: arr = [1, 2, 3], k = 3
Prefix sum: [1, 3, 6]
Count all subarrays whose sum is k using: 
  if (prefix_sum - k) exists in map => count++
*/


/*
-----------------------------------------
🔹 3. Maximum Subarray Sum (Alt. to Kadane's)
-----------------------------------------
> Use prefix[j] - min(prefix[i])

Keep track of:
  maxSum = max(maxSum, prefix[i] - minPrefixSoFar)
*/


/*
-----------------------------------------
🔹 4. Range Updates and Range Queries
-----------------------------------------
> For static range updates
  - Use prefix diff array method

Example: Add +1 from index 2 to 4
  diff[2] += 1
  diff[5] -= 1
Then take prefix sum of diff array to get final array
*/


/*
-----------------------------------------
🔹 5. Count Subarrays with Equal 0s and 1s
-----------------------------------------
> Convert all 0 → -1
> Then apply subarray sum = 0 logic (prefix sum + hashmap)
*/


/*
-----------------------------------------
🔹 6. Even-Odd Index Prefix Sums
-----------------------------------------
> Maintain two prefix arrays:
  evenPrefix[i] = sum of even indices till i
  oddPrefix[i] = sum of odd indices till i

Use for:
  - Balance problems
  - Remove element and check if even/odd sum match
*/


/*
-----------------------------------------
🔹 7. 2D Prefix Sum (Matrix Problems)
-----------------------------------------
> To get sum of any submatrix in O(1)

prefix[i][j] = sum of all elements (0,0) to (i,j)
Use inclusion-exclusion for submatrix sum
*/


/*
-----------------------------------------
🔹 8. Longest Subarray with Given Sum
-----------------------------------------
> Similar to count subarrays with sum = k
But use map to store first occurrence of prefix sum
Update maxLen = max(maxLen, i - map[sum - k])
*/


/*
-----------------------------------------
🔹 9. Equilibrium Index
-----------------------------------------
> Index where:
  sum of elements left of i == sum of elements right of i

Use:
  totalSum - prefix[i] == prefix[i-1]
*/
