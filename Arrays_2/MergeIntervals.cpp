#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// never condiser it sorted UNLESS expicitly mentioned
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {}; //always remember the base case

        vector<vector<int>> v;
        int start,end=0,cntr=0;
        sort(intervals.begin(),intervals.end()); //sorting a 2d vector
        //it will sort based on the first element, then the second, third, etc...
        //basically it sort LEXICOGRAPHICALLY
        v.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            start=intervals[i][0];
            end=intervals[i][1];
            if(start<=v[cntr][1])
                v[cntr][1]=max(v[cntr][1], end); //consider edge cases like
                //an interval might be inside another
            else{
                v.push_back({start, end});
                cntr++;
            }
        }
        return v;
    }
};

int main() {
    Solution s;
    vector<vector<int>> v={{1,3},{2,6},{8,10},{15,18}};
    v=s.merge(v);
    for (vector<int> x : v) {
        for ( int i: x) {
            cout << i << " ";
        }
        cout << endl;
    }
}