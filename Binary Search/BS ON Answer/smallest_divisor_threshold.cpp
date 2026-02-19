// Find the Smallest Divisor Given a Threshold

/*
Problem Statement: You are given an array of integers 'arr' and an integer i.e. a threshold value 'limit'. 
Your task is to find the smallest positive integer divisor, such that upon dividing all the elements of the 
given array by it, the sum of the division's result is less than or equal to the given threshold value.
*/

//=====================================================================================================================================================

/*
✅ Key Points:
Ceiling Division: While dividing array elements by a number, always take the ceiling (e.g., 3 / 2 = 2).

Minimum Divisor:
The minimum possible divisor is always 1, the smallest positive integer.

Maximum Divisor:
The maximum possible divisor is max(arr[]), because any divisor greater than this will behave the same as max(arr[]).

🔍 Final Observation:
The optimal answer will always lie within the range:
[1, max(arr[])]

This forms the search space for applying binary search efficiently.
*/

/*
===================================
Naive Approach(Brute-force): 
=====================================
🔁 Naive Brute-Force Approach:
Idea: Try all possible divisors from 1 to max(arr[]) and find the smallest divisor for which the total sum of ceiling divisions is less than or equal to the threshold.

🧠 Algorithm Steps:
Loop over all divisors d from 1 to max(arr[]).

For each d, calculate total:
sum += ceil(arr[i] / d) for all elements.

If the sum ≤ threshold, return d as the answer.

If no such d is found, return -1.

⛔ Drawback:
Inefficient for large arrays or values, since it checks all max(arr[]) possible divisors.


-------------------------------------------------



#include <bits/stdc++.h>
using namespace std;

int smallestDivisor(vector<int>& arr, int limit) {
    int n = arr.size(); //size of array.
    //Find the maximum element:
    int maxi = *max_element(arr.begin(), arr.end());

    //Find the smallest divisor:
    for (int d = 1; d <= maxi; d++) {
        //Find the summation result:
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ceil((double)(arr[i]) / (double)(d));
        }
        if (sum <= limit)
            return d;
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;
    int ans = smallestDivisor(arr, limit);
    cout << "The minimum divisor is: " << ans << "\n";
    return 0;
}

--------------------------------------------------------
🧮 Complexity Analysis – Naive Approach
Time Complexity:
O(max(arr[]) × N)

Outer loop runs from 1 to max(arr[])

Inner loop runs N times (size of array)

Space Complexity:
O(1)

No extra data structures used; only variables for computation
*/

/*

==========================
Optimal Approach(Using Binary Search): 
=====================================================
✅ Summary: Optimized Approach Using Binary Search
We use Binary Search on the answer space instead of the array itself.

🔍 Key Observations:
The array is not sorted, but the answer space [1, max(arr[])] is sorted.

We're trying to minimize a divisor such that the sum of ceilings of array elements divided by it is ≤ threshold.

🧠 Intuition:
If n > threshold, return -1 immediately — it's impossible to meet the condition.

Else, binary search the divisor space [1, max(arr[])]:

For each candidate mid, calculate the sum of ceil(arr[i] / mid).

If that sum is ≤ threshold, it's a potential answer → move left to find smaller divisors.

Otherwise, move right to try larger divisors.

🧮 Algorithm Steps:
Edge Case Check: If n > threshold, return -1.

Initialize Search Range:

low = 1, high = max(arr[])

Binary Search Loop:

mid = (low + high) // 2

Compute sumByD(mid)

If sum ≤ threshold: move left → high = mid - 1

Else: move right → low = mid + 1

Return low as the minimum valid divisor.


-----------------
Time Complexity:
Olog(max(arr[]) × N)

*/



#include <bits/stdc++.h>
using namespace std;

int sumByD(vector<int> &arr, int div) {
    int n = arr.size(); //size of array
    //Find the summation of division values:
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ceil((double)(arr[i]) / (double)(div));
    }
    return sum;
}

int smallestDivisor(vector<int>& arr, int limit) {
    int n = arr.size();
    if (n > limit) return -1;
    int low = 1, high = *max_element(arr.begin(), arr.end());

    //Apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (sumByD(arr, mid) <= limit) {
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
    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;
    int ans = smallestDivisor(arr, limit);
    cout << "The minimum divisor is: " << ans << "\n";
    return 0;
}


