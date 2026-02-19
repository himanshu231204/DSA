// leetcode 1910. Remove All Occurrences of a Substring https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/
// Time Complexity: O(n * m) where n is the length of the string s and m is the length of the substring part
// Space Complexity: O(n) where n is the length of the string s


// pseudo code
/*
to remove all occurrences of a substring part from a string s, we can use the find and erase functions of the string class in C++. We will repeatedly search for the substring part in the string s and remove it until there are no more occurrences left. 
1. We start by finding the first occurrence of the substring part in the string s using the find function. This will return the index of the first occurrence or string::npos if the substring is not found.
2. If the substring is found, we use the erase function to remove it from the string
3. We repeat this process until the find function returns string::npos, indicating that there are no more occurrences of the substring part in the string s.

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.size()>0 && s.find(part)<s.size()) {
            s.erase(s.find(part), part.size());
        }
   
        return s;
    }
};


int main() {
    string s = "daabcbaabcbc";
    string part = "abc";
    Solution obj;
    string ans = obj.removeOccurrences(s, part);
    cout << "The resulting string after removing all occurrences of the substring is: " << ans;
    return 0;
}