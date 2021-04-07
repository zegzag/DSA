#include<cstring>
#include<iostream>
#include<vector>
using namespace std;

string longestPalindrome(string s){
    if (s == "")
        return "";
    int len = s.size();
    int left = 0, right = 0, maxlen = 0;
    vector<vector<bool>> dp(len, vector<bool>(len, false));
    for(int i = 0; i<len; i++){
        dp[i][i]=true;
        if(i+1<len && s[i+1]==s[i]){
            dp[i][i+1]=true;
            maxlen = 1;
            left = i;
        }
    }
    for(int k = 2; k<len; k++){
        for(int i = 0; i+k<len; i++){
            if(s[i+k]==s[i])
                dp[i][i+k]=dp[i+1][i+k-1] && true;
            else
                dp[i][i+k]=false;
            if(dp[i][i+k]==true){
                maxlen = k;
                left = i;
            }
        }
    }
    return s.substr(left, maxlen+1);
}