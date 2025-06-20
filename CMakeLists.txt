cmake_minimum_required(VERSION 3.31)
project(DSA_striver_sheet)

set(CMAKE_CXX_STANDARD 23)

add_executable(DSA_striver_sheet
        notQuitePalindrome.h
        Arrays_1/SetMatrixZero/SetMatrixZeros_1.cpp
        Arrays_1/SetMatrixZero/SetMatrixZeros_2.cpp
        cmake-build-debug/SetMatrixZeros_3.cpp
        cmake-build-debug/SetMatrixZeros_3.h
        Arrays_1/PascalsTriangle/PascalsTriangle_1.cpp
        Arrays_1/NextPermutation.cpp
        Arrays_1/MaxSubArray/MaxSubArray_2.cpp
        Arrays_1/MaxSubArray/MaxSubArray_1.cpp
        Arrays_1/SortColours/SortColours_1.cpp
        Arrays_1/SortColours/SortColours_2.cpp
        Arrays_2/RotateMatrix.cpp
        Arrays_2/MajorityElement.cpp
        Arrays_2/MergeIntervals.cpp
        Arrays_2/MergeSortedArray.cpp
        Arrays_2/FindDuplicate.cpp
        Arrays_2/MissingRepeatedValues.cpp
        Arrays_3/Binary2D/BinarySearch.cpp
        Arrays_3/Search2DMatrix.cpp
        OOP.cpp
        "Arrays_3/Binary2D/Flattening2DMatrix.cpp"
        Arrays_3/PowFunction.cpp
        Arrays_3/MajorityElementn3.cpp
        "Arrays_3/UniquePaths.cpp"
        "Arrays_3/MergeSort(ReverseCount)/MergeSort.cpp"
        "Arrays_3/MergeSort(ReverseCount)/ReverseCount.cpp"
        Arrays_4/2_sum.cpp
        "CodeForce Contests/CF1029(Div 3)/1029A.cpp"
        "CodeForce Contests/CF1029(Div 3)/1029B.cpp"
        Arrays_4/3sum.cpp
        Arrays_4/4sum.cpp
        Arrays_4/LongestConsecutiveSequence.cpp
        Arrays_4/SubArraySum/SubArraySum_brute.cpp
        Arrays_4/SubArraySum/SubArraySum_optimal.cpp
        Arrays_4/LongestSSwoRepeats.cpp
        LinkedList1/ReverseLL.cpp
        "CodeForce Contests/CF1032(Div 3)/1032A.cpp"
        "CodeForce Contests/CF1032(Div 3)/1032B.cpp"
        "CodeForce Contests/CF1032(Div 3)/1032C.cpp"
        LinkedList1/MiddleLL.cpp
        LinkedList1/MergeSortedLL.cpp
        LinkedList1/DeleteKthFromEnd.cpp
        LinkedList1/AddNumbersLL.cpp
        LinkedList1/DeleteNodeLL.cpp
        LinkedList2/IntersectionOfLL/IntersectionOfLL.cpp
        LinkedList2/IntersectionOfLL/Intersection_optimal.cpp
        LinkedList2/LinkedListCycle.cpp
        LinkedList2/PalindromeLL.cpp
        LinkedList2/DetectLoopLL.cpp
        LinkedList2/ReverseNodesinKthGroup.cpp
        LinkedList2/FlattenLL.cpp
)
