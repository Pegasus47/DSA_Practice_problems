#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        //if it is a rotation of s, it has to be a substring of s+s
        s=s+s;

        //s.find(goal) returns index of first occurance or string:npos
        //its datatype is size_t --> 32 bit unsigned
        //writing int x = s.find(goal) may result in funky stuffs
        if(s.find(goal)!=string::npos) //s.find(goal)
            return true;
        else
            return false;
    }
};