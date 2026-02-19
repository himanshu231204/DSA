/*
Problem Statement: Given an integer array arr, find the contiguous subarray (containing at least one number) which
has the largest sum and returns its sum and prints the subarray.
*/

// Brute Force(Generate all sumarray and find maxsum)
/*
Intuition:

We will check the sum of every possible subarray and consider the maximum among them. 
To get every possible subarray sum, we will be using three nested loops.


Approach:
The steps are as follows:

First, we will run a loop(say i) that will select every possible starting index of the subarray. The possible starting indices can vary from index 0 to index n-1(n = size of the array).
Inside the loop, we will run another loop(say j) that will signify the ending index of the subarray. For every subarray starting from the index i, the possible ending index can vary from index i to n-1(n = size of the array).
After that for each subarray starting from index i and ending at index j (i.e. arr[i….j]), we will run another loop to calculate the sum of all the elements(of that particular subarray)

Tc=O(n^3)
SC=O(1)


#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // subarray = arr[i.....j]
            int sum = 0;

            //add all the elements of subarray:
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }

            maxi = max(maxi, sum);
        }
    }

    return maxi;
}

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}



*/

// Better solution:(Try to remove 1 loo)

/*
Intuition:

Intuition: If we carefully observe, we can notice that to get the sum of the current subarray 
we just need to add the current element(i.e. arr[j]) to the sum of the previous subarray i.e. arr[i….j-1].

Assume previous subarray = arr[i……j-1]
current subarray = arr[i…..j]
Sum of arr[i….j] = (sum of arr[i….j-1]) + arr[j]

This is how we can remove the third loop and while moving j pointer, we can calculate the sum.

TC=O(n^2)
SC=O(1)



#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            // current subarray = arr[i.....j]

            //add the current element arr[j]
            // to the sum i.e. sum of arr[i...j-1]
            sum += arr[j];

            maxi = max(maxi, sum); // getting the maximum
        }
    }

    return maxi;
}

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}


*/



// Optimal Approach (using Kadanes Algoritms)

/*
Intuition:
The intuition of the algorithm is not to consider the subarray as a part of the answer if its sum is less than 0.
 A subarray with a sum less than 0 will always reduce our answer and so this type of subarray cannot be a part of the subarray with maximum sum.

 Approach:
The steps are as follows:

We will run a loop(say i) to iterate the given array.
Now, while iterating we will add the elements to the sum variable and consider the maximum one.
If at any point the sum becomes negative we will set the sum to 0 as we are not going to consider it as a part of our answer.

TC=O(n)
SC=O(1)
*/


#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

     int start=0;
     int ansstart=-1 , ansend=-1;
    for (int i = 0; i < n; i++) {

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;

            ansstart=start;
            ansend=i;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }

       //printing the subarray:
       cout << "The subarray is: [";
       for (int i = ansstart; i <= ansend; i++) {
           cout << arr[i] << " ";
       }
       cout << "]n";
   
       // To consider the sum of the empty subarray
       // uncomment the following check:
   
       //if (maxi < 0) maxi = 0;
   
       return maxi;
   }

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}



// There might be more than one subarray with the maximum sum.
// We need to print any of them.

/*
  we carefully observe our algorithm,
  subarray always starts at the particular index where the sum variable is equal to 0, 
  at the ending index, the sum always crosses the previous maximum sum(i.e. maxi).

  so what we can do is :

  we will keep track of starting index inside loop using start variable
  ---> int start=0
   we will take variable
    ansstart=-1;
    ansend=-1;
    if(sum>maxsum){
     ansstart=start;
     ansend=current index (i)
    }
     the rest approach will be the same as kadanes algorithms
*/