
//Minimum days to make M bouquets

/*
Problem Statement: You are given 'N’ roses and you are also given an array 'arr'  where 'arr[i]'  denotes that the 'ith' rose will bloom on the 'arr[i]th' day.
You can only pick already bloomed roses that are adjacent to make a bouquet. You are also told that you require exactly 'k' adjacent bloomed roses to make a single bouquet.
Find the minimum number of days required to make at least ‘m' bouquets each containing 'k' roses. Return -1 if it is not possible.
*/

/*
/*
Problem Summary:
----------------
We are given an array `bloomDay` where each element represents the day a flower blooms.
We need to make 'm' bouquets with 'k' adjacent flowers each.
Our goal is to find the minimum day when it is possible to make all 'm' bouquets.
If it's not possible, return -1.

Key Observations:
-----------------
1. Impossible Case:
   If total flowers needed (m * k) > bloomDay.size(), return -1.

2. Answer Range:
   - Minimum possible day = min(bloomDay)
   - Maximum possible day = max(bloomDay)
   So, our answer lies in the range [min, max].

Bouquet Check Function (possible()):
------------------------------------
- Initialize count of adjacent bloomed flowers (cnt) and bouquet count (noOfB).
- Loop through the bloomDay array:
    - If bloomDay[i] <= current day, increment cnt.
    - If cnt reaches k, increment bouquet count and reset cnt.
    - If bloomDay[i] > current day, reset cnt to 0.
- After loop, check if bouquets formed (noOfB) >= m.

-------------                     -----------
bool posday(vector<int>& bloomDay, int day, int m, int k) {
        int cnt = 0;
        int bouquets = 0;
        
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                cnt++;
                if (cnt == k) {
                    bouquets++;
                    cnt = 0; // reset for next bouquet
                }
            } else {
                cnt = 0; // reset streak if day not satisfied
            }
        }

        return bouquets >= m;
    }
-------------------------------
Binary Search Approach:
-----------------------
- Apply binary search in the range [min, max].
- For each mid (day), check if possible(mid) returns true:
    - If yes, store mid as a possible answer and search for smaller days.
    - If no, search for larger days.
- Return the minimum day when possible() is true.
*/



//====================================


/*
=======================================
Naive Approach (Brute Force):
=====================================
We try every day from min(bloomDay) to max(bloomDay) and check if it's possible to make 'm' bouquets.

Algorithm:
----------
1. If m * k > bloomDay.size(), return -1 (not enough flowers).
2. Loop from day = min(bloomDay) to max(bloomDay):
   - For each day, call possible(bloomDay, day, m, k).
   - If possible() returns true, return current day as the answer.
3. If loop completes without returning, return -1 (no valid day found).

Note:
-----
This approach has high time complexity and is not optimal for large inputs.
Use binary search for a better solution.


-----------------------------------




#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> &arr, int day, int m, int k) {
    int n = arr.size(); //size of the array
    int cnt = 0;
    int noOfB = 0;
    // count the number of bouquets:
    for (int i = 0; i < n; i++) {
        if (arr[i] <= day) {
            cnt++;
        }
        else {
            noOfB += (cnt / k);
            cnt = 0;
        }
    }
    noOfB += (cnt / k);
    return noOfB >= m;
}
int roseGarden(vector<int> arr, int k, int m) {
    long long val = m * 1ll * k * 1ll;
    int n = arr.size(); //size of the array
    if (val > n) return -1; //impossible case.
    //find maximum and minimum:
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }

    for (int i = mini; i <= maxi; i++) {
        if (possible(arr, i, m, k))
            return i;
    }
    return -1;
}

int main()
{
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int k = 3;
    int m = 2;
    int ans = roseGarden(arr, k, m);
    if (ans == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << ans << "\n";
    return 0;
}

------------------------
/*
Time Complexity:
----------------
O((max(arr[]) - min(arr[]) + 1) * N)
- We iterate through all possible days in the range [min, max].
- For each day, we check the entire array in the possible() function => O(N).

Space Complexity:
-----------------
O(1)
- No extra space is used beyond a few variables.
*/




/*
===========================================
Optimized Approach (Binary Search on Answer):
==========================================
/*

---------------------------------------------


Algorithm:
----------
1. If m * k > bloomDay.size(), return -1 (not enough flowers).
2. Initialize:
   - low = min(bloomDay)
   - high = max(bloomDay)
3. While low <= high:
   - mid = (low + high) / 2
   - If possible(bloomDay, mid, m, k) returns true:
       -> mid is a valid answer, but we try for smaller (high = mid - 1)
   - Else:
       -> mid is too small, try larger (low = mid + 1)
4. Return low as the minimum day when 'm' bouquets can be made.
*/





#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> &arr, int day, int m, int k) {
    int n = arr.size(); //size of the array
    int cnt = 0;
    int noOfB = 0;
    // count the number of bouquets:
    for (int i = 0; i < n; i++) {
        if (arr[i] <= day) {
            cnt++;
            if(cnt==k){
                noOfB++;
                cnt=0;
            }
        }
        else {
            
            cnt = 0;
        }
    }
   
    return noOfB >= m;
}
int roseGarden(vector<int> arr, int k, int m) {
    long long val = m * 1ll * k * 1ll; // avoiding overflow
    int n = arr.size(); //size of the array
    if (val > n) return -1; //impossible case.
    //find maximum and minimum:
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }

    //apply binary search:
    int low = mini, high = maxi;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (possible(arr, mid, m, k)) {
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return low;
}

int main()
{
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int k = 3;
    int m = 2;
    int ans = roseGarden(arr, k, m);
    if (ans == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << ans << "\n";
    return 0;
}





