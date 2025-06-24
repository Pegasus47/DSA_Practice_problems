#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//build from brute
//notice a way to check if a given string is valid or not
//try to use that method in the optimal soln
//replace while-->if and add a check while updating ans to get from 2n-->n

class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxFreq=0,ans=0,r=0,l=0;
        unordered_map<char,int> freq;
        while(r<s.size()){
            freq[s[r]]++;
            maxFreq=max(maxFreq,freq[s[r]]); //notice that you can do this
            //and that you do not have to FIND the maxfreq everytime

            //intuition for this is that a string is valid
            //only if its len-maxfreq is less than or equal to k
            //so do not use freq table like before
            while((r-l+1)-maxFreq>k){ //replace with if for an event better soln
                freq[s[l]]--;
                l++;
            }

            if ((r-l+1)-maxFreq<=k)
                ans=max(ans,r-l+1);
            r++;
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
