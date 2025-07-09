#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void help(vector<vector<int>>& ans,vector<int>& sub, int index,int target,int k){
        if(target==0 && sub.size()==k){ //base contition to get ur ans
            ans.push_back(sub);
            return;
        }
        if(sub.size()>k || index>9) //make sure of the conditions when to stop
            return;

        sub.push_back(index);
        help(ans,sub,index+1,target-index,k);
        sub.pop_back();
        help(ans,sub,index+1,target,k);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        // if(n<10 || n>45) //NOTE: Do not hard code shit like this
        //     return {{}};
        vector<vector<int>> ans;
        vector<int> sub;
        help(ans,sub,1,n,k);
        return ans;
    }
};
