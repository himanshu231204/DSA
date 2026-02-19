//Aggressive Cows 

/*
Problem Statement: You are given an array 'arr' of size 'n' which denotes the position of stalls.
You are also given an integer 'k' which denotes the number of aggressive cows.
You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.
Find the maximum possible minimum distance.
*/

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
Why do we need to sort the stalls?

To place the cows with a certain minimum distance between them,
we must sort the stall positions first.

Key Reason:
- Sorting ensures that we can try placing cows in order and 
  calculate the minimum distance correctly between any two cows.
- In a sorted array, the closest distance will always occur between 
  two adjacent stalls, which helps in applying the greedy placement strategy.

Note:
- Placing cows in consecutive order does NOT mean placing them in 
  adjacent stalls, but in increasing order of stall positions.

Sorting is crucial for applying Binary Search and Greedy efficiently.
*/


/*
🔍 Observation:

Minimum possible distance between 2 cows:
- The smallest valid distance is 1 (minimum possible gap between two stalls).

Maximum possible distance between 2 cows:
- The largest valid distance is max(stalls[]) - min(stalls[]).
- This happens when cows are placed at the two ends of the stall array.

➡️ So, the answer lies in the range: [1, max(stalls[]) - min(stalls[])].

📌 How to check if cows can be placed with a minimum distance 'dist':

Approach:
1. Always place the first cow in the first stall.
2. Traverse the sorted array and place the next cow only if the gap from the last placed cow is >= dist.
3. Repeat this until all cows are placed or we reach the end.

Function: canWePlace(stalls[], dist, k)
- cntCows → Number of cows placed (initially 1)
- last → Position of the last cow placed (initially stalls[0])

Loop through the stalls from index 1:
- If (stalls[i] - last) >= dist:
    - Place a cow at stalls[i]
    - Increment cntCows
    - Update last = stalls[i]

- If cntCows >= k → return true (placement possible)
- If loop ends and cntCows < k → return false (placement not possible)
*/

/*
================================
Brute Force( linear search)
===================================




#include <bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> &stalls, int dist, int cows) {
    int n = stalls.size(); //size of array
    int cntCows = 1; //no. of cows placed
    int last = stalls[0]; //position of last placed cow.
    for (int i = 1; i < n; i++) {
        if (stalls[i] - last >= dist) {
            cntCows++; //place next cow.
            last = stalls[i]; //update the last location.
        }
        if (cntCows >= cows) return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k) {
    int n = stalls.size(); //size of array
    //sort the stalls[]:
    sort(stalls.begin(), stalls.end());

    int limit = stalls[n - 1] - stalls[0];
    for (int i = 1; i <= limit; i++) {
        if (canWePlace(stalls, i, k) == false) {
            return (i - 1);
        }
    }
    return limit;
}

int main()
{
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}


/*
🧠 Complexity Analysis:

⏱️ Time Complexity:
O(NlogN) + O(N * (max(stalls[]) - min(stalls[])))
- O(NlogN) → for sorting the stalls array.
- The loop runs from 1 to max(stalls[]) - min(stalls[]) to test all possible distances.
- For each distance, the canWePlace() function is called which takes O(N) time.

So overall time: Sorting + (Distance Range Iterations × Array Traversal)

🗃️ Space Complexity:
O(1)
- We are not using any additional data structures or space.
- The solution is done in-place with constant space.
*/


/*
===============================
Optimal Solutions (BS on answer)
====================================
/*
🧠 Complexity Analysis:

⏱️ Time Complexity:
O(NlogN) + O(N * log(max(stalls[]) - min(stalls[])))
- O(NlogN): for sorting the stalls array.
- O(log(max - min)): for binary search over the possible distance range.
- O(N): for each call to canWePlace() during binary search.

So overall time = Sorting + (Binary Search Iterations × Stall Traversal)

🗃️ Space Complexity:
O(1)
- No extra space is used; constant space solution.
*/




#include <bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> &stalls, int dist, int cows) {
    int n = stalls.size(); //size of array
    int cntCows = 1; //no. of cows placed
    int last = stalls[0]; //position of last placed cow.
    for (int i = 1; i < n; i++) {
        if (stalls[i] - last >= dist) {
            cntCows++; //place next cow.
            last = stalls[i]; //update the last location.
        }
        if (cntCows >= cows) return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k) {
    int n = stalls.size(); //size of array
    //sort the stalls[]:
    sort(stalls.begin(), stalls.end());

    int low = 1, high = stalls[n - 1] - stalls[0];
    //apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canWePlace(stalls, mid, k) == true) {
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return high;
}

int main()
{
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}

