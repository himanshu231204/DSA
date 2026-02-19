// Capacity to Ship Packages within D Days

/*
📦 Problem Summary: Ship Packages Within D Days
You are managing a shipping company. Packages (given as an array of weights) must be shipped in order using a conveyor system, and within d days.

Each day, packages are loaded sequentially (in the given order).

The total weight loaded each day must not exceed a fixed ship capacity.

Your goal: Find the minimum ship capacity needed to ship all packages within d days.

🧠 Core Idea:
Determine the smallest possible weight capacity of the ship such that all packages can be shipped in at most d days, without breaking the sequence or exceeding the daily weight limit.

*/
//=========================================================================================================================================================================================================================================================

/*
🔍 Observation:

1. Minimum Ship Capacity:
   - Must be at least max(weights[]).
   - Reason: If any weight exceeds the ship capacity, it can never be shipped.
   - Example: If weights = {1,2,3,...,10}, capacity < 10 won't ship last item.

2. Maximum Ship Capacity:
   - Can be sum(weights[]), i.e., ship everything in one day.
   - Any value above sum(weights[]) behaves the same.

✅ So, the answer lies in the range:
   [max(weights[]), sum(weights[])]

🛠 How to compute days required for a given capacity:

We define a helper function:

int findDays(vector<int>& weights, int cap)
{
    // Initialize number of days and current day's load
    int days = 1, load = 0;

    // Iterate through each weight
    for (int w : weights)
    {
        if (load + w > cap)
        {
            // Start a new day
            days++;
            load = w; // Load current item in new day
        }
        else
        {
            load += w; // Continue loading in current day
        }
    }

    return days;
}
*/


/*==============================
🐢 Naive Approach:
==================================================
- We brute-force all possible ship capacities from max(weights[]) to sum(weights[]).
- The smallest capacity that allows shipping all packages within 'd' days is the answer.

🧠 Algorithm:

1. Loop through all possible capacities (cap) from max(weights[]) to sum(weights[]).
2. For each 'cap', call the helper function `findDays(weights, cap)` to get the number of days needed.
3. The first capacity for which `days <= d` will be our answer.

🔁 Pseudocode:
for (int cap = maxWeight; cap <= sumWeight; cap++) {
    if (findDays(weights, cap) <= d) {
        return cap; // Minimum valid capacity found
    }
}

/*
📊 Complexity Analysis:

🕒 Time Complexity:
O(N * (sum(weights[]) - max(weights[]) + 1))
- Outer loop: Runs from max(weights[]) to sum(weights[]) => up to (sum - max + 1) iterations.
- Inner operation: findDays() runs in O(N) for each capacity checked.
- Total = (range of capacities) * (array size)

🧠 Variables:
- N = number of packages (size of weights array)
- sum(weights[]) = total weight of all packages
- max(weights[]) = heaviest individual package

🧠 Example:
If weights = {1, 2, ..., 10}, then:
- max = 10
- sum = 55
- Loop runs from 10 to 55 => 46 iterations
- Each iteration processes N items

🗃 Space Complexity:
O(1)
- No extra space used beyond a few variables.

------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

int findDays(vector<int> &weights, int cap) {
    int days = 1; //First day.
    int load = 0;
    int n = weights.size(); //size of array.
    for (int i = 0; i < n; i++) {
        if (load + weights[i] > cap) {
            days += 1; //move to next day
            load = weights[i]; //load the weight.
        }
        else {
            //load the weight on the same day.
            load += weights[i];
        }
    }
    return days;
}

int leastWeightCapacity(vector<int> &weights, int d) {
    //Find the maximum and the summation:
    int maxi = *max_element(weights.begin(), weights.end());
    int sum = accumulate(weights.begin(), weights.end(), 0);

    for (int i = maxi; i <= sum; i++) {
        if (findDays(weights, i) <= d) {
            return i;
        }
    }
    //dummy return statement:
    return -1;
}

int main()
{
    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    int d = 5;
    int ans = leastWeightCapacity(weights, d);
    cout << "The minimum capacity should be: " << ans << "\n";
    return 0;
}
*/

//************************************************************************************************************** */

/*
🚀 Optimal Approach (Using Binary Search):

🔍 Core Idea:
- We apply binary search not on a sorted array, but on the **answer space**: [max(weights[]), sum(weights[])].
- This range is sorted because a higher capacity always leads to fewer required days.
- Our goal is to find the minimum ship capacity that allows shipping within 'd' days.

🧠 Algorithm:
1. Calculate:
   - maxW = max(weights[]) // Minimum possible capacity
   - sumW = sum(weights[]) // Maximum possible capacity

2. Initialize pointers:
   - low = maxW
   - high = sumW

3. Binary Search Loop:
   while (low <= high):
     - mid = (low + high) // 2
     - days = findDays(weights, mid)

     - If days <= d:
         // mid might be a valid (but not minimal) answer
         high = mid - 1
     - Else:
         // mid is too small, try bigger capacities
         low = mid + 1

4. Return:
   - Final answer = low (smallest capacity to ship within 'd' days)

🛠 Helper Function: findDays(weights[], cap)
- Tracks how many days are needed if the ship has capacity 'cap'.
- Adds weights one by one, starts new day if load exceeds capacity.

📦 Example:
weights[] = {1,2,3,4,5,6,7,8,9,10}, d = 5
Answer space = [10, 55]

✅ Efficient, because we only check ~log(sum - max) capacity values.
*/
/*
📊 Complexity Analysis (Optimized using Binary Search):

🕒 Time Complexity:
O(N * log(sum(weights[]) - max(weights[]) + 1))
- We perform binary search on the range [max(weights[]), sum(weights[])].
- Binary Search takes log(sum - max + 1) time.
- For each mid value, we call findDays(), which runs in O(N) time.
- Total = O(N * log(range of capacities))

🧠 Variables:
- N = number of packages
- max(weights[]) = heaviest package (minimum ship capacity)
- sum(weights[]) = total weight of all packages (maximum ship capacity)

🗃 Space Complexity:
O(1)
- No additional space used, only variables for computation.

⚡️ Efficient and optimal for large inputs.
*/





#include <bits/stdc++.h>
using namespace std;

int findDays(vector<int> &weights, int cap) {
    int days = 1; //First day.
    int load = 0;
    int n = weights.size(); //size of array.
    for (int i = 0; i < n; i++) {
        if (load + weights[i] > cap) {
            days += 1; //move to next day
            load = weights[i]; //load the weight.
        }
        else {
            //load the weight on the same day.
            load += weights[i];
        }
    }
    return days;
}

int leastWeightCapacity(vector<int> &weights, int d) {
    //Find the maximum and the summation:
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    while (low <= high) {
        int mid = (low + high) / 2;
        int numberOfDays = findDays(weights, mid);
        if (numberOfDays <= d) {
            //eliminate right half
            high = mid - 1;
        }
        else {
            //eliminate left half
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    int d = 5;
    int ans = leastWeightCapacity(weights, d);
    cout << "The minimum capacity should be: " << ans << "\n";
    return 0;
}










