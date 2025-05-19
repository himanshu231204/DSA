// Stock Buy And Sell

// Brute force Approach:
/*
Intutuions:
Try every pair of days — buy on day i, sell on a future day j.
Track the maximum profit from all such pairs.

Approach

maxPro = 0

Loop i = 0 to n-1
  Loop j = i+1 to n
   If arr[j] > arr[i], update maxPro = max(maxPro, arr[j] - arr[i])

Return maxPro


TC=O(n^2)
SC=O(1)



#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &arr) {
    int maxPro = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
            maxPro = max(arr[j] - arr[i], maxPro);
            }
        }
        }

    return maxPro;
}

int main() {
    vector<int> arr = {7,1,5,3,6,4};
    int maxPro = maxProfit(arr);
    cout << "Max profit is: " << maxPro << endl;
}

*/


// optimal Solutions

/*
🔁 Intuition (Best Time to Buy and Sell Stock):
We track the minimum price so far and calculate the profit if we sell at the current price.
If the profit is higher than the current max profit, we update it.

⚙️ Approach:
maxPro = 0, minPrice = ∞

Loop through the array:

Update minPrice = min(minPrice, arr[i])

Update maxPro = max(maxPro, arr[i] - minPrice)

Return maxPro


TC=O(n)
SC=O(1)


*/


#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &arr) {
    int maxPro = 0;
    int n = arr.size();
    int minPrice = INT_MAX;

    for (int i = 0; i < arr.size(); i++) {
        minPrice = min(minPrice, arr[i]);
        maxPro = max(maxPro, arr[i] - minPrice);
    }
    
    return maxPro;
}

int main() {
    vector<int> arr = {7,1,5,3,6,4};
    int maxPro = maxProfit(arr);
    cout << "Max profit is: " << maxPro << endl;
}





