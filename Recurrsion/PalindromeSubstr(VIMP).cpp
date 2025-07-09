#include<bits/stdc++.h>
using namespace std;

//NOTE: important to practice to master recursion

class Solution {
public:
    bool isPal(string s){
        int l=0,r=s.size()-1;
        while(r>l){
            if(s[r]!=s[l])
                return false;
            r--;
            l++;
        }
        return true;
    }
    
    void ps(vector<vector<string>>& ans,string& s,int index,vector<string>& temp){

        if(index==s.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=index;i<s.size();i++){
            string str=s.substr(index,i-index+1); //substring starts at index and has
            //(i-index+1) number of digits
            //at every element we check which of the palindromes can be made which start with that element
            //we only make a recurrsive call if we find one
            if(isPal(str)){
                temp.push_back(str);
                ps(ans,s,i+1,temp); // i+1 works or index + substr.size() also works
                temp.pop_back(); //clear temp as the above call is made
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans; 
        vector<string> temp;
        ps(ans,s,0,temp);
        return ans;        
    }
};