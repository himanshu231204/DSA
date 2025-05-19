#include <iostream>
#include <vector>
using namespace std;

// Function to print all subarrays
void printAllSubarrays(vector<int> &arr) {
    int n = arr.size();
    cout << "\nAll Subarrays:\n";
    for (int i = 0; i < n; i++) {            // Starting index
        for (int j = i; j < n; j++) {        // Ending index
            for (int k = i; k <= j; k++) {   // Elements from i to j
                cout << arr[k] << " ";
            }
            cout << "\n";
        }
    }
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call the function
    printAllSubarrays(arr);

    return 0;
}
