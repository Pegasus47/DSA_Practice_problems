#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //without writing numRows you cannot directly address memory
        vector<vector<int>> generate(numRows); //this means create numRows number of rows or no of elements
        //each row is still empty or each element only contains an empty vector<int>
        generate[0]={1}; //using an initialiser list to set the first 1
        for(int i=1;i < numRows;i++){
            generate[i].resize(i+1); //ensures that after resizing you have exactly
            //i+1 columns to use
            //if you want to use it like an array aka [][] --> use resize and make sure of the size
            //else keep pushing elements back
            generate[i][0]=1;
            generate[i][i]=1;
            for(int j=1;j < i;j++){
                generate[i][j]=generate[i-1][j]+generate[i-1][j-1];
            }
        }
        return generate;
    }
};

//The below is also a valid solution using only vector functions without resize

// class Solution {
// public:
//     vector<vector<int>> generate(int numRows) {
//         vector<vector<int>> triangle;
//         if(numRows==0)
//             return triangle;
//         triangle.push_back({1}); // {} --> this is a vector
//         for(int i=1;i<numRows;i++){
//             triangle.push_back({1});
//             for(int j=1;j<i;j++){
//                 int sum=triangle[i-1][j-1]+triangle[i-1][j];
//                 triangle[i].push_back(sum);
//             }
//             triangle[i].push_back(1);
//         }
//         return triangle;
//     }
// };
int main() {
    Solution s;
    int numRows=5;
    vector<vector<int>> sol=s.generate(numRows);
    for (int i=0;i < sol.size();i++) {
        for (int j=0;j < i+1;j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}