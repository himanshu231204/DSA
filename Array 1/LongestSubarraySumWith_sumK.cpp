// Problem Statement: Given an array and a sum k, we need to print the length of the longest subarray that sums to k.

/*
Solution 1:
Naive Approach (Brute-force approach): 
Here, in this approach, we are going to generate all possible subarrays to solve this problem.

How to generate all possible subarrays?

We will select all possible starting indices(say i) and all possible ending indices(say j) to generate all possible subarrays. 
The possible starting indices i.e. i can vary from index 0 to index n-1(i.e. The last index). For every index i, the possible
 ending index j can vary from i to n-1. So, the nested loops to generate all possible subarrays will be like the following:

       for(i=0;i<n;i++){ // starting index
       for(j=i;j<n;j++) // ending index
       // subarray=arr[i...j]
       }

Approach:
The steps are as follows:

First, we will run a loop(say i) that will select every possible starting index of the subarray. The possible starting indices can vary from index 0 to index n-1(n = size of the array).
Inside the loop, we will run another loop(say j) that will signify the ending index of the subarray. For every subarray starting from the index i, the possible ending index can vary from index i to n-1(n = size of the array).
After that for each subarray starting from index i and ending at index j (i.e. arr[i….j]), we will run another loop to calculate the sum of all the elements(of that particular subarray).
If the sum is equal to k, we will consider its length i.e. (j-i+1). Among all such subarrays, we will consider the maximum length by comparing all the lengths.

Intuition:
We will check the sum of every possible subarray and consider the one with the sum k and the maximum length among them. To get every possible subarray sum, we will be using three nested loops. The first loops(say i and j) will iterate over every possible starting index and ending index of a subarray. Basically, in each iteration, the subarray range will be from index i to index j. Using another loop we will get the sum of the elements of the subarray [i…..j]. Among all the subarrays with sum k, we will consider the one with the maximum length.

Note: We are selecting every possible subarray using two nested loops and for each of them, we add all its elements using another loop.

Complexity Analysis

Time Complexity: O(N3) approx., where N = size of the array.
Reason: We are using three nested loops, each running approximately N times.

Space Complexity: O(1) as we are not using any extra space







#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    int len = 0;
    for (int i = 0; i < n; i++) { // starting index
        for (int j = i; j < n; j++) { // ending index
            // add all the elements of
            // subarray = a[i...j]:
            long long s = 0;
            for (int K = i; K <= j; K++) {
                s += a[K];
            }

            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}

int main()
{
    vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}


*/


// Better Approach(Using Hashing):   Longest Subarray with sum K | [Postives and Negatives]  Then this is the optimal solution in this case

/*
Approach:
The steps are as follows:

First, we will declare a map to store the prefix sums and the indices.
Then we will run a loop(say i) from index 0 to n-1(n = size of the array).
For each index i, we will do the following:

We will add the current element i.e. a[i] to the prefix sum.
If the sum is equal to k, we should consider the length of the current subarray i.e. i+1. We will compare this length with the existing length and consider the maximum one.
We will calculate the prefix sum i.e. x-k, of the remaining subarray.
If that sum of the remaining part i.e. x-k exists in the map, we will calculate the length i.e. i-preSumMap[x-k], and consider the maximum one comparing it with the existing length we have achieved until now.
If the sum, we got after step 3.1, does not exist in the map we will add that with the current index into the map. We are checking the map before insertion because we want the index to be as minimum as possible and so we will consider the earliest index where the sum x-k has occurred. [Detailed discussion in the edge case section]


In this approach, we are using the concept of the prefix sum to solve this problem. Here, the prefix sum of a subarray ending at index i, simply means the sum of all the elements of that subarray.

Observation: Assume, the prefix sum of a subarray ending at index i is x.
 In that subarray, we will search for another subarray ending at index i,
  whose sum equals k. Here, we need to observe that if there exists another subarray ending at index i with sum k, 
  then the prefix sum of the rest of the subarray will be x-k. 

Now, for a subarray ending at index i with the prefix sum x, if we remove the part with the prefix sum x-k, we will be left with the part whose sum is equal to k. And that is what we want.

That is why, instead of searching the subarrays with sum k, we will keep track of the prefix sum of the subarrays generated at every index using a map data structure. 

In the map, we will store every prefix sum calculated, with its index in a <key, value> pair. Now, at index i, we just need to check the map data structure to get the index i.e. preSumMap[x-k] where the subarrays with the prefix sum x-k occur. Then we will simply subtract the index i.e. preSumMap[x-k] from the current index i to get the length of the subarray i.e. len = i -preSumMap[x-k].

We will apply the above process for all possible indices of the given array. The possible values of the index i can be from 0 to n-1(where n = size of the array).

Edge Case: Why do we need to check the map if the prefix sum already exists? In the algorithm, we have seen that at step 3.4, we are checking the map if the prefix sum already exists, and if it does we are not updating it.




          ----------------Pseudo Code ---------------

    Function getLongestSubarray(array, k):

    Initialize:
        sum = 0                 // running total (prefix sum)
        maxLen = 0              // stores maximum subarray length
        map = empty             // stores first occurrence of each prefix sum

    Loop through the array using index i from 0 to array.length - 1:
        Add array[i] to sum

        If sum == k:
            maxLen = i + 1      // from index 0 to i, full subarray sum is k

        remaining = sum - k     // this is the part we want to find before current i

        If map contains 'remaining':
            subarray_length = i - map[remaining]
            Update maxLen = maximum of (maxLen, subarray_length)

        If sum is not already in map:
            map[sum] = i        // store the first time this sum appears

    Return maxLen
----------------------------------
Complexity Analysis

Time Complexity: O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array.
Reason: For example, if we are using an unordered_map data structure in C++ the time complexity will be O(N)(though in the worst case, unordered_map takes O(N) to find an element and the time complexity becomes O(N2)) but if we are using a map data structure, the time complexity will be O(N*logN). The least complexity will be O(N) as we are using a loop to traverse the array.

Space Complexity: O(N) as we are using a map data structure.






#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        //calculate the prefix sum till index i:
        sum += a[i];

        // if the sum = k, update the maxLen:
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of remaining part i.e. x-k:
        long long rem = sum - k;

        //Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        //Finally, update the map checking the conditions:
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}

int main()
{
    vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}

*/

// Optimal Approach (Using 2 pointers): 

/*
Approach:
The steps are as follows:

First, we will take two pointers: left and right, initially pointing to the index 0.
The sum is set to a[0] i.e. the first element initially.
Now we will run a while loop until the right pointer crosses the last index i.e. n-1.
Inside the loop, we will do the following:
We will use another while loop and it will run until the sum is lesser or equal to k.
Inside this second loop, from the sum, we will subtract the element that is pointed by the left pointer and increase the left pointer by 1.
After this loop gets completed, we will check if the sum is equal to k. If it is, we will compare the length of the current subarray i.e. (right-left+1) with the existing one and consider the maximum one.
Then we will move forward the right pointer by 1. If the right pointer is pointing to a valid index(< n) after the increment, we will add the element i.e. a[right] to the sum.
Finally, we will return the maximum length.

Intuition: We are using two pointers i.e. left and right. The left pointer denotes the starting index of the subarray and the right pointer denotes the ending index. Now as we want the longest subarray, we will move the right pointer in a forward direction every time adding the element i.e. a[right] to the sum. But when the sum of the subarray crosses k, we will move the left pointer in the forward direction as well to shrink the size of the subarray as well as to decrease the sum. Thus, we will consider the length of the subarray whenever the sum becomes equal to k.
The below dry run will clarify the intuition.

---------------Pseudo Code--------------------

Input: array of numbers, target sum k
Output: Length of the longest subarray with sum exactly k

1. Set:
   - left = 0     → start of the window
   - right = 0    → end of the window
   - sum = array[0]
   - maxLen = 0   → stores the longest subarray length

2. While right is within array bounds:
   a. If sum > k:
      - Shrink window from the left:
        While sum > k and left <= right:
            Subtract array[left] from sum
            Move left forward by 1

   b. If sum == k:
      - Update maxLen as max of current maxLen and window size (right - left + 1)

   c. Move right forward by 1
      - If right is still inside array, add array[right] to sum

3. Return maxLen


*/




#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    int left = 0, right = 0; // 2 pointers
    long long sum = a[0];
    int maxLen = 0;
    while (right < n) {
        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        // if sum = k, update the maxLen i.e. answer:
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        // Move forward thw right pointer:
        right++;
        if (right < n) sum += a[right];
    }

    return maxLen;
}

int main()
{
    vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}

/*
Complexity Analysis

Time Complexity: O(2*N), where N = size of the given array.
Reason: The outer while loop i.e. the right pointer can move up to index n-1(the last index). Now, the inner while loop i.e. the left pointer can move up to the right pointer at most. So, every time the inner loop does not run for n times rather it can run for n times in total. So, the time complexity will be O(2*N) instead of O(N2).

Space Complexity: O(1) as we are not using any extra space.

*/