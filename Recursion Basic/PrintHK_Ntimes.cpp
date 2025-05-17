
/*
#include<bits/stdc++.h>
using namespace std;
int cnt = 0;

void print(){
   
   // Base Condition.
   if(cnt == 3)  return;
   cout<<cnt<<endl;

   // Count Incremented
   cnt++;
   print();

}

int main(){
    print();
  return 0;
}
  */

  // using recursions


  #include<bits/stdc++.h>
using namespace std;

void func(int i, int n){
   
   // Base Condition.
   if(i>n) return;
   cout<<"Himanshu"<<endl;

   // Function call to print till i increments.
   func(i+1,n);

}

int main(){
  
  // Here, let’s take the value of n to be 4.
  int n = 4;
  func(1,n);
  return 0;

}