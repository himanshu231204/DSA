//Maximum Product Subarray in an Array

//Problem Statement: Given an array that contains both negative and positive integers, find the maximum product subarray.

/*
=============================
Brute force
============================
Approach:
Find all possible subarrays of the given array. Find the product of each subarray. Return the maximum of all them.

Following are the steps for the approach:-

Run a loop on the array to choose the start point for each subarray.
Run a nested loop to get the end point for each subarray.
Multiply elements present in the chosen range.

-----------------------
TC=O(n^3)
SC=O(1)


---------------------------------------------------
#include<bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int>& nums) {
    int result = INT_MIN;
    for(int i=0;i<nums.size()-1;i++) {
        for(int j=i+1;j<nums.size();j++) {
            int prod = 1;
            for(int k=i;k<=j;k++) 
                prod *= nums[k];
            result = max(result,prod);    
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProductSubArray(nums);
    return 0;
}

*/


/*
======================
Better Solutions
=====================

Algorithm / Intuition
Approach:
We can optimize the brute force by making 3 nested iterations to 2 nested iterations

Following are the steps for the approach:

Run a loop to find the start of the subarrays.
Run another nested loop
Multiply each element and store the maximum value of all the subarray.
---------------------
TC=O(n^2)
SC=O(1)

-----------------------



#include<bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int>& nums) {
    int result = nums[0];
    for(int i=0;i<nums.size()-1;i++) {
        int p = nums[i];
        for(int j=i+1;j<nums.size();j++) {
           result = max(result,p);
           p *= nums[j];
        }
        result = max(result,p);//manages (n-1)th term 
    }
    return result;
}

int main() {
    vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProductSubArray(nums);
    return 0;
}


*/

/*
====================================================
Optimal Solutions 1: ( using general formula)  tell this algo to intervi

🔢 Maximum Product Subarray – Observations for Optimization:

Only Positive Numbers:
→ Max product = Product of entire array.

Even Number of Negative Numbers:
→ Product remains positive → Max product = Product of entire array.

Odd Number of Negative Numbers:
→ Product becomes negative.
→ Remove one negative number (either from the start or end) to make negatives even → maximize the remaining product.

Array Contains 0s:
→ 0 breaks the product chain.
→ Split array at 0s and treat each subarray individually using above logic.

-----------------------------------
🧮 Algorithm to Find Maximum Product Subarray (Optimized using Prefix & Suffix):

Initialize:

pre = 1 (prefix product)

suff = 1 (suffix product)

ans = INT_MIN (to track max product)

Loop from i = 0 to n-1:

If pre == 0, reset pre = 1 (new subarray due to 0)

If suff == 0, reset suff = 1 (new suffix subarray due to 0)

Multiply:

pre *= arr[i]

suff *= arr[n - 1 - i]

Update: ans = max(ans, pre, suff)

Return ans as the maximum product.

----------------------------
TC=O(n)
SC=O(1)

*/




#include <bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int> &arr) {
    int n = arr.size(); //size of array.

    int pre = 1, suff = 1;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        // condition when 0 comes in arrya
        // so restart the product to 1 
        if (pre == 0) pre = 1;
        if (suff == 0) suff = 1;
        pre *= arr[i];
        suff *= arr[n - i - 1];  // multiply from last
        ans = max(ans, max(pre, suff));
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, -3, 0, -4, -5};
    cout << "The maximum product subarray is: "
         << maxProductSubArray(arr) << "\n";
    return 0;
}






