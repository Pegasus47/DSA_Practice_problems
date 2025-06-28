#include<bits/stdc++.h>
using namespace std;

//LOWER BOUND: the smallest number more than or equal to target
//UPPER BOUND: the smallest number strictly more than target
//Main difference between this and binary search is that you let this run
//till condition l<=h isnt satisfied so that you check all the possibilies

//IMPORTANT CONCEPT

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb=-1;
        int l=0,h=nums.size()-1,m;
        while(l<=h){
            m=l+(h-l)/2;
            if(nums[m]>=target){ //if nums is more than or equal, go left
                if(nums[m]==target) //set only if equal
                    lb=m;
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        l=0;
        h=nums.size()-1;
        int ub=-1;
        while(l<=h){
            m=l+(h-l)/2;
            if(nums[m]>target){ //go left only if num[m] is STRICTLY greater
                h=m-1;
            }else{
                if(nums[m]==target) ub=m; //can only find nums[m] here and no in if ofc
                l=m+1;
            }
        }

        return {lb,ub};
    }
};

int main() {
    Solution s;
    vector<int> v={1,2,3,5,5,8,8,8,13};
    int target=8;
}