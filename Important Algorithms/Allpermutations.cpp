/*
✅ Recursive Idea:
We fix one element at a time and recursively 
generate permutations for the remaining elements.

----------------------------------------------
🔁 Recursive Algorithm (Pseudocode)

function permute(arr, start, end):
    if start == end:
        print arr
        return

    for i from start to end:
        swap arr[start] with arr[i]
        permute(arr, start + 1, end)
        swap arr[start] with arr[i]   // backtrack
------------------------------------------------------------------------

📌 Explanation:
arr: the array to permute

start: current index where permutation begins

end: total number of elements (arr.length - 1)

Swap: choose an element to fix at start

Backtrack: restore the array before the next iteration
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void permute(vector<int>& arr, int start, int end) {
    if (start == end) {
        for (int num : arr)
            cout << num << " ";
        cout << endl;
        return;
    }

    for (int i = start; i <= end; i++) {
        swap(arr[start], arr[i]);
        permute(arr, start + 1, end);
        swap(arr[start], arr[i]); // backtrack
    }
}

int main() {
    vector<int> arr = {1, 2, 3};
    permute(arr, 0, arr.size() - 1);
    return 0;
}


//----------------------------------------------------

/*
✅ Time Complexity: O(n * n!)

Why?
For n elements, there are n! permutations.

Each permutation takes O(n) time to print or store.
So, total time:

Time =n! (permutations)×n (print each)= O(n⋅n!)
----------------------------
✅ Space Complexity:
1. Auxiliary Space (Recursive Stack): O(n)
The recursion goes n levels deep, one for each element being fixed.

2. Output Space:
If you’re storing all permutations (instead of printing), then:


Output space=O(n⋅n!) to store all permutations
So overall space is:

O(n) (for recursion) if printing only

O(n * n!) if storing all permutations


*/