#include<bits/stdc++.h>
using namespace std;

/*BRUTE FORCE / RECURRSION*/

class Solution {
public:
    int helper(vector<vector<int>>& grid,int m,int n,int sum){
        if(m==grid.size()-1 && n==grid[0].size()-1){
            return sum+grid[m][n]; //consider the last element
        }
        int down,right;
        if(m<grid.size()-1)
            down=helper(grid,m+1,n,sum+grid[m][n]);
        else
            down=INT_MAX;
        if(n<grid[0].size()-1)
            right=helper(grid,m,n+1,sum+grid[m][n]);
        else
            right=INT_MAX;

        return min(down,right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        return helper(grid,0,0,0);
    }
};

/*MEMOIZATION SOLN*/

class Solution {
public:
    int helper(vector<vector<int>>& grid,int m,int n,vector<vector<int>>& dp){ //do not use sum variable
        //you will be polluting the recurrsive calls as you might have come to the same
        //m and n with 10 and then later come with 5 but that wont work as its already
        //initializaed to 10
        if(m==grid.size()-1 && n==grid[0].size()-1){
            return grid[m][n]; //consider the last element
        }
        int down,right;
        if(dp[m][n]!=-1) return dp[m][n];
        if(m<grid.size()-1)
            down=helper(grid,m+1,n,dp);
        else
            down=INT_MAX;
        if(n<grid[0].size()-1)
            right=helper(grid,m,n+1,dp);
        else
            right=INT_MAX;

        return dp[m][n]=grid[m][n]+min(down,right); //memoize as you go on
    }

    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        return  helper(grid,0,0,dp);
    }
};


/*TABULATION*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i==0 && j==0) dp[i][j]=grid[i][j]; //base case-->do nothing
                int up=INT_MAX,right=INT_MAX;
                if(i>0)
                    up=dp[i-1][j];
                if(j>0)
                    right=dp[i][j-1];
                if(up==INT_MAX && right==INT_MAX)
                    dp[i][j]=grid[i][j];
                else
                    dp[i][j]=grid[i][j]+min(up,right);
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};
