#include<bits/stdc++.h>
using namespace std;

//memoization solution

class Solution {
public:
    int help(vector<int>& nums,int i, vector<int>& dp){
        if(i<0) return 0;

        if(dp[i]!=-1) return dp[i];

        dp[i]=max(help(nums,i-1,dp),help(nums,i-2,dp)+nums[i]); //memoization
        //has recurrsive calls to fill array

        return dp[i]; //we start off with i=0 soo this will return value for i=0
    }

    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        vector<int> dp(nums.size(),-1); //remember this
        vector<int> dpp(nums.size(),-1);
        int noLast = help(nums,nums.size()-2,dp);
        nums.erase(nums.begin());
        int noFirst = help(nums,nums.size()-1,dpp);
        return max(noFirst,noLast);
    }
};

//