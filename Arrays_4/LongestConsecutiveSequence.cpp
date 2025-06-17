#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        int len=1;
        unordered_set <int> us; //sets can only contain 1 of each element
        for(int i=0;i<nums.size();i++){
            us.insert(nums[i]);
        }
        for(auto it:us){
            if(us.find(it-1)==us.end()){
                int cnt=1;
                int x=it;
                while(us.find(x+1)!=us.end()) {
                    x++;
                    cnt++;
                }
                len=max(len,cnt);
            }
        }
        return len;
    }
};

int main() {
    Solution s;
    vector<int> v={1,3,5,3143,843,200,4,69,2};
    cout << s.longestConsecutive(v) << endl     ;
}