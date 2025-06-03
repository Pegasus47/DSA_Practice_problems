#include <iostream>
#include <vector>
using namespace std;

//Brute: put arr2 in arr1 and sort
//TC:O((n+m)*log(n+m)) SC:O(1)
//Better: Use the 2 pointer approach in creating a new array and then copy that into arr1
//TC:O(n+m) SC:O(n+m)
//Optimal: Start from the end of this array and use it as the third array
//TC:O(n+m) SC:O(1)

//NOTE: Striver has a wrong solution for this. Please watch neetcode for this
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int c1 = m-1, c2 = n-1, c = m+n-1;
        while(c2 >= 0 && c1 >= 0) {
            if(nums2[c2] >= nums1[c1]) {
                nums1[c] = nums2[c2];
                c2--;
            } else {
                nums1[c] = nums1[c1];
                c1--;
            }
            c--;
        }
        //We dont need to copy remaining from arr1 coz they are already there

        // Copy remaining elements from nums2 (if any)
        while(c2 >= 0) {
            nums1[c] = nums2[c2];
            c2--;
            c--;
        }
    }
};


int main() {
    Solution s;
    vector<int> arr1={1,3,5,7,0,0,0,0,0};
    vector<int> arr2={0,2,6,7,8};
    s.merge(arr1,4,arr2,5);
    for (int i: arr1) {
        cout << i << " ";
    }
}
