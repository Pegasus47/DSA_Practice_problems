#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> v;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if(matrix[i][j]==0){
                    putMinus(matrix,i,j);
                    cout << "i: " << i << " j: "<<j <<endl;
                    matrix[i][j]=0;
                }
            }
        }

        for(int i=0; i < matrix.size();i++){
            for(int j=0; j<matrix[i].size();j++){
                if(matrix[i][j]==-23083)
                    matrix[i][j]=0;
            }
        }
    }
    void putMinus(vector<vector<int>>& matrix, int n, int m){
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size();j++){
                if(i==n && matrix[i][j]!=0){
                    matrix[i][j]=-23083;
                }
                if(j==m && matrix[i][j]!=0){
                    matrix[i][j]=-23083;
                }
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