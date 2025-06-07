#include<iostream>
#include<vector>
using namespace std;
//RANDOM FACT: Post C++20 there is a Threeway operator
//a <=> b returns <0 if b is more, >0 if a is more or 0 if equal
void merge(vector<int>& arr,int left,int mid,int right) {
    int sizeL=mid-left+1; //size of the left subarray
    int sizeR=right-mid; //size of the right subarray

    //note that the entire array is being passed but we will only be sorting the subarray

    vector<int> L(sizeL),R(sizeR); //vectors to temporarily store data

    for (int i=0;i<sizeL;i++) //copy left half onto left subarray
        L[i]=arr[left+i]; //left!=0 always so KEEP TRACK
    for (int i=0;i<sizeR;i++) //similarly for right
        R[i]=arr[mid+1+i];

    int lp=0,rp=0; //leftpointer, rightpointer
    int arrp=left; //arraypointer
    while (lp<sizeL && rp<sizeR) { //merging 2 sorted arrays code
        if (L[lp]<R[rp]) {
            arr[arrp]=L[lp];
            lp++;
        }else {
            arr[arrp]=R[rp];
            rp++;
        }
        arrp++;
    }

    while (lp<sizeL) { //if left has any elements left
        arr[arrp]=L[lp];
        lp++;
        arrp++;
    }

    while (rp<sizeR) { //if right has any elements left
        arr[arrp]=R[rp];
        rp++;
        arrp++;
    }
}

void mergeSort(vector<int>& arr,int left, int right) {
    if (left>=right) //this coz then we'd effeticely be at 1 element and cant divide further
        return;
        int mid=left+((right-left)>>1); //NOTE: BITWISE operators have a lower precedence
    //compared to +,-,/,*,%.etc
    //SIDENOTE: a+=b,a*=b,etc. have one of the least priority
    //SIDENOTE: a++, a-- have one of the highest priority
    mergeSort(arr,left,mid); //calling on left --> you should assume left will be sorted
    mergeSort(arr,mid+1,right); //calling on right
    merge(arr,left,mid,right); //helper function to sort left and right subarrays in 1 pass
}

int main() {
    vector<int> arr={3,5,7,6,2,5,3,1,9};
    mergeSort(arr,0,arr.size()-1);
    for (int i: arr) {
        cout << i << " ";
    }
}