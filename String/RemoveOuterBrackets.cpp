#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=0;
        string str;
        //when to update count and when to check for conditions is important
        for(char c : s){
            if(c=='('){
                if(cnt>0) //if count is 0 means its a starting bracket
                    str+=c;
                cnt++;
            } else {
                cnt--; //it count it 0 means its an ending bracket
                if(cnt>0)
                    str+=c;
            }
        }
        return str;
    }
};
