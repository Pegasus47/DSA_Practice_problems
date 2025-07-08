#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void binary(string s,int n, vector<string>& ans){
        if(s.size()==n){ //this also stops the size from ballooning up any further
            ans.push_back(s);
            return;
        }
        binary(s+'1',n,ans);
        if(s.empty()||s.back()!='0') //s.empty is for the right half of the recurrsion tree
            binary(s+'0',n,ans);
    }

    vector<string> validStrings(int n) {
        vector<string> ans;
        binary("",n,ans);
        return ans;
    }
};

int main() {
    Solution s;
    int n=5;
    vector<string> v=s.validStrings(n);
    for (string s : v) {
        cout << s << " ";
    }
}