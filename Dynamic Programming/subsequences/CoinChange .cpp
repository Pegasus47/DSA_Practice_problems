#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coin(vector<int>& coins, int amount,vector<int>& dp){
        if(amount==0)
            return 0;
        if(amount<0)
            return INT_MAX;
        if(dp[amount-1]!=-1)  return dp[amount-1];
        int mn=INT_MAX;
        for(int i=0;i<coins.size();i++){
            int temp=coin(coins,amount-coins[i],dp);
            if(temp==INT_MAX)   continue;
            mn=min(mn,1+temp);
        }
        return dp[amount-1]=mn;
    }

    int coinChange(vector<int>& coins, int amount) {
        //sort(coins.begin(),coins.end(),greater<int>());
        if(amount==0)   return 0;
        vector<int> dp(amount,-1);
        int ans=coin(coins,amount,dp);
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //sort(coins.begin(),coins.end(),greater<int>());
        if(amount==0)   return 0;
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int coin : coins){
            for(int i=coin;i<=amount;i++){
                if(dp[i-coin]==INT_MAX)     continue;
                dp[i]=min(dp[i],dp[i-coin]+1);
            }
        }
        if(dp.back()==INT_MAX)  return -1;
        return dp.back();
    }
};