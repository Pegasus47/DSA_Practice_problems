#include<iostream>
#include<vector>
#include<set>
#include<string>
using namespace std;

//The Brute generating all the substrings and returning the valid one with max length
//This is the semi-optimal solution which has a TC of O(n)+O(26*n) and SC of O(26)
//Solution should work but not the best approach

class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        set<char> st;
        for(char c : s){
            st.insert(c);
        }
        for(char c : st){
            int l=0,r=0,cnt=0;
            while(r<s.length()){
                if(s[r]!=c)
                    cnt++;
                if(cnt>k){
                    if(s[l]!=c)
                        cnt--;
                    l++;
                }
                if(cnt<=k)
                    ans=max(ans,r-l+1);
                r++;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    string str="ABBABBAABA";
    int k=2;
    cout << s.characterReplacement(str,k);

}
