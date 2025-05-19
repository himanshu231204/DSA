// Kadanes Algorithms

/* Intiution Of kadanes algo:

 Algorithms intution is simple if the 
 subaray (sum<0) it will not consider as answer.

 Note:
 A subarrray (sum<0) will always reduce our answer
 and so this types of subarray cannot be
 part of the subarraywith maximum sum.

 Approach i simple-->
 > run loop to iterate the array

 > while iterating add the elemnt to 
 the sum varible and consider the maximum one

 >if at any point (sum<0),we will set sum=0
 and we are not going to consider it as paert of answer

 > if at any point (sum>maxsum) update maxsum=sum

*/

#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    for (int i = 0; i < n; i++) {

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }

    // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;

    return maxi;
}



// ✅ Problem Types where Kadane's Algorithm is Used:
/*
1) Maximum Subarray Sum
2)Maximum Profit/Loss in a Range
3) Maximum Length Subarray with Positive Sum (variation)

4)Maximum Subarray with at most K negatives/zeros (advanced kadane)
5)Maximum Sum Rectangle in 2D Matrix (Extended Kadane in 2D)
6)Maximum Energy Burst in Signals / Sensors
7)Maximum Scoring Streak in Games
8)Temperature/Weather Data Analysis
*/