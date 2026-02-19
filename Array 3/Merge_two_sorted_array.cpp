/*
Problem statement: Given two sorted arrays arr1[] and arr2[] of sizes n and m in
 non-decreasing order. Merge them in sorted order. Modify arr1 so that it contains
  the first N elements and modify arr2 so that it contains the last M elements.

  Example 1:

Input: 
n = 4, arr1[] = [1 4 8 10] 
m = 5, arr2[] = [2 3 9]

Output: 
arr1[] = [1 2 3 4]
arr2[] = [8 9 10]

Explanation:
After merging the two non-decreasing arrays, we get, 1,2,3,4,8,9,10.

*/

/*
===================================
Brute Force
===================================

✅ Intuitions:

The approach uses a two-pointer technique to merge two sorted arrays into a third sorted array.
Once merged, the elements from this third array are copied back into the original two arrays.
This works efficiently because the original arrays are already sorted.

✅ Approach/Pseudo Code

This approach merges two sorted arrays using a two-pointer technique and a temporary array:

Initialize a third array arr3[] of size n + m and two pointers (left for arr1[], right for arr2[]).

Traverse both arrays:

If arr1[left] < arr2[right], insert arr1[left] into arr3[] and move left.

If arr2[right] < arr1[left], insert arr2[right] into arr3[] and move right.

If both are equal, insert either and move the respective pointer.

Insert remaining elements from whichever array is left.

Copy elements back:

First n elements of arr3[] go to arr1[].

Next m elements go to arr2[].

-----------------------------------------
✅ Summary – Complexity Analysis:
Time Complexity: O(n + m) + O(n + m)

First O(n + m) to merge arr1[] and arr2[] into arr3[].

Second O(n + m) to copy back sorted elements into arr1[] and arr2[].

Space Complexity: O(n + m)

Because of the use of an extra array arr3[] to hold merged elements.
--------------------------------------------

#include <bits/stdc++.h>
using namespace std;

void merge(long long arr1[], long long arr2[], int n, int m) {

    //Declare a 3rd array and 2 pointers:
    long long arr3[n + m];
    int left = 0;
    int right = 0;

    int index = 0;

    //Insert the elements from the 2 arrays
    // into the 3rd array using left and right
    // pointers:

    while (left < n && right < m) {
        if (arr1[left] <= arr2[right]) {
            arr3[index] = arr1[left];
            left++, index++;
        }
        else {
            arr3[index] = arr2[right];
            right++, index++;
        }
    }

    // If right pointer reaches the end:
    while (left < n) {
        arr3[index++] = arr1[left++];
    }

    // If left pointer reaches the end:
    while (right < m) {
        arr3[index++] = arr2[right++];
    }

    // Fill back the elements from arr3[]
    // to arr1[] and arr2[]:
    for (int i = 0; i < n + m; i++) {
        if (i < n) arr1[i] = arr3[i];
        else arr2[i - n] = arr3[i];
    }
}

int main()
{
    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};
    int n = 4, m = 3;
    merge(arr1, arr2, n, m);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}



*/

/*
========================================
Optimal Approach
==========================================

Intuition:

In the brute force approach, we are using space complexity = O(n + m).
So, can we optimize this? Yes, we can.

Since both arrays are already sorted, if we can rearrange the elements within the arrays, 
then we can achieve space complexity = O(1).

So, what we can do is:

Swap the largest element from arr1[] with the smallest element from arr2[], 
whenever needed.

And after that,

Sort both arrays, i.e., arr1[] and arr2[] individually.
-----------------------------------------------------

Time Complexity:
O(min(n, m)) + O(n log n) + O(m log m)
→ Swapping elements takes O(min(n, m))
→ Sorting arr1[] takes O(n log n)
→ Sorting arr2[] takes O(m log m)

Space Complexity:
O(1) — No extra space is used.
-----------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

void merge(long long arr1[], long long arr2[], int n, int m) {

    //Declare 2 pointers:
    int left = n - 1; //
    int right = 0;

    //Swap the elements until arr1[left] is
    // smaller than arr2[right]:
    while (left >= 0 && right < m) {
        if (arr1[left] > arr2[right]) {
            swap(arr1[left], arr2[right]);
            left--, right++;
        }
        else {
            break;
        }
    }

    // Sort arr1[] and arr2[] individually:
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

int main()
{
    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};
    int n = 4, m = 3;
    merge(arr1, arr2, n, m);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}




*/


/*
===================================
Optimal Solutions 2
==================================

💡 Intuition (Sochne ka tarika):
Is approach mein hum do sorted arrays ko bina extra space ke merge karte hain using a smart technique jise Gap Method kehte hain (ye Shell Sort se inspired hai).

👣 Steps:
Dono arrays ko ek continuous array samjho
Jaise arr1[] aur arr2[] ek hi array ka part hain.

Initial gap calculate karo:
gap = ceil((n + m) / 2)
Yahaan n aur m dono arrays ka size hai.

Two pointer lagao:

Ek pointer left par

Dusra pointer right = left + gap par

Agar arr[left] > arr[right] hai to swap karo

Fir left++ aur right++ karte jao

Jab tak right end tak na pahuch jaaye

Har round ke baad gap ko update karo:
gap = ceil(gap / 2)
Jab tak gap == 1 ka iteration complete na ho jaaye, tab tak ye repeat karo.

-----------------------------------------------


*/



#include <bits/stdc++.h>
using namespace std;

void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2) {
    if (arr1[ind1] > arr2[ind2]) {
        swap(arr1[ind1], arr2[ind2]);
    }
}

void merge(long long arr1[], long long arr2[], int n, int m) {
    // len of the imaginary single array:
    int len = n + m;

    // Initial gap:
    int gap = (len / 2) + (len % 2);

    while (gap > 0) {
        // Place 2 pointers:
        int left = 0;
        int right = left + gap;
        while (right < len) {
            // case 1: left in arr1[]
            //and right in arr2[]:
            if (left < n && right >= n) {
                swapIfGreater(arr1, arr2, left, right - n);
            }
            // case 2: both pointers in arr2[]:
            else if (left >= n) {
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            // case 3: both pointers in arr1[]:
            else {
                swapIfGreater(arr1, arr1, left, right);
            }
            left++, right++;
        }
        // break if iteration gap=1 is completed:
        if (gap == 1) break;

        // Otherwise, calculate new gap:
        gap = (gap / 2) + (gap % 2);
    }
}

int main()
{
    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};
    int n = 4, m = 3;
    merge(arr1, arr2, n, m);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}




