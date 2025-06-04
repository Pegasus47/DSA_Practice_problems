#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//BRUTE: Check for every element
//TC=O(n⁴) SC=O(1)

//BETTER: Iterate through all the elements and put in hashmap
//TC=O(n²) SC=O(n²)

//OPTIMAL: Use math. Let a be missing and b be extra
//use the sum of squares and sum of the grid to get 2 equations
//which on solving give you the values

//TC=O(n²) SC=O(1)


class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        if(grid.empty())
            return{}; //base case
        long long int sum=0,sum_sq=0;
        long long int gsum=0,gsum_sq=0;
        int grid_elem=grid.size()*grid.size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                gsum=gsum+grid[i][j];
                gsum_sq=gsum_sq+grid[i][j]*grid[i][j];
            }
        }
        sum=grid_elem*(grid_elem+1)/2;
        sum_sq=1LL*grid_elem*(grid_elem+1)*(2*grid_elem+1)/6; //use 1LL to force long multiplication
        long long int diff=gsum-sum;
        long long int diff_sq=gsum_sq-sum_sq;
        if(diff==0)
            return{0,(int)sqrt(diff_sq/2)}; //not needed as it is garanteed by the sum  to not happen
        //use the (int) to explicilty type-cast as we are pushing in vector <int>
        int extra=((diff_sq/diff)+diff)/2;
        int missing=((diff_sq/diff)-diff)/2;
        vector<int> v={extra,missing};
        return v;
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {
        {1,  2,  3,  4,  5},
        {6,  7,  8,  9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 23, 25}  // 23 is repeated, 24 is missing
    };

    vector<int> x=s.findMissingAndRepeatedValues(grid);
    for (int i: x) {
        cout << i << " ";
    }
}