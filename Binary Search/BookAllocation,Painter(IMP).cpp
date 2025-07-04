class Solution {
public:
    int helper(vector<int>& nums, int k, int j){
        int cnt=1,sum=0;
        for(int i : nums){
            if(sum+i > j){
                cnt++;
                sum=0;
            }
            sum+=i;
        }
        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end()),mid; 
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<high){
            mid=low+(high-low)/2; 
            int temp=helper(nums,k,mid);
            if(temp <= k){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};