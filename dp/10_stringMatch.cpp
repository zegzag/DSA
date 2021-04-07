#include<string>
#include<vector>
#include<iostream>
using namespace std;


//递归求解
bool isMatch(string s, string p) {
    if(p.empty())
        return s.empty();
    if(p.empty() || s.empty())
        return false;
    bool first_match = (p[0] == '.') || (p[0]==s[0]);
    if(p.size()>=2 && p[1]=='*')
        return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
    else
        return first_match && isMatch(s.substr(1), p.substr(1));
}

//上面的是会出错的，下面的是不会出错的，仔细想想原因呐！

bool isMatch(string s, string p) {
    if(p.empty())
        return s.empty();
    bool first_match = (!s.empty()) && ((p[0] == '.') || (p[0]==s[0]));
    if(p.size()>=2 && p[1]=='*')
        return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
    else
        return first_match && isMatch(s.substr(1), p.substr(1));
}

//动态规划求解
bool isMatch(string s, string p) {
    int row = s.size(), col = p.size();
    vector<vector<bool>> dp(row+1, vector<bool>(col+1, false));
    dp[0][0]=true;
    
    //模式串匹配空串时，一般情况下的动态规划情况会退化。既是因为退化原因把这种情况单独拿出来，也是为一般情况下的动态规划做初始化。
    for(int c=1; c<col; c++)
        if(p[c]=='*')
            dp[0][c+1]=dp[0][c-1];
    
    //模式串和匹配串都不是空串时的动态规划规则。因为r从0开始，而dp[row]一项的取值永远都是从r+1开始，所以这里不包含模式串匹配空串时的情况。
    for(int r=0; r<row; r++)
        for(int c=0; c<col; c++){
            if(p[c]=='.' || p[c]==s[r])
                dp[r+1][c+1] = dp[r][c];
            else if(p[c]=='*'){
                if(c>0){
                    if(p[c-1]==s[r] || p[c-1]=='.')
                        dp[r+1][c+1] = dp[r+1][c] || dp[r+1][c-1] || dp[r][c+1];                
                    else
                        dp[r+1][c+1] = dp[r+1][c-1];
                }
            }
        }
    return dp[row][col];
}