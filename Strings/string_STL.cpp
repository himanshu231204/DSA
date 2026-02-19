// 🔥 Most Commonly Used C++ String STL Functions for LeetCode

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "leetcode";

    // ✅ 1. Length of string
    cout << s.length() << endl;  // Output: 8

    // ✅ 2. Check if string is empty
    cout << s.empty() << endl;   // Output: 0 (false)

    // ✅ 3. Substring
    cout << s.substr(2, 4) << endl;  // Output: "etco"

    // ✅ 4. Find substring
    cout << s.find("code") << endl;  // Output: 4 (starting index)

    // ✅ 5. Reverse string
    reverse(s.begin(), s.end());
    cout << s << endl;               // Output: "edocetle"

    // ✅ 6. Sort string
    sort(s.begin(), s.end());
    cout << s << endl;               // Output: "cdeeelot"

    // ✅ 7. Convert number to string
    int x = 123;
    string str_num = to_string(x);
    cout << str_num << endl;         // Output: "123"

    // ✅ 8. Convert string to number
    string s2 = "456";
    int num = stoi(s2);
    cout << num << endl;             // Output: 456

    // ✅ 9. Add character to end
    string a = "abc";
    a.push_back('d');                // a = "abcd"
    cout << a << endl;

    // ✅ 10. Remove last character
    a.pop_back();                    // a = "abc"
    cout << a << endl;

    // ✅ 11. Loop through string
    for (char c : s) {
        cout << c << " ";
    }

    return 0;
}
