class Solution {
public:
    void help(vector<vector<int>>& adj,vector<int>& ans,vector<int>& seen,int node){
        seen[node]=1;
        ans.push_back(node);
        for(int x : adj[node]){
            if(!seen[x]){
                help(adj,ans,seen,x);
            }
        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> seen(adj.size(),0);
        vector<int> ans;
        seen[0]=1;
        help(adj,ans,seen,0);
        return ans;
    }
};