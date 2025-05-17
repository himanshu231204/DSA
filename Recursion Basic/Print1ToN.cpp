#include<bits/stdc++.h>
using namespace std;

void func(int i, int n){
   
   // Base Condition.
   if(i>n) return;
   cout<<i<<endl;

   // Function call to print i till i increments to n.
   func(i+1,n);

}

int main(){
  
  // Here, let’s take the value of n to be 4.
  int n = 4;
  func(1,n);
  return 0;

}

//Alternate Approach for printing integers from 1 to N (using Backtracking)

/*
 This is an alternative approach for printing the integers from 1 to N using recursion.
  In the previous approach, we used forward recursion 
  but in this approach, we will 
  be using backward recursion.
   The only change from the previous approach here will be 
 that the print line would be kept after the function call inside the recursive function 
 contrary to the previous approach. The function
  would be called for printing (i-1) integers and the nth integer would be printed.
*/

/*
Time Complexity: O(N) { Since the function is being called n times, and for each function, we have only one printable line that takes O(1) time, so the cumulative time complexity would be O(N) }

Space Complexity: O(N) { In the worst case, the recursion stack space would be full with all the function calls waiting to get completed and that would make it an O(N) recursion stack space }.
*/