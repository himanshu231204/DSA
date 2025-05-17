#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int arr[] = {1, 3, 2, 1, 3, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    unordered_map<int, int> freq;

    // Count frequencies
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    int maxFreq = 0, minFreq = n + 1;
    int maxElem = -1, minElem = -1;

    // Find highest and lowest frequency elements
    for (auto pair : freq) {
        if (pair.second > maxFreq) {
            maxFreq = pair.second;
            maxElem = pair.first;
        }
        if (pair.second < minFreq) {
            minFreq = pair.second;
            minElem = pair.first;
        }
    }

    cout << "Highest frequency element: " << maxElem << " -> " << maxFreq << " times\n";
    cout << "Lowest frequency element: " << minElem << " -> " << minFreq << " times\n";

    return 0;
}
