// Brute Force Pseudo Code (Intersection of Two Arrays)
/*
    FUNCTION findIntersection(arr1, arr2):
    result ← empty vector

    FOR i FROM 0 TO length of arr1 - 1:
        FOR j FROM 0 TO length of arr2 - 1:
            IF arr1[i] == arr2[j]:
                ADD arr1[i] TO result
                BREAK  // move to next i (avoid duplicate count)
    
    RETURN result


*/

/*    code of brute force approach

#include <iostream>
#include <vector>
using namespace std;

vector<int> findIntersection(vector<int>& arr1, vector<int>& arr2) {
    vector<int> result;

    // Outer loop: go through each element of arr1
    for(int i = 0; i < arr1.size(); i++) {
        // Inner loop: compare arr1[i] with each element in arr2
        for(int j = 0; j < arr2.size(); j++) {
            if(arr1[i] == arr2[j]) {
                result.push_back(arr1[i]); // Common element found
                break; // Move to next element in arr1
            }
        }
    }

    return result;
}

int main() {
    vector<int> arr1 = {1, 2, 4, 5};
    vector<int> arr2 = {2, 3, 4};

    vector<int> intersection = findIntersection(arr1, arr2);

    cout << "Intersection elements are: ";
    for(int num : intersection) {
        cout << num << " ";
    }

    return 0;
}



  Time and Space Complexity

  ⏱️ Time Complexity:
Let:

n = arr1.size()

m = arr2.size()

Then:

Outer loop runs n times

Inner loop runs up to m times for each element of arr1

Time Complexity = O(n * m)
❗ Worst case: every element of arr1 needs to be compared with all elements of arr2.


🧠 Space Complexity:
We're using only:

An output result vector (to store common elements)

No extra data structures like hash sets, maps, etc.

Space Complexity = O(min(n, m))

Because in the worst case, all elements of the smaller array could be common.
*/




//--------------------------------------------------------------


//  Optimial approach ---> Two Pointer Approach (Intersection of Two Sorted Arrays)

/*
✅ Two Pointer Approach – Pseudo Code

   FUNCTION findIntersection(arr1, arr2):
    i ← 0
    j ← 0
    result ← empty list

    WHILE i < length(arr1) AND j < length(arr2):
        IF arr1[i] == arr2[j]:
            ADD arr1[i] TO result
            i ← i + 1
            j ← j + 1
        ELSE IF arr1[i] < arr2[j]:
            i ← i + 1
        ELSE:
            j ← j + 1

    RETURN result


   📈 Time and Space Complexity Analysis

     1. Time Complexity:
Code Breakdown:
Outer Loop (while i < arr1.size() && j < arr2.size()): This loop runs as long as both pointers (i for arr1 and j for arr2) haven't reached the end of their respective arrays.

Pointer Increment: Each pointer (i and j) is incremented at most n or m times where n is the size of arr1 and m is the size of arr2.

Worst-Case Scenario:
In the worst case, both pointers will traverse through all elements of their respective arrays.

Thus, the total number of iterations is bounded by O(n + m).

Time Complexity:
Best Case: O(n + m) (when all elements match quickly)

Worst Case: O(n + m) (when no or few elements match)

2. Space Complexity:
Space Used:
We only store the common elements in the result vector.

The result vector can hold a maximum of min(n, m) elements, where n is the size of arr1 and m is the size of arr2 (in the worst case, all elements might match).

Space Complexity:
Space Complexity = O(min(n, m))
(because the result array stores at most min(n, m) elements)



*/

// code of optimal approach

#include <iostream>
#include <vector>
using namespace std;

vector<int> findIntersection(vector<int>& arr1, vector<int>& arr2) {
    vector<int> result; // To store the intersection elements
    int i = 0, j = 0;

    // Traverse both arrays using two pointers
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] == arr2[j]) {
            result.push_back(arr1[i]); // Found common element
            i++; // Move both pointers forward
            j++;
        } else if (arr1[i] < arr2[j]) {
            i++; // Move pointer for arr1 forward
        } else {
            j++; // Move pointer for arr2 forward
        }
    }

    return result; // Return the result with common elements
}

int main() {
    vector<int> arr1 = {1, 2, 4, 5};
    vector<int> arr2 = {2, 3, 4};

    vector<int> intersection = findIntersection(arr1, arr2);

    cout << "Intersection elements are: ";
    for(int num : intersection) {
        cout << num << " ";
    }

    return 0;
}
