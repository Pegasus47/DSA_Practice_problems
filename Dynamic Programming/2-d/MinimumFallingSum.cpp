#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    /*
     * YOU WOULD NEED THIS ONLY IF YOU WANT TO USE MEMOIZAITON OR DIRECT RECURRSION
     */

    // int help(vector<vector<int>>& matrix, int m, int n,vector<vector<int>>& dp){
    //     if(n<0 || n>matrix[0].size()-1) return INT_MAX;
    //     if(m==matrix.size()-1){
    //         return matrix[m][n];
    //     }
    //     if(dp[m][n]!=-101)    return dp[m][n];
    //
    //     int left=help(matrix,m+1,n-1,dp);
    //     int down=help(matrix,m+1,n,dp);
    //     int right=help(matrix,m+1,n+1,dp);
    //
    //     return dp[m][n]=matrix[m][n]+min({left,down,right});
    // }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        //if(matrix.size()==1) return *min_element(matrix[0].begin(),matrix[0].end());
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-101));
        dp[0]=matrix[0];
        for(int i=1;i<matrix[0].size();i++){
            for(int j=0;j<matrix.size();j++){
                int up=dp[i-1][j];
                int left=(j>0)?dp[i-1][j-1]:INT_MAX;
                int right=(j<matrix[0].size()-1)?dp[i-1][j+1]:INT_MAX;
                dp[i][j]=matrix[i][j]+min({up,left,right});
            }
        }
        return *min_element(dp[dp.size()-1].begin(),dp[dp.size()-1].end());
    }
};
