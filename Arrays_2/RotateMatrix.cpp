#include <iostream>
#include <vector>
using namespace std;

//The brute force solution to this problem could be taking the first row and replacing is at the last
//column in another n*n matrix
//TC would be O(n²) but the SC would also be O(n²)

//This solution ha TC as O(n²) but SC as O(1) as it is in place.
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=i;j<matrix.size();j++){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix.size()/2;j++){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[i][matrix.size()-j-1];
                matrix[i][matrix.size()-j-1]=temp;
            }
        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> v= {{1,2,3},{4,5,6},{7,8,9}};
    s.rotate(v);
    for (vector<int> arr : v) {
        for (int i : arr) {
            cout << i << " ";
        }
        cout << endl;
    }
}