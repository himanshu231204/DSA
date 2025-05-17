

  /*
      
   int LargestElements(vector<int>&arr,int n){

        largest=a[0];
        for(i=0,i<n,i++){
          if(a[i]>a[0]){
          largest=a[i]
        }
}
        return largest
        

   }

   */
  
   /*
       TC=O(n)
      

   */


   #include <bits/stdc++.h>
 
   using namespace std;
   int findLargestElement(int arr[], int n) {
    
     int max = arr[0];
     for (int i = 0; i < n; i++) {
       if (max < arr[i]) {
         max = arr[i];
       }
     }
     return max;
   }
   int main() {
     int arr1[] = {2,5,1,3,0};
     int n = 5;
     int max = findLargestElement(arr1, n);
     cout << "The largest element in the array is: " << max << endl;
    
     int arr2[] =  {8,10,5,7,9};
     n = 5;
     max = findLargestElement(arr2, n);
     cout << "The largest element in the array is: " << max<<endl;
     return 0;
   }
   
   
   