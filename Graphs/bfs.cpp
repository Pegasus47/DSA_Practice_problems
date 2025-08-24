class Solution {
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        vector<int> ans;
        queue<int> q;
        vector<int> seen(adj.size(),0);
        q.push(0);
        seen[0]=1;
        while(!q.empty()){
            for(int x : adj[q.front()]){
                if(seen[x]==0)
                    q.push(x);
                seen[x]=1;
            }
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};