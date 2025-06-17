#include<iostream>
#include<string>
#include<map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0) return 0;
        map<char,int> um;
        int ans=1,cntr=0,l=0,r=0;
        for(r=0;r<s.length();r++){
            if(um.find(s[r])!=um.end() && um[s[r]]>=l) //this second statement
            { //makes sense as we arent not deleting elements while coming to that
                //elemtent marked by the right
                //else if we were coming one by one that would have made sense too
                l=um[s[r]]+1;
            }
            um[s[r]]=r;
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};

int main() {
    Solution s;
    const string str="abcabcbba";
    cout << s.lengthOfLongestSubstring(str) << endl;
    return 0;
}
