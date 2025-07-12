#include<bits/stdc++.h>
using namespace std;

//NOTE: Importnant rec tree
class Solution {
public:
    void rec(vector<vector<int>>& ans,int index, vector<int>& nums){
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int j=index;j<nums.size();j++){
            swap(nums[index],nums[j]);
            rec(ans,index+1,nums); //its like all the ones to the right of index want to be at index
            swap(nums[index],nums[j]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        rec(ans,0,nums);
        return ans;
    }
};