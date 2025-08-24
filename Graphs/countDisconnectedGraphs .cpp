#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,vector<int>& seen,int node){
        seen[node]=1; //as soon as it comes, see it
        for(int i=0;i<isConnected.size();i++){ //modified to work for a adj matrix
            if(i==node) continue; 
            if(isConnected[node][i]==1 && !seen[i]){
                dfs(isConnected,seen,i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> seen(isConnected.size(),0);
        int ans=0;    
        for(int i=0;i<isConnected.size();i++){
            if(!seen[i]){
                ans++;
                dfs(isConnected,seen,i);
            } 
        }
        return ans;
    }
};