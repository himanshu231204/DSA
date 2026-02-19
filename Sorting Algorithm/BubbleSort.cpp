/*
Pseudo code
time complexity= O(N^2)

procedure BubbleSort(arr, n):
    for i from n-1 down to 0:
        for j from 0 to i-1:
            if arr[j] > arr[j+1]:
                swap arr[j] and arr[j+1]

*/
#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n) {
    // bubble sort
    for (int i = n - 1; i >= 0; i--) {
         
        int swap=0;

        for (int j = 0; j <= i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                swap=1;
            }
        }
        if(swap==0){
            break;
        }
    }

    cout << "After Using bubble sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Using Bubble Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubble_sort(arr, n);
    return 0;

}


/*
Optimized bubble sort Pseudo code  

time complexity= O(N)

Procedure OptimizedBubbleSort(arr, n):
    for i from n-1 to 0:
        swapped ← false
        for j from 0 to i-1:
            if arr[j] > arr[j + 1]:
                swap arr[j] and arr[j + 1]
                swapped ← true
        if swapped = false:
            break;

*/