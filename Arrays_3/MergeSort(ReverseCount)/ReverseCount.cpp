#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& arr,int left,int mid,int right) {
        int sizeL=mid-left+1;
        int sizeR=right-mid;

        vector<int> L(sizeL),R(sizeR);

        for (int i=0;i<sizeL;i++)
            L[i]=arr[left+i];
        for (int i=0;i<sizeR;i++)
            R[i]=arr[mid+1+i];

        int lp=0,rp=0;
        int arrp=left;
        while (lp<sizeL && rp<sizeR) {
            if (L[lp]<R[rp]) {
                arr[arrp]=L[lp];
                lp++;
            }else {
                arr[arrp]=R[rp];
                rp++;
            }
            arrp++;
        }

        while (lp<sizeL) {
            arr[arrp]=L[lp];
            lp++;
            arrp++;
        }

        while (rp<sizeR) {
            arr[arrp]=R[rp];
            rp++;
            arrp++;
        }
    }
    int countPairs(vector<int>& arr,int left, int mid, int right){
        int x=mid+1; //this will iterate through the second array
        int count=0; //to count occurances
        for(int i=left;i<=mid;i++){
            while(x<=right && (long long)arr[i]>2LL*arr[x]) x++; //long long to help with overflow
            count=count+(x-(mid+1)); //basically updating it in outer for loop
        }
        return count;
    }

    int mergeSort(vector<int>& arr,int left, int right) {
        int cntr=0;
        if (left>=right) //this coz then we'd effeticely be at 1 element and cant divide further
            return 0;
        int mid=left+((right-left)>>1);

        cntr+=mergeSort(arr,left,mid);
        cntr+=mergeSort(arr,mid+1,right); //calling on right
        cntr+=countPairs(arr,left,mid,right); //we assume that the above 2 steps makes the right and the left subarrays
        //sorted. Then we count the pairs BEFORE merging
        merge(arr,left,mid,right); //helper function to sort left and right subarrays in 1 pass
        return cntr;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};

int main() {
    Solution s;
    vector<int> arr={1,3,2,3,1};
    cout << s.reversePairs(arr);
}