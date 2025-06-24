#include<bits/stdc++.h>
using namespace std;
//Pls try this later using a freq array so as to improve upon the performance of this
//TC: O(n*(map_overhead)) SC=O(3)-->aka constant space
class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0,l=0,r=0;
        unordered_map<char,int> um;
        while(r<s.size()){
            um[s[r]]++;
            while(um.size()>=3){ //NOTE: the adding and the shrinking logic is in one loop
                //NO SEPERATE IF'S
                ans+=s.size()-r;
                um[s[l]]--;
                if(um[s[l]]==0)
                    um.erase(s[l]);
                l++;
            }
            r++;
        }
        return ans;
    }
};

int main() {
    Solution s;
    string str="aaabcabcbc";
    cout << s.numberOfSubstrings(str);
}