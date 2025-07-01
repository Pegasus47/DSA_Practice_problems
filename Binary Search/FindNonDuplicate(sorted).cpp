#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0,mid,high=nums.size()-1;
        while(low<high){ //don't less than equal as TLE
            //when you do < ans is usually where low ends
            //and when you do <= ans is usually where high ends
            mid=low+(high-low)/2;
            if(mid%2==1) //dont deal with odd cases, just make it even and check
                mid--;
            if(nums[mid]!=nums[mid+1])
                high=mid; 
            else 
                low=mid+2;
        }
        return nums[low];
    }
};

int main() {
    Solution s;
    vector<int> nums={1,1,2,2,3,4,4,5,5,6,6,7,7};
    cout << s.singleNonDuplicate(nums);

}