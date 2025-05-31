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
)
