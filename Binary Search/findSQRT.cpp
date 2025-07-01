class Solution {
public:
    int mySqrt(int x) {
        int low=0,high=x,sq=0; 
        long long mid; //to prevent overflow
        while(low<=high){
            mid=low+(high-low)/2; 
            if(mid*mid <= x){ //update the answer in a seperate variable to make life easy
                low=mid+1;
                sq=mid;
            }
            else
                high=mid-1; 
        }
            return sq;
    }
};