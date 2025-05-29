//This is a slightly more optimised solution for the problem
//The time complexity is now the minimum of what it can be O(nm) as that is the minimum
//amount of time required to traverse a 2D matrix
//Here an extra space of the order O(n+m) is also being used to store the rows and col vectors

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int a = matrix.size(); //gets the number of rows
        int b = matrix[0].size(); //gets the number of columns

        // int rows[a]{0}; -->you cannot use this as you do not know the
        // int col[b]{0}; -->size of the matrix at "COMPILE TIME"

        vector<int> rows(a,0); //this initialises a vector of size a with all 0s
        vector<int> col(b,0); // ''
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if(matrix[i][j]==0){
                    rows[i]=-1;
                    col[j]=-1;
                }
            }
        }

        for(int i=0; i < matrix.size();i++){
            for(int j=0; j<matrix[i].size();j++){
                if(rows[i]==-1 || col[j]==-1)
                    matrix[i][j]=0;
            }
        }
    }
};
int main() {
    Solution s;
    vector<vector<int>> matrix={{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    s.setZeroes(matrix);
    for (int i=0;i<matrix.size();i++) {
        for (int j=0;j<matrix[i].size();j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}