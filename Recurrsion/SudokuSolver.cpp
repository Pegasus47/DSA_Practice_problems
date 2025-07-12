#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<char> possible(vector<vector<char>>& board,int m,int n){
        static const vector<char> best={'1','2','3','4','5','6','7','8','9'};
        unordered_set<char> avoid; //best to use a hash set

        for(int i=0;i<9;i++){
            if(board[m][i]!='.') //checking rows
                avoid.insert(board[m][i]);
            if(board[i][n]!='.') //checking cols
                avoid.insert(board[i][n]);
        }
        int col = n/3,row=m/3; 
        for(int i=row*3;i<(3*row+3);i++){ //checking the grid
            for(int j=col*3;j<(3*col+3);j++){
                if(board[i][j]!='.')
                    avoid.insert(board[i][j]);
            }
        }
        vector<char> result; //doing (best-avoid) == valid
        for(char c : best){
            if(avoid.find(c)==avoid.end())
                result.push_back(c);
        }
        return result;
    }
    vector<int> next(vector<vector<char>>& board,int m,int n){ //to find the next free box
        for(int i=m;i<9;i++){
            //j is like that coz it can only overflow in the first case
            for(int j=((i == m) ? n + 1 : 0);j<9;j++){
                if(board[i][j]=='.')
                    return{i,j};
            }
        }
        return {-1,-1};
    }
    bool helper(vector<vector<char>>& board,int m,int n){
        vector<char> pos=possible(board,m,n); //checks if anything is possible or not
        if(pos.empty())
            return false; 
        
        for(char c : pos){
            board[m][n]=c;

            vector<int> nx=next(board,m,n);
            if(nx[0]==-1) //means there is no free element
                return true;

            if(helper(board,nx[0],nx[1])) //this is the MOST imp
                return true; // this returns true so that the entire function
            //stops executing when we have solved this
            //VERY IMPORTANT concept to remember

            board[m][n]='.'; //backtrack
        }
        return false; //no possible combination
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<int> nxt=next(board,0,0);
        if(board[0][0]=='.')
            helper(board,0,0);
        else
            helper(board,nxt[0],nxt[1]);
    }
};