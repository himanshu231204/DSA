// Koko Eating Bananas;
/*
🐵 Monkey Eating Bananas – Problem Summary
A monkey has access to n piles of bananas, where the i-th pile contains a[i] bananas. The monkey can eat up to k bananas per hour from any one pile (if a pile has fewer than k, the monkey eats the whole pile and doesn't eat more that hour).

You are given an integer h — the maximum number of hours allowed to eat all the bananas.

🎯 Goal:
Find the minimum value of k (bananas per hour) such that the monkey can finish all the bananas from all piles within h hours.
*/

/*
/*
📝 Problem Understanding: How Koko Eats Bananas

Given:
- An array of banana piles: {3, 6, 7, 11}
- A total time limit h = 8 hours

Rules:
1. Koko can eat bananas from only one pile in an hour.
2. If a pile has fewer bananas than her eating speed `k`, she eats all and the rest of the hour is unused.
3. Time taken per pile = ceil(pile_size / k)

Example:
- If Koko eats 2 bananas/hour:
    - Pile 1: ceil(3/2) = 2 hrs
    - Pile 2: ceil(6/2) = 3 hrs
    - Pile 3: ceil(7/2) = 4 hrs
    - Pile 4: ceil(11/2) = 6 hrs
    - Total time = 15 hrs > h (8) → Not feasible

🔍 Observation:
- The **maximum** number of bananas (`k`) Koko can eat in an hour is limited by the **largest pile**.
- Therefore, the minimum value of `k` must lie in the range: [1, max(piles)].

🎯 Goal:
- Find the **minimum possible k** such that total hours to eat all bananas ≤ h.
- Use Binary Search on the answer space [1, max(piles)] to optimize.
*/




/*

======================
Brute Force ( linear Serach)
=========================
🧠 Algorithm Summary: Brute-force Approach for Banana Eating Problem
Determine the Maximum 🍌
Find the maximum number of bananas in any pile — this is the upper limit for k.

Try All Possible Eating Speeds (k = 1 to max)
Loop through all possible values of k from 1 to max(a[]).

For Each k, Calculate Total Hours Needed
Use a helper function calculateTotalHours(a[], k) to:

Loop through each pile

Compute hours = ceil(pile size / k) for each

Add all hours

Find Minimum k
Return the first value of k where total hours needed is ≤ h.

📌 Goal: Minimize k such that the monkey finishes all bananas in ≤ h hours.




#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> &v) {
    int maxi = INT_MIN;
    int n = v.size();
    //find the maximum:
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

int calculateTotalHours(vector<int> &v, int hourly) {
    int totalH = 0;
    int n = v.size();
    //find total hours:
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)(v[i]) / (double)(hourly));
    }
    return totalH;
}

int minimumRateToEatBananas(vector<int> v, int h) {
    //Find the maximum number:
    int maxi = findMax(v);

    //Find the minimum value of k:
    for (int i = 1; i <= maxi; i++) {
        int reqTime = calculateTotalHours(v, i);
        if (reqTime <= h) {
            return i;
        }
    }

    //dummy return statement
    return maxi;
}

int main()
{
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    int ans = minimumRateToEatBananas(v, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
}

----------------------------------

Time Complexity: O(max(a[]) * N),
Space Complexity: O(1
*/

/*
====================================
Optimal Approach(Using Binary Search): 
======================================

/*
🍌 Koko Eating Bananas - Binary Search Optimization

🎯 Goal:
Find the **minimum eating speed (k)** such that Koko can eat all bananas in `h` hours.

🧠 Key Insight:
- We don’t apply binary search on a sorted array, but on the **answer space** [1, max(pile)].
- The answer space is inherently sorted, so we can apply binary search there.

🧮 Algorithm Steps:
1. Determine the maximum number of bananas in any pile: max(pile).
2. Set binary search boundaries:
   - low = 1
   - high = max(pile)
3. While (low ≤ high):
   - mid = (low + high) / 2
   - totalH = total hours needed to eat all bananas at `mid` bananas/hour.
   - If totalH ≤ h → mid is a possible answer, try to minimize `k` → high = mid - 1
   - Else → mid is too small → increase `k` → low = mid + 1
4. Return `low` (it will point to the minimum feasible `k`)

🛠️ Helper Function - calculateTotalHours(piles[], hourly):
- For each pile, add ceil(pile[i] / hourly) to total time.
- Return total time.

✅ Why it works:
- Binary search efficiently narrows down the range of valid `k`.
- The loop guarantees `low` ends up at the smallest valid value satisfying the time constraint.


*/




#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> &v) {
    int maxi = INT_MIN;
    int n = v.size();
    //find the maximum:
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

int calculateTotalHours(vector<int> &v, int hourly) {
    int totalH = 0;
    int n = v.size();
    //find total hours:
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)(v[i]) / (double)(hourly));
    }
    return totalH;
}

int minimumRateToEatBananas(vector<int> v, int h) {
    int low = 1, high = findMax(v);

    //apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        int totalH = calculateTotalHours(v, mid);
        if (totalH <= h) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    int ans = minimumRateToEatBananas(v, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
}



/*     leetcode solutions

class Solution {
public:
    // Calculate total hours needed at a given speed
    long long reqtime(const vector<int>& piles, int k) {
        long long total = 0;
        for (int p : piles) {
            total += (p + k - 1LL) / k; // use 1LL to ensure no overflow
        }
        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long time = reqtime(piles, mid);

            if (time <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

*/






