// Leaders in an Array

//  Problem Statement: Given an array, print all the elements which are leaders. 
// A Leader is an element that is greater than all of the elements on its right side in the array.

//==========================================================================================================

// Brute Force Approach

//=============================================

/*
Intuition:
There is no special intuition needed here. Just a common fact that we need to compare elements in order to find the greatest is more than enough.

Brute Force Approach –
Use two nested loops:

The outer loop goes through each element from left to right.

The inner loop checks if any element to the right is greater than the current element.

If a greater element is found on the right, the current element is not a leader.

If no greater element is found, the current element is a leader and added to the resul




Complexity Analysis

Time Complexity: O(N^2) { Since there are nested loops being used, at the worst case n^2 time would be consumed }.

Space Complexity: O(N) { There is no extra space being used in this approach. But, a O(N) of space for ans array will be used in the worst case }.



#include<bits/stdc++.h>
using namespace std;

vector<int> printLeadersBruteForce(int arr[], int n) {

  vector<int> ans;
  
  for (int i = 0; i < n; i++) {
    bool leader = true;

    //Checking whether arr[i] is greater than all 
    //the elements in its right side
    for (int j = i + 1; j < n; j++)
      if (arr[j] > arr[i]) {
          
        // If any element found is greater than current leader
        // curr element is not the leader.
        leader = false;
        break;
      }

    // Push all the leaders in ans array.
    if (leader)
    ans.push_back(arr[i]);

  }
  
  return ans;
}

int main() {
    
  // Array Initialization.
  int n = 6;
  int arr[n] = {10, 22, 12, 3, 0, 6};

  vector<int> ans = printLeadersBruteForce(arr,n);
  
  for(int i = 0;i<ans.size();i++){
      
      cout<<ans[i]<<" ";
  }
  
  cout<<endl;
  return 0;
}



*/
//========================================================================================


//====================================================================================

// Optimal Solutions
//==============================================================

/*
Finding Leaders in an Array – Easy Explanation:

Instead of checking every element with all elements on its right, we can make it easier by starting from the last element of the array.

Steps:
The last element is always a leader, so we start from there.

Keep a variable to store the greatest element seen so far (initially the last element).

Move from right to left through the array:

If the current element is greater than the greatest so far, it's a leader.

Update the greatest so far.

This method is faster because we only check each element once.
However, it gives leaders in reverse order.
If you want them in the correct order, you can store them in a new list and reverse it at the end.


## Pseudo code
function findLeaders(arr):
    n = length of arr
    leaders = empty list
    max_so_far = arr[n - 1]  // last element is always a leader
    add max_so_far to leaders

    for i from n-2 down to 0:
        if arr[i] > max_so_far:
            max_so_far = arr[i]
            add max_so_far to leaders

    reverse the leaders list (optional, to maintain original order)
    return leaders


    Complexity Analysis

Time Complexity: O(N) { Since the array is traversed single time back to front, it will consume O(N) of time where N = size of the array }.

Space Complexity: O(N) { There is no extra space being used in this approach. But, a O(N) of space for ans array will be used in the worst case }.




*/




#include<bits/stdc++.h>
using namespace std;

vector<int> printLeaders(int arr[], int n) {

  vector<int> ans;
  
 // Last element of an array is always a leader,
 // push into ans array.
 int max = arr[n - 1];
 ans.push_back(arr[n-1]);

  // Start checking from the end whether a number is greater
  // than max no. from right, hence leader.
  for (int i = n - 2; i >= 0; i--)
    if (arr[i] > max) {
      ans.push_back(arr[i]);
      max = arr[i];
    }

  
  return ans;
}

int main() {
    
  // Array Initialization.
  int n = 6;
  int arr[n] = {10, 22, 12, 3, 0, 6};

  vector<int> ans = printLeaders(arr,n);
  
  
  for(int i = ans.size()-1;i>=0;i--){
      
      cout<<ans[i]<<" ";
  }
  
  cout<<endl;
  return 0;
}

