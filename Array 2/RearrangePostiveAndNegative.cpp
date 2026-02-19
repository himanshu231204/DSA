/*
Variety-1

Problem Statement:

There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.

Note: Start the array with positive elements.
*/
//========================================================

// MY fist approach that come in my mind is :
/*
  if a[i] is +ve , put it on even index(2*i) &
  if a[i] is -ve, put it on odd index (2*i+1)

  this is the main logic ,now we have implements this
*/

//===============================================================

// Brute force:
// Seperate +ve and -ve elements using vector array and then place it to even&odd indexes
/*
🔹 Idea:
Separate positives and negatives → then place them alternately.

🧠 Steps:

Put all positives in pos[] and negatives in neg[].

Traverse both arrays and place:

pos[i] at index 2*i (even index)

neg[i] at index 2*i + 1 (odd index)

⏱ Time Complexity: O(N) (due to multiple traversals)

================================================================

// Pseudo code
---------------

create 2 vector 
pos=[]
neg=[]

//seperate array into -ve and +ve

for(i=0--->n)
if(A[i]>0)  add to pos[]
else add to neg[]

// place +ve at even and -ve at odd index

for(i=0-->n/2)
A[2*i]=pos[i]
A[2*i+1]=neg[i]

return A


TC=O(n)+O(n/2)
SC=O(n)  , since we are using extra array

=================================================================

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
  
  // Positives on even indices, negatives on odd.
  for(int i=0;i<n/2;i++){
      
      A[2*i] = pos[i];
      A[2*i+1] = neg[i];
  }
  
  
  return A;
    
}

int main() {
    
  // Array Initialisation.
  int n = 4;
  vector<int> A {1,2,-4,-5};

  vector<int> ans = RearrangebySign(A,n);
  
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}

*/


// =============================
// Optimal Solutions:

//we will try to solve the problem in a single pass and
// try to arrange the array elements in the correct order in that pass only.

/*
✅ Optimal Approach Summary:
Use two pointers:

posIndex = 0 → to place positive numbers at even indices.

negIndex = 1 → to place negative numbers at odd indices.

Traverse the array once:

If element is positive → place at posIndex, then posIndex += 2

If element is negative → place at negIndex, then negIndex += 2

Continue until the full array is rearranged.

✅ Done in O(N) time and O(N) space (unless done in-place with a new array).
*/
//=======================================================

#include<bits/stdc++.h>
using namespace std;

  vector<int> RearrangebySign(vector<int>A){
    
  int n = A.size();
  
  // Define array for storing the ans separately.
  vector<int> ans(n,0);
  
  // positive elements start from 0 and negative from 1.
  int posIndex = 0, negIndex = 1;
  for(int i = 0;i<n;i++){
      
      // Fill negative elements in odd indices and inc by 2.
      if(A[i]<0){
          ans[negIndex] = A[i];
          negIndex+=2;
      }
      
      // Fill positive elements in even indices and inc by 2.
      else{
          ans[posIndex] = A[i];
          posIndex+=2;
      }
  }
  
  return ans;
    
}

int main() {
    
  // Array Initialisation.
  
  vector<int> A = {1,2,-4,-5};

  vector<int> ans = RearrangebySign(A);
  
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}