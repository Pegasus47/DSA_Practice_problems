#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums,int start,int target) {
        vector<vector<int>> v;
        long long int left,right,comp; //preventing overflow
        for(int i=start;i<nums.size();i++){ //start replaced by 0
            comp=0LL+target-nums[i]; //forcing LL operation
            left=i+1;
            right=nums.size()-1;
            if(i>start && nums[i]==nums[i-1]) continue;
            while(left<right){
                if(nums[left]+nums[right]==comp){
                    v.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    while(left<right && nums[left]==nums[left-1]) left++;
                    while(left<right && nums[right]==nums[right+1]) right--;
                }
                else if(nums[left]+nums[right]<comp){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return v;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> arr;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue; //skip over duplicates
            //check i>0 before ever accessing it
            vector<vector<int>> temp= threeSum(nums,i+1,target-nums[i]);
            if(temp.empty())
                continue;
            for (vector<int> x: temp){
                x.push_back(nums[i]);
                arr.push_back(x);
            }
        }
        return arr;
    }
};

int main() {
    Solution s;
    vector<int> x={1,0,-1,0,-2,2};
    int target=0;
    vector<vector<int>> arr=s.fourSum(x,target);
    for (vector<int> x: arr) {
        for (int i: x) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}

