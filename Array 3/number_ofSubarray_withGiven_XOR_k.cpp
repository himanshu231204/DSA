//Problem Statement: Given an array of integers A and an integer B. Find the total number of subarrays having bitwise XOR of all elements equal to k.

/*
=======================================
Brute Force
===========================================

🧠 Intuition:
We want to count how many subarrays have XOR equal to k.

We check every possible subarray, calculate its XOR, and increase the count if it matches k.

🛠️ Approach:
Generate Subarrays:

Use two nested loops:

i: starting index (0 to n-1)

j: ending index (i to n-1)

Calculate XOR:

For each subarray [i...j], use a third loop to compute XOR of all elements in this range.

Check and Count:

If the calculated XOR equals k, increment the counter.

⏱️ Time Complexity:
O(n³) due to three nested loops:

Two for subarray selection

One for XOR calculation

---------------------------------------------------



#include <bits/stdc++.h>
using namespace std;

int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); //size of the given array.
    int cnt = 0;

    // Step 1: Generating subarrays:
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {

            //step 2:calculate XOR of all
            // elements:
            int xorr = 0;
            for (int K = i; K <= j; K++) {
                xorr = xorr ^ a[K];
            }

            // step 3:check XOR and count:
            if (xorr == k) cnt++;
        }
    }
    return cnt;
}

int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}




*/

/*
====================================
Better Solutions
======================================

💡 Key Insight:
Instead of recalculating XOR for every subarray from scratch, use the previously computed XOR.

For subarray arr[i…j], we can derive its XOR using:
XOR(arr[i…j]) = XOR(arr[i…j-1]) ^ arr[j]

✅ Benefit:
This removes the third loop used to calculate XOR.

Now, XOR can be updated incrementally as j increases.

⚙️ Result:
Reduces time complexity from O(n³) to O(n²).

Makes the brute-force approach significantly more efficient.

------------------------------------------------



#include <bits/stdc++.h>
using namespace std;

int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); //size of the given array.
    int cnt = 0;

    // Step 1: Generating subarrays:
    for (int i = 0; i < n; i++) {
        int xorr = 0;
        for (int j = i; j < n; j++) {

            //step 2:calculate XOR of all
            // elements:
            xorr = xorr ^ a[j];

            // step 3:check XOR and count:
            if (xorr == k) cnt++;
        }
    }
    return cnt;
}

int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}





*/




/*
==================================
Optimal Solutions
====================================

🔍 Intuition:
We use the concept of prefix XOR.

Let the XOR of a subarray ending at index i be xr.

To find subarrays with XOR equal to k, we observe:

If xr ^ k exists as a prefix XOR, then the subarray between that
 prefix and index i has XOR = k.

 ---------------------

 🧠 Approach:
Initialize a map (dictionary) to store frequency of prefix XORs.

Initialize xr = 0 (current prefix XOR) and count = 0 (answer).

Loop through each element in the array:

Update prefix XOR: xr = xr ^ arr[i]

If xr == k, increment count by 1 (whole subarray till i has XOR k)

Check if xr ^ k exists in map:

If yes, add its frequency to count

Store/update the frequency of xr in the map

After the loop, count holds the total number of subarrays with XOR = k.
*/




#include <bits/stdc++.h>
using namespace std;

int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); //size of the given array.
    int xr = 0;
    map<int, int> mpp; //declaring the map.
    mpp[xr]++; //setting the value of 0.
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        // prefix XOR till index i:
        xr = xr ^ a[i];

        //By formula: x = xr^k:
        int x = xr ^ k;

        // add the occurrence of xr^k
        // to the count:
        cnt += mpp[x];

        // Insert the prefix xor till index i
        // into the map:
        mpp[xr]++;
    }
    return cnt;
}

int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}

