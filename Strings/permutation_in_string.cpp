// leetcode 567. Permutation in String
// https://leetcode.com/problems/permutation-in-string/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();

        if(n1>n2) return false;

        vector<int> freq1(26,0);
        vector<int> freq2(26,0);

        for(int i=0;i<n1;i++){
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }

        if(freq1==freq2) return true;

        for(int i=n1;i<n2;i++){
            freq2[s2[i]-'a']++;
            freq2[s2[i-n1]-'a']--;

            if(freq1==freq2) return true;
        }

        return false;


        
    }

};

int main(){

    string s1="ab";
    string s2="eidbaooo";

    Solution sol;
    bool ans=sol.checkInclusion(s1,s2);
    cout<<ans<<endl;

    return 0;
}

// time complexity: O(n1+n2) where n1 and n2 are the lengths of s1 and s2 respectively