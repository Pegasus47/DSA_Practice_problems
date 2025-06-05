#include <iostream>
#include <vector>
using namespace std;

//Same TC as the other solution but this is the solution while flattening the 2D array into 1D

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x,y,mid,low=0,high=matrix.size()*matrix[0].size()-1; //notice low and high
        while(low<=high){
            mid=low+(high-low)/2; //mid is the same
            y=mid%matrix[0].size(); //row = mid % noofcol;
            x=mid/matrix[0].size();//col = mid / noofcol;
            if(matrix[x][y]==target)
                return true;
            else if(matrix[x][y]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<vector<int>> arr={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target=16;
    cout << ((s.searchMatrix(arr,target))?"Found":"Not Found");
    return 0; //added implicilty by compilers usually
}