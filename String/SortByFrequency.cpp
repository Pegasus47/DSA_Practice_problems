#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //ONLY static functions will work and custom comparators
    //auto parameters can only be used in lambda functions
    //pain<x,y> can just be used like a datatype / obj
    static bool comp(pair<char,int> a, pair<char,int> b){
        if(a.second == b.second ) return a.first > b.first;
        return a.second > b.second; //decending order
    }

    string frequencySort(string s) {
        unordered_map<char,int> um;
        for(char c : s){
            um[c]++;
        }
        vector<pair<char,int>> v(um.begin(),um.end()); //if you give a vector
        //begin and end parameters of um or another vector
        //it will be copied
        sort(v.begin(),v.end(),comp); //comp is custom comparator
        //you can also use the inline lambda function below to save you time

        // sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
        //     if (a.second == b.second) return a.first > b.first;
        //     return a.second > b.second;
        // });

        //https://www.geeksforgeeks.org/cpp/how-to-create-vector-of-pairs-in-cpp/
        //check that out for more info about vector pairs

        string ans="";
        for(auto& p : v){
            char ch=p.first;
            int freq=p.second;
            ans += string(freq, ch); //this pushes back 'ch','freq' number of times
        }
        return ans;
    }
};