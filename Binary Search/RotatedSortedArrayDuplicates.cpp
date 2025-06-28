class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0,mid,high=nums.size()-1;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]==target)
                return true; 
            if(nums[mid]==nums[low] && nums[mid]==nums[high]){ //only case it wont work
                //is if all the 3 are same so you wont know which side to look
                //TC is o(n) worst case
                low++;
                high--; 
                continue;
            }
            if(nums[low]<=nums[mid]){
                if(target>=nums[low] && target<nums[mid])
                    high=mid-1;
                else
                    low=mid+1;
            }
            else{
                if(target>nums[mid] && target<=nums[high])
                    low=mid+1;
                else
                    high=mid-1;
            }
        }
        return false;
    }
};