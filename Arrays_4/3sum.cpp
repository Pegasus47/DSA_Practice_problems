#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        sort(nums.begin(),nums.end());
        int left,right,comp;
        for(int i=0;i<nums.size();i++){
            comp=0-nums[i];
            left=i+1;
            right=nums.size()-1;
            if(i>0 && nums[i]==nums[i-1]) continue;
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
};


int main() {
    Solution s;
    vector<int> v={-1,0,2,-1,1,3};
    vector<vector<int>> arr=s.threeSum(v);
    for (vector<int> x:arr) {
        for (int i: x) {
            cout << i << " ";
        }
        cout << endl;
    }
}