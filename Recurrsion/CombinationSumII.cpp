#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void help(vector<int>& candidates, int target, vector<vector<int>>& ans,
              vector<int>& sub, int cnt, int sum) {

        if (sum == target) {
            ans.push_back(sub);
            return;
        }
        if (cnt == candidates.size() || sum > target) //if sum >, dont need to go further
            return;

        // Take current element
        sub.push_back(candidates[cnt]);
        help(candidates, target, ans, sub, cnt + 1, sum + candidates[cnt]);
        sub.pop_back();  // Backtrack immediately

        // Skip current element and all its duplicates
        int next = cnt + 1;
        while (next < candidates.size() && candidates[next] == candidates[cnt])
            next++;

        // Only recurse if next is valid
        if (next < candidates.size()) {
            help(candidates, target, ans, sub, next, sum);
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> sub;
        help(candidates, target, ans, sub, 0, 0);
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v={2,4,5,1,4,2,4,4,7,9,4};
    int target=8;
}