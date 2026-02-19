#include<bits/stdc++.h>
using namespace std;

int func(int n){
   
   // Base Condition.
   if(n == 0)
   {
       return 0;
   }

   // Problem broken down into 2 parts and then combined.
   return n + func(n-1);

}

int main(){
  
  // Here, let’s take the value of n to be 3.
  int n = 3;
  cout<<func(n)<<endl;
  return 0;

}