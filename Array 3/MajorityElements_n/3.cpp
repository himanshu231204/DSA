/*
Problem Statement: Given an array of N integers. 
Find the elements that appear more than N/3 times in the array. 
If no such element exists, return an empty vector.
*/
/*
===========================================
Brute Force
===========================================

✅ Observation: Max Elements > floor(N/3)
In an array of size N, at most 2 elements can appear more than floor(N/3) times.

🔍 Why?
Suppose N = 8, then floor(8/3) = 2.

So, a majority element must appear at least 3 times.

If 3 different elements each appear ≥ 3 times → total = 3×3 = 9 > 8.

This exceeds the array size, which is not possible.

➡️ Conclusion: Maximum 2 elements can appear more than floor(N/3) times.
------------------------------------------------------------------------------------------

✅ Naive Approach to Find Elements Occurring More Than ⌊N/3⌋ Times
🔁 Approach:
Run a loop to pick each element one by one.

For each unique element, count its occurrences in the array using another loop.

If an element appears more than ⌊N/3⌋ times, add it to the answer.

If an element is already in the answer, skip it to avoid duplicates.

📌 Note: This approach uses nested loops, so it has O(N²) time complexity.

🧠 Complexity Analysis (Naive Approach)
Time Complexity:
🔸 O(N²)
➤ For each element, we scan the entire array to count occurrences.

Space Complexity:
🔸 O(1)
➤ We only store up to 2 majority elements, which is considered constant space.



#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> v) {
    int n = v.size(); //size of the array
    vector<int> ls; // list of answers

    for (int i = 0; i < n; i++) {
        //selected element is v[i]:
        // Checking if v[i] is not already
        // a part of the answer:
        if (ls.size() == 0 || ls[0] != v[i]) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                // counting the frequency of v[i]
                if (v[j] == v[i]) {
                    cnt++;
                }
            }

            // check if frquency is greater than n/3:
            if (cnt > (n / 3))
                ls.push_back(v[i]);
        }

        if (ls.size() == 2) break;
    }

    return ls;
}

int main()
{
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    vector<int> ans = majorityElement(arr);
    cout << "The majority elements are: ";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
    return 0;
}
    */

    /*
    ===========================================
    Better Approaach
    =============================================

    ⚙️ Better Approach (HashMap)
🧠 Intuition:
Avoid counting duplicates repeatedly by using a hash map to track frequencies efficiently.

🔄 Approach:
Use a hashmap to store elements and their frequencies.

Traverse the array once to update frequencies.

Iterate through the map:

If any element's frequency > ⌊N/3⌋ → add it to the result list.

Return the result list.

⏱️ Time Complexity: O(N)
✅ Single pass for counting and another for checking.

🧠 Space Complexity: O(N)
🧾 Stores frequencies for all elements in the array.

-----------------------------------------------------------   
#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> v) {
    int n = v.size(); //size of the array
    vector<int> ls; // list of answers

    //declaring a map:
    map<int, int> mpp;

    // least occurrence of the majority element:
    int mini = int(n / 3) + 1;

    //storing the elements with its occurnce:
    for (int i = 0; i < n; i++) {
        mpp[v[i]]++;

        //checking if v[i] is
        // the majority element:
        if (mpp[v[i]] == mini) {
            ls.push_back(v[i]);
        }
        if (ls.size() == 2) break;
    }

    return ls;
}

int main()
{
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    vector<int> ans = majorityElement(arr);
    cout << "The majority elements are: ";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
    return 0;
}

*/

/*
==============================
Optimal Approach
===========================
🧠 Intuition (Optimal Approach):
If an element appears more than ⌊N/3⌋ times, it must stand out significantly in the array.

We maintain two potential candidates and their counts while traversing the array:

Majority and minority elements will cancel each other out over time.

After the first pass, we verify the two candidates by counting their actual occurrences.

This helps us find elements appearing more than ⌊N/3⌋ times without using extra space for every element.

✅ Optimal Approach Summary:
Maintain two potential majority elements (el1, el2) and their counts (cnt1, cnt2).

Traverse the array:

If cnt1 is 0 and current ≠ el2, set el1 = current, cnt1 = 1.

Else if cnt2 is 0 and current ≠ el1, set el2 = current, cnt2 = 1.

Else if current == el1, increment cnt1.

Else if current == el2, increment cnt2.

Otherwise, decrement both cnt1 and cnt2.

After traversal, manually count and validate el1 and el2 to confirm if they appear more than ⌊N/3⌋ times.

✔️ Time Efficient: Only two passes.
✔️ Space Efficient: Uses constant space.


*/



 #include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> v) {
    int n = v.size(); //size of the array

    int cnt1 = 0, cnt2 = 0; // counts
    int el1 = INT_MIN; // element 1
    int el2 = INT_MIN; // element 2

    // applying the Extended Boyer Moore's Voting Algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && el2 != v[i]) {
            cnt1 = 1;
            el1 = v[i];
        }
        else if (cnt2 == 0 && el1 != v[i]) {
            cnt2 = 1;
            el2 = v[i];
        }
        else if (v[i] == el1) cnt1++;
        else if (v[i] == el2) cnt2++;
        else {
            cnt1--, cnt2--;
        }
    }

    vector<int> ls; // list of answers

    // Manually check if the stored elements in
    // el1 and el2 are the majority elements:
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el1) cnt1++;
        if (v[i] == el2) cnt2++;
    }

    int mini = int(n / 3) + 1;
    if (cnt1 >= mini) ls.push_back(el1);
    if (cnt2 >= mini) ls.push_back(el2);

    // Uncomment the following line
    // if it is told to sort the answer array:
    // sort(ls.begin(), ls.end()); //TC --> O(2*log2) ~ O(1);

    return ls;
}

int main()
{
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    vector<int> ans = majorityElement(arr);
    cout << "The majority elements are: ";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
    return 0;
}






