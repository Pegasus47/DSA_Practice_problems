#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z=0,o=0,t=0;
        for(int i=0;i<nums.size();i++){
            switch(nums[i]){
                case 0:
                    z++;
                    break;
                case 1:
                    o++;
                    break;
                case 2:
                    t++;
                    break;
                default:
                    break;
            }
        }

        for(int i=0;i<nums.size();i++){
            if(z>0){
                z--;
                nums[i]=0;
            }else if(o>0){
                o--;
                nums[i]=1;
            }else if(t>0){
                t--;
                nums[i]=2;
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