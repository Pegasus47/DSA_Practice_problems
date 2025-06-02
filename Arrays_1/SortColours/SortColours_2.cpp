#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                // int temp=nums[mid];
                // nums[mid]=nums[low];
                // nums[low]=temp;

                swap(nums[low],nums[mid]);
                mid++;
                low++;
            }else if(nums[mid]==1){
                mid++;
            }else if(nums[mid]==2){
                int temp=nums[mid];
                nums[mid]=nums[high];
                nums[high]=temp;
                high--;
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> v={0,0,1,1,2,2};
    s.sortColors(v);
    for (int i : v) {
        cout << i <<" ";
    }
}