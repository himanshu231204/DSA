//  Brute Force Approach
/*
For Rotating the Elements to left
Step 1: Copy the first k elements into the temp array.
            
             for(i=0;i<k;i++){
             temp[i]=a[i]
             }

Step 2: Shift n-k elements from last by k position to the left
          
              for(i=0;i<n-k;i++){
             a[i]=a[i+k]
             }

Step 3: Copy the elements into the main array from the temp array.

               for(i=n-k;i<n;i++){
             a[i]=temp[i-(n-k)]
             }


    Time Complexity: O(n)

Space Complexity: O(k) since k array element needs to be stored in temp array

*/

            // Code of Brute Force Approach
/*
#include <iostream>
using namespace std;
void Rotatetoleft(int arr[], int n, int k)
{
  if (n == 0)
    return;
  k = k % n;
  if (k > n)
    return;
  int temp[k];
  for (int i = 0; i < k; i++)
  {
    temp[i] = arr[i];
  }
  for (int i = 0; i < n - k; i++)
  {
    arr[i] = arr[i + k];
  }
  for (int i = n - k; i < n; i++)
  {
    arr[i] = temp[i - n + k];
  }
}
int main()
{
  int n = 7;
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int k = 2;
  Rotatetoleft(arr, n, k);
  cout << "After Rotating the elements to left " << endl;
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}
  */


  // Optimal approch ( Reversal algorithm)
  
  /*
        Approach 2: Using ” Reversal Algorithm “

Approach:

For Rotating Elements to left
Step 1: Reverse the first k elements of the array

Step 2: Reverse the last n-k elements of the array.

Step 3: Reverse the whole array.
  */
   
    // code for optimal approach

    #include <bits/stdc++.h>
    using namespace std;
    
    void Rotateeletoleft(int arr[], int n, int k)
    {
      // Fix k if greater than n
      k = k % n;
    
      // Reverse first k elements
      reverse(arr, arr + k);
      // Reverse last n-k elements
      reverse(arr + k, arr + n);
      // Reverse the whole array
      reverse(arr, arr + n);
    }
    
    int main()
    {
      int arr[] = {1, 2, 3, 4, 5, 6, 7};
      int n = sizeof(arr) / sizeof(arr[0]);
      int k = 2;
      Rotateeletoleft(arr, n, k);
      cout << "After Rotating the k elements to left: ";
      for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
      cout << endl;
      return 0;
    }
    