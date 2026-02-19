#include<bits/stdc++.h>
using namespace std;

void func(int i, int n){
   
   // Base Condition.
   if(i<1) return;
   cout<<i<<endl;

   // Function call to print i till i decrements to 1.
   func(i-1,n);

}

int main(){
  
  // Here, let’s take the value of n to be 4.
  int n = 4;
  func(n,n);
  return 0;

}

//TC=O(n), SC=O(n)

// Alternate Approach for printing integers from N to 1 (using Backtracking)

/*
This is an alternative approach for printing the integers from N to 1 using recursion.
 In the previous approach, we used forward recursion but in this approach, we will be using backward recursion.
  The only change from the previous approach here will be that the print line would be kept after the function call
   inside the recursive function contrary to the previous approach. The function would be called for printing (i+1) integers 
   and the ith integer would be printed.
*/