//Finding Sqrt of a number using Binary Search

//Problem Statement: You are given a positive integer n. Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of 'sqrt(n)'

/*
==============================
Brute Force  ( Linear Search)
===============================




#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int n) {
    int ans = 0;
    //linear search on the answer space:
    for (long long i = 1; i <= n; i++) {
        long long val = i * i;
        if (val <= n * 1ll) {
            ans = i;
        } else {
            break;
        }
    }
    return ans;
}

int main()
{
    int n = 28;
    int ans = floorSqrt(n);
    cout << "The floor of square root of " << n
         << " is: " << ans << "\n";
    return 0;
}

------------------------------------------------------------------------------------------

Complexity Analysis:

Time Complexity: O(N), N = the given number.
Space Complexity: O(1) as we are not using any extra space.
*/

/*
====================================================
Optimal Solutions-1 ( using in-built sqrt() function)
=======================================================




#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int n) {
    int ans = sqrt(n);
    return ans;
}

int main()
{
    int n = 28;
    int ans = floorSqrt(n);
    cout << "The floor of square root of " << n
         << " is: " << ans;
    return 0;
}

---------------------------------------
TC=O(logN)
SC=O(1)
*/


/*
====================================================
Optimal Solutions-2 ( using binary search)
=======================================================

// ✅ Algorithm / Intuition
// Binary Search on Answer Space (Not Array Elements)
//
// We are NOT given a sorted array,
// but we can apply Binary Search on a **virtual answer space**.

// ✨ Key Insight:
// The array may not be sorted, but the possible *range of answers* [1, n] is sorted.
// So, instead of searching in the array, we apply binary search over the answer space.

1. // Define the low and high bounds of the answer space:
   int low = 1;
   int high = n;

2. // In each iteration, calculate mid:
   int mid = (low + high) / 2;

3. // Use a condition to check if mid could be the answer.
   // Based on this condition, eliminate the half where the answer can't exist:
   - If condition satisfied → high = mid
   - Else → low = mid + 1;

4. // After loop ends, 'low' will point to the correct answer.


*/

#include <bits/stdc++.h>
using namespace std;
 
int floorsqrt(int n){

    int low=1;
    int high=n;
    int ans=0;

    while(low<=high){
        // to avoid over flow use long long
        long long mid=(low+high)/2;

        if(mid*mid<=n){
            ans=mid;
            low=mid+1;

        }
        else{
            high=mid-1;
        }
    }
    return ans;
}
int main(){
     int n;
    cin>>n;
    int result=floorsqrt( n);

    cout<< "The floor of square root of "<< n <<" is "<<result<<"\n";
    return 0;
}