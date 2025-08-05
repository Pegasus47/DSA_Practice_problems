#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    struct Comp{
        bool operator()(pair<int,int> a, pair<int,int> b){
            return a.second < b.second;
        }
    };
    
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> um; 
        for(int i : nums){
            um[i]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,Comp> pq;

        for(auto& p : um){
            pq.push(p);
        }

        vector<int> res;
        while(k--){
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};