#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            nums[k]=nums[i];
            k++;
        }
        return k;
    }
};

int main() {
    Solution s;
    vector<int> v={1,2,3,3,4,5,6,6};
    int k=s.removeDuplicates(v);
    for (int i=0;i<k;i++) {
        cout << v[i] << " ";
    }
}

