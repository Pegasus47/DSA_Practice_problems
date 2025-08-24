class Solution {
public:
    void dfs(vector<vector<char>>& board,pair<int,int> coord){
        int row=coord.first;
        int col=coord.second; 
        board[row][col]='I'; 
        if(row>0 && board[row-1][col]=='O'){
            dfs(board,{row-1,col});
        }
        if(col>0 && board[row][col-1]=='O'){
            dfs(board,{row,col-1});
        }
        if(row<board.size()-1 && board[row+1][col]=='O'){
            dfs(board,{row+1,col});
        }
        if(col<board[0].size()-1 && board[row][col+1]=='O'){
            dfs(board,{row,col+1});
        }
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<int>> seen(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++){
            if(board[i][0]=='O')    
                dfs(board,{i,0});
            if(board[i][board[0].size()-1]=='O')
                dfs(board,{i,board[0].size()-1});
        }
        for(int i=0;i<board[0].size();i++){
            if(board[0][i]=='O')
                dfs(board,{0,i});
            if(board[board.size()-1][i]=='O')
                dfs(board,{board.size()-1,i});
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
                if(board[i][j]=='I')
                    board[i][j]='O';
            }
        }
    }
};