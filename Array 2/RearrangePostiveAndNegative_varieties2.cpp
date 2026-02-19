/*
Variety-2
Problem Statement:
There’s an array ‘A’ of size ‘N’ with positive and negative elements (not necessarily equal). Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values. The leftover elements should be placed at the very end in the same order as in array A.

Note: Start the array with positive elements.

*/
//===========================================


/*
Intuition:
In this variety, the number of positive and negative numbers shall not necessarily
 be equal to each other in the given array. So, there can be two cases possible: 
 either the positive elements exceed the negatives or the negatives exceed the positives. 
 So, instead of using the optimal solution discussed for the variety-1 above, we’ll fall 
 back to the brute force solution where we create separate arrays for storing positives and 
 negatives and then put them back into the array alternatively. The remaining negative or positive 
 elements are added to the array at last.

*/
//============================================

/*
   Approach

   Function RearrangeArray(arr, n):
    pos = []   // Array to store positive numbers
    neg = []   // Array to store negative numbers

    // Step 1: Separate positive and negative elements
    for i from 0 to n-1:
        if arr[i] >= 0:
            pos.append(arr[i])
        else:
            neg.append(arr[i])

    // Step 2: Alternate merging
    i = 0
    j = 0
    k = 0      // Index for original array

    while i < length(pos) AND j < length(neg):
        arr[k] = pos[i]
        k = k + 1
        i = i + 1

        arr[k] = neg[j]
        k = k + 1
        j = j + 1

    // Step 3: Append remaining elements
    while i < length(pos):
        arr[k] = pos[i]
        i = i + 1
        k = k + 1

    while j < length(neg):
        arr[k] = neg[j]
        j = j + 1
        k = k + 1
================================
This approach ensures:

Positives and negatives are placed alternately (as much as possible).

Remaining elements are added at the end, preserving order within positives/negatives.

*/
#include<bits/stdc++.h>
using namespace std;

  vector<int> RearrangebySign(vector<int>A, int n){
    
  // Define 2 vectors, one for storing positive 
  // and other for negative elements of the array.
  vector<int> pos;
  vector<int> neg;
  
  // Segregate the array into positives and negatives.
  for(int i=0;i<n;i++){
      
      if(A[i]>0) pos.push_back(A[i]);
      else neg.push_back(A[i]);
  }
  
  // If positives are lesser than the negatives.
  if(pos.size() < neg.size()){
      
    // First, fill array alternatively till the point 
    // where positives and negatives ar equal in number.
    for(int i=0;i<pos.size();i++){
      
      A[2*i] = pos[i];
      A[2*i+1] = neg[i];
    }
    
    // Fill the remaining negatives at the end of the array.
    int index = pos.size()*2;
    for(int i = pos.size();i<neg.size();i++){
        
        A[index] = neg[i];
        index++;
    }
  }
  
  // If negatives are lesser than the positives.
  else{
      
      // First, fill array alternatively till the point 
      // where positives and negatives ar equal in number.
      for(int i=0;i<neg.size();i++){
      
      A[2*i] = pos[i];
      A[2*i+1] = neg[i];
  }
    
    // Fill the remaining positives at the end of the array.
    int index = neg.size()*2;
    for(int i = neg.size();i<pos.size();i++){
        
        A[index] = pos[i];
        index++;
    }
  }
  return A;
    
}

int main() {
    
  // Array Initialisation.
  int n = 6;
  vector<int> A {1,2,-4,-5,3,4};

  vector<int> ans = RearrangebySign(A,n);
  
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}


//=====================================

/*
✅ Time Complexity: O(2*N) = O(N)
O(N) to separate the array into pos and neg arrays.

O(N) to merge elements back alternatively and then append leftovers.

So, total = O(N + N) = O(2*N) = O(N) in Big-O terms.

✅ Space Complexity: O(N)
Two extra arrays (pos and neg) are used.

Each can store up to N/2 elements in the worst case.

So, total space = O(N/2 + N/2) = O(N).
*/