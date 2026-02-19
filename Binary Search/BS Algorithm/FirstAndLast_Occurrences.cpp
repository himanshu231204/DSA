// OPtimal solutions


#include <bits/stdc++.h>
using namespace std;

// Lower Bound function: finds the first position where element >= x
int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1; // go left
        } else {
            low = mid + 1; // go right
        }
    }
    return ans;
}

// Upper Bound function: finds the first position where element > x
int upperBound(vector<int> &arr, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1; // go left
        } else {
            low = mid + 1; // go right
        }
    }
    return ans;
}

// First and Last Occurrences using binary search
pair<int, int> firstAndLastPositions(vector<int> &arr, int n, int k) {
    int lb = lowerBound(arr, n, k);
    int ub = upperBound(arr, k, n) - 1;

    // ❗ FIXED: Check if the element is not present
    if (lb == n || arr[lb] != k) return {-1, -1}; // correct edge case
    return {lb, ub};
}

int main() {
    int n = 7;
    int k = 13;
    vector<int> arr = {3, 4, 13, 13, 13, 20, 40};

    // ❗ FIXED: Can't print a pair directly using cout
    pair<int, int> res = firstAndLastPositions(arr, n, k);
    cout << "First occurrence: " << res.first << ", Last occurrence: " << res.second << endl;

    return 0;
}
