#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // a simpler solution is through an STL lib function
    // just call next_permutation(nums.begin(),nums.end());
    void nextPermutation(vector<int>& nums) {
        int bp=-1;
        for(int i=nums.size()-1;i > 0;--i){ //check notes for more detailed solutions
            if(nums[i-1]<nums[i]){
                bp=i-1;
                break;
            }
        }
        if(bp==-1){
            sort(nums.begin(),nums.end());
            return;
        }
        sort(nums.begin()+bp+1,nums.end());
        for(int i=bp+1;i<nums.size();i++){
            if(nums[i]>nums[bp]){
                int temp=nums[bp];
                nums[bp]=nums[i];
                nums[i]=temp;
                break;
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> v={1,2,3,4,5};
    s.nextPermutation(v);
    for (int i:v) { //this to seem cool
        cout << i;
    }
    return 0;
}
