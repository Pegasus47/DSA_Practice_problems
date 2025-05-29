//this is the fully optimised solution to the problem
//we use the first row and first col of the matrix to store the values
//there are 2 more varibles that keep count of if the first row/col is zero (diffrent from Striver)
// O(nm)-->time O(1)-->space

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int a=matrix.size();
        int b=matrix[0].size();

        bool firstRowZero=false; //tell us if the first colomn should be set to 0 or not
        bool firstColZero=false; //tells us if the first row should be zeros or not

        for(int i=0;i<a;i++){
            if(matrix[i][0]==0)
                firstColZero=true;
        }
        for(int i=0;i<b;i++){
            if(matrix[0][i]==0)
                firstRowZero=true;
        }

        for (int i = 1; i < a; i++) {
            for (int j = 1; j < b; j++) {
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }

        for(int i=1; i < matrix.size();i++){
            for(int j=1; j<matrix[i].size();j++){
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
            }
        }

        if(firstColZero){
            for(int i=0;i<a;i++)
                matrix[i][0]=0;
        }
        if(firstRowZero){
            for(int i=0;i<b;i++)
                matrix[0][i]=0;
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