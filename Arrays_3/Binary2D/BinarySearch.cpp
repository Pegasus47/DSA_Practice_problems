#include <iostream>
#include <vector>
using namespace std;

//Basically a reccursion revision coz i am dumb
//TC=O(log N)
bool bin(vector<int>& arr, int low, int high, int target) {
    if (low>high)
        return false;
    int mid=low+(high-low)/2; //this is for int safety as low+high 'might' go out of range
    if (arr[mid]==target)
        return true;
    else if (arr[mid]>target)
        return bin(arr,low,mid-1,target);
    else
        return bin(arr,mid+1,high,target);
}

// Iterative Binary Search Function
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Prevents potential overflow

        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    return -1; // Target not found
}

int main() {
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 8;
    bool found = bin(arr, 0, arr.size() - 1, target);
    cout << (found ? "Found" : "Not Found") << endl;
    return 0;
}