//Leetcode 125. Valid Palindrome https://leetcode.com/problems/valid-palindrome/description/
//Time Complexity: O(n)
//Space Complexity: O(1)

// pseudo code
/*
int left = 0, right = s.size() - 1;
while (left < right) {
check if s[left] is alphanumeric, if not, move left pointer to the right
check if s[right] is alphanumeric, if not, move right pointer to the left   
compare the characters at left and right pointers, if they are not equal, return false
move left pointer to the right and right pointer to the left
}
*/





#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    string s = "A man, a plan, a canal: Panama";
    Solution obj;   
    bool ans = obj.isPalindrome(s);
    cout << "Is the string a valid palindrome? " << (ans ? "Yes" : "No");
    return 0;
}