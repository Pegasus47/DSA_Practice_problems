#include <iostream>
#include <vector>
using namespace std;

//BRUTE: Check all elements indivisually
//TC=O(n*m)
//BETTER: Linear search(if target b/w first and last elem) to check which row elem is in/isnt, Binary search then
//TC=O(n)+O(log(m))
//OPTIMAL: Binary search of rows, then coloumns
//TC=O(log(n*m))

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int mid,low=0,high=matrix.size()-1;
        while(low<=high){
            mid=low+(high-low)/2;
            if(matrix[mid][0]==target)
                return true;
            else if(matrix[mid][0]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        int row=high;

        if(row<0) //this is for if the element is smaller that the first elem of row aka high=-1
            return false; //notice error like this from dry run/cout and fix


        low=0;
        high=matrix[0].size()-1;

        while(low<=high){
            mid=low+(high-low)/2;
            if(matrix[row][mid]==target)
                return true;
            else if(matrix[row][mid]>target)
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