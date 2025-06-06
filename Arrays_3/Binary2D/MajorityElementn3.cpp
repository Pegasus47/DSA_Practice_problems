#include <iostream>
#include <vector>
using namespace std;

//The trick here is to notice that only 2 can be more than n/3
//Only inc one at a time but dec if BOTH arent that element --> main intuition
//TC: O(n)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        // 1st pass: find potential candidates
        int x = 0, y = 1; // initialize to different values
        int c1 = 0, c2 = 0;
        for (int v : nums) {
            if (v == x) {
                c1++;
            }
            else if (v == y) {
                c2++;
            }
            else if (c1 == 0) {
                x = v;
                c1 = 1;
            }
            else if (c2 == 0) {
                y = v;
                c2 = 1;
            }
            else {
                c1--;
                c2--;
            }
        }

        // 2nd pass: verify counts
        c1 = 0;
        c2 = 0;
        for (int v : nums) {
            if (v == x) c1++;
            else if (v == y) c2++;
        }

        vector<int> ans;
        if (c1 > n / 3) ans.push_back(x);
        if (c2 > n / 3) ans.push_back(y);
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v={3,2,3};
    vector<int> x=s.majorityElement(v);
    for (int i: x) {
        cout << i;
    }
    return 0;
}