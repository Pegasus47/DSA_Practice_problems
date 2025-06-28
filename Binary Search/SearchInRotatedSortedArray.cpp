class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,mid,high=nums.size()-1;
        while(low<=high){
            mid=low+(high-low)/2;

            if(nums[mid]==target) //if we find it, return it
                return mid;

            if(nums[low]<=nums[mid]){ //this means that the left half is monotonic
                //<= so as it if low and mid are the same numbers, just says that they in themselves are sorted
                //for egs: 5 1 2 3 4 & target is 5
                //if we don't use <=, it fails for [3,1] k=1
                if(nums[low]<=target && target<nums[mid]) //this =< coz nums[low] can be the target
                    high=mid-1;
                else
                    low=mid+1;
            }else{ //or the right half is
                if(nums[mid]<target && nums[high]>=target) //similarly here
                    low=mid+1;
                else
                    high=mid-1;
            }
        }
        return -1;
    }
};
