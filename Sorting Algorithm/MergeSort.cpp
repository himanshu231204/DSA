/*
Pseudo Code MergeSort
      
    MergeSort(arr,low,high){

    if(low>=high) return;

    mid=(low+high)/2  find where to split
    mergesort=(arr,low,mid)
    mergesort=(arr,mid+1,high)
    merge(arr,low,mid,high)  // combining above two sorted array 
    
    
    
    }
*/


/*
     Pseudo code of Merge opertaion

     Merge(arr[],low,mid,high,tep[])  , where temp[] is empty array

     left=low
     right=mid+1

//storing elements in the temporary array in a sorted manner//

     while(left<=mid && right<=high){
     if arr[left]<=arr[right]
        temp.add(arr[left])
        left++
      ele
       temp.add(arr[right])
        right++

     }
       // if elements on the left half are still left //
     while(left<=mid){
         temp.add(arr[left]);
         left++
     }
       /  if elements on the right half are still left //
      while(right<=high){
         temp.add(arr[right]);
         right++
     }
     // moving sorted element from temp[] to original array
     for(i=low -> high){
         arr[i]=temp(i-low)
     }
       



*/


// Code of MergeSort 


#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid);  // left half
    mergeSort(arr, mid + 1, high); // right half
    merge(arr, low, mid, high);  // merging sorted halves
}

int main() {

    vector<int> arr = {9, 4, 7, 6, 3, 1, 5}  ;
    int n = 7;

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    mergeSort(arr, 0, n - 1);
    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    return 0 ;
}