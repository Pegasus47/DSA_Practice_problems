#include<bits/stdc++.h>
using namespace std;

//to get a O(1) space, do the following
//1. remove the extra spaces, trailing or not
//2. reverse the entire string
//3. reverse each word indivisually

class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int i=0;
        string temp="";
        while(i<s.size() && s[i]==' ') i++;
        for(;i<s.size();i++){
            if(i>0 && s[i]==' ' && s[i-1]==' ') continue;
            if(s[i]==' '){
                st.push(temp);
                temp="";
                //while(i<s.size() && s[i]==' ') i++;
            }
            else{
                temp+=s[i];
            }
        }
        st.push(temp);
        string ans="";
        while(!st.empty()){
            string s=st.top();
            ans+=s;
            ans+=" ";
            st.pop();
        }
        ans.pop_back();
        if(ans[0]==' ')
            ans.erase(0,1);
        return ans;
    }
};