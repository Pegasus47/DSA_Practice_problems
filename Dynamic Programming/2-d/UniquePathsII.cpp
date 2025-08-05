#include<bits/stdc++.h>
using namespace std;
/* BRUTE FORCE + Memoization soln*/
class Solution {
public:
    int paths(vector<vector<int>>& obstacleGrid,int m, int n,vector<vector<int>>& dp){
        if(m>=obstacleGrid.size() || n>=obstacleGrid[0].size())
            return 0;
        if(obstacleGrid[m][n]==1)
            return dp[m][n]=0;
        if(m==obstacleGrid.size()-1 && n==obstacleGrid[0].size()-1){
            return dp[m][n]=1;
        }

        if(dp[m][n]!=-1)
            return dp[m][n];

        return dp[m][n]=paths(obstacleGrid,m+1,n,dp)+paths(obstacleGrid,m,n+1,dp);
    }

    int uniquePathsWithObstaclesTablulation(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
        return paths(obstacleGrid,0,0,dp);
    }
};

/*TABLULATION*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
        if(obstacleGrid[0][0]==1)   return 0; //important case
        //while assigning values make sure that it is valid to assign values
        dp[0][0]=1;
        int up,left;
        for(int i=0;i<obstacleGrid.size();i++){
            for(int j=0;j<obstacleGrid[0].size();j++){
                if(i==0 && j==0) continue; //in the loops,never consider what you have already declared
                if(i>0)
                    up=dp[i-1][j];
                else
                    up=0;
                if(j>0)
                    left=dp[i][j-1];
                else
                    left=0;
                if(obstacleGrid[i][j]==1)
                    dp[i][j]=0;
                else
                    dp[i][j]=up+left;
            }
        }
        return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1]; //this will give you the number of ways to
        //reach the last element of the dp
    }
};