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

    // Print frequencies
    for (auto pair : freq) {
        cout << pair.first << " -> " << pair.second << endl;
    }

    return 0;
}
