#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void combine(vector<int>& candidates,vector<vector<int>>& ans,vector<int> sum,int target,int index){
        if(target==0){
            ans.push_back(sum);
            return;
        }
        if(index >= candidates.size())
            return;
        if(target-candidates[index]>=0){
            sum.push_back(candidates[index]); //note that usually these 3 come together
            //add that element and call and then remove that element for anything further
            combine(candidates,ans,sum,target-candidates[index],index);
            sum.pop_back();
        }
        combine(candidates,ans,sum,target,index+1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> sum;
        combine(candidates,ans,sum,target,0);
        return ans;
    }
};
