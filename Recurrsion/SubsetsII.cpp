#include<bits/stdc++.h>
using namespace std;


//subsets 1 is similar but no dupicate handling required

class Solution {
public:
    void help(vector<vector<int>>& ans,vector<int>& nums,vector<int>& sub, int index){
        if(index==nums.size()){
            ans.push_back(sub);
            return;
        }
        //------------
        sub.push_back(nums[index]);
        help(ans,nums,sub,index+1); //these 3 are combined
        sub.pop_back();
        //----------
        index++;
        while(index<nums.size() && nums[index]==nums[index-1]) //skip over all same numbers
            index++;

        help(ans,nums,sub,index);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> sub;
        help(ans,nums,sub,0);
        return ans;
    }
};
