#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
//NOTE: HASHMAP BASICS
/* CREATION:
 *     unordered_map<int, string> um = {{1, "Geeks"}, {2, "For"}, {3, "C++"}};
 *     1,2,3,etc are the keys and the names are the values
 *
 * PRINTING:
 *   for (auto i : um)
 *       cout << i.first << " " << i.second << endl;
 *
 * INSERTING:
 *  um[1] = "Geeks"; or um.insert({2,"Geek"}) --> [] updates if value present, .insert does not
 *
 * ACCESSING:
 *  um.at(1) or um[1] --> if no key is found [] will show default value
 *
 * UPDATION: Works similar to accessing and [] will create an element if not already there
 *
 * TRAVERSAL: for(auto it = um.begin(); it != um.end(); it++)   -->note that travesal is O(n)
 *       cout << it->first << ": " << it->second << endl;
 */

//Note: A sub optimal solution also exists where you sort the array with 2 pointer approach from beginning and ending

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int complement=target-nums[i];
            if(mp.find(complement)!=mp.end()){ //.find finds by key
                //if key is found the iterator to that key-value pair is returned
                //if key is not found it returns mp.end()
                return {mp[complement],i}; //.end is a special iterator that marks the end of the map
            }
            mp[nums[i]]=i; //whatever is in [] is the key and 'i' will be the value
        }
        return {};
    }
};

int main() {
    Solution s;
    vector v={3,4,6,8,7,5};
    int target=15;
    vector<int> ans=s.twoSum(v,target);
    for (int i : ans) {
        cout << i << " ";
    }
    return 0;
}
