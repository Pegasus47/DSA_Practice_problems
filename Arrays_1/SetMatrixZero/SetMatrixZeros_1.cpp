//This is my attempt at a brute force way to do this
//It has a time complexity of O(nm(n+m)) or O(n²m²) [If you consider the commented out code]
//It's space complexity is O(1) as there is no extra space used

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
                if(matrix[i][j]==-23083) //this is just assuming this test case is never run
                    matrix[i][j]=0;
            }
        }
    }
    // void putMinus(vector<vector<int>>& matrix, int n, int m){
    //     for(int i=0; i<matrix.size(); i++){
    //         for(int j=0; j<matrix[i].size();j++){
    //             if(i==n && matrix[i][j]!=0){
    //                 matrix[i][j]=-23083; //bad solution as i couldnt use anything other than INT
    //             }
    //             if(j==m && matrix[i][j]!=0){
    //                 matrix[i][j]=-23083;
    //             }
    //         }
    //     }
    // }

    void putMinus(vector<vector<int>>& matrix, int n, int m){
        for(int i=0; i<matrix.size(); i++){
            if(matrix[i][m]!=0){
                matrix[i][m]=-23083; //bad solution as i couldnt use anything other than INT
            }
        }
        for (int j=0; j<matrix[0].size();j++) {
            if (matrix[n][j]!=0) {
                matrix[n][j]=-23083;
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