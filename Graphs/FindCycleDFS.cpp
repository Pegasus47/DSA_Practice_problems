class Solution {
public:
    bool helper(vector<vector<char>>& grid,pair<int,int> parent,vector<vector<int>>& seen,pair<int,int> child){
        int row=child.first; 
        int col=child.second;
        char c = grid[row][col];
        bool ans=false;
        seen[row][col]=1; 
        if(row>0 && grid[row-1][col]==c && make_pair(row-1,col)!=parent){
            if(seen[row-1][col]==1) return true; 
            ans= ans || helper(grid,make_pair(row,col),seen,make_pair(row-1,col));
            if(ans) return ans;
        }
        if(col>0 && grid[row][col-1]==c && make_pair(row,col-1)!=parent){
            if(seen[row][col-1]==1) return true; 
            ans= ans || helper(grid,make_pair(row,col),seen,make_pair(row,col-1));
            if(ans) return ans;
        }
        if(row<grid.size()-1 && grid[row+1][col]==c && make_pair(row+1,col)!=parent){
            if(seen[row+1][col]==1) return true; 
            ans= ans || helper(grid,make_pair(row,col),seen,make_pair(row+1,col));
            if(ans) return ans;
        }
        if(col<grid[0].size()-1 && grid[row][col+1]==c && make_pair(row,col+1)!=parent){
            if(seen[row][col+1]==1) return true; 
            ans= ans || helper(grid,make_pair(row,col),seen,make_pair(row,col+1));
            if(ans) return ans;
        }
        return ans;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<int>> seen(grid.size(),vector<int>(grid[0].size(),0));
        bool res=false;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(seen[i][j]==0){
                    res=res || helper(grid,make_pair(-1,-1),seen,make_pair(i,j));
                }
                if(res) return res;
            }
        }
        return false;
    }
};