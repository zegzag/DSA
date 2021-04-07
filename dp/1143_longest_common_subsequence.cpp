#include<string>
#include<vector>
using namespace std;
/*dp[i][j] := text1 [0, i), text2 [0, j)时最长公共子串的长度
    *dp[i][j+1] = dp[i][j] + 1 if s2[j+1] == s1[i]
    *dp[i+1][j] = dp[i][j] + 1 if s1[i+1] == s2[j]
    *dp[i+1][j+1] = dp[i][j] + 1 if s1[i+1] = s2[j+1]
    */
int longestCommonSubsequence(string text1, string text2) {
    size_t n1 = text1.size();
    size_t n2 = text2.size();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
    for (size_t i = 1; i <= n1; i++) {
        for (size_t j = 1; j <= n2; j++){
            if (text2[j-1] == text1[i-1]) {
                dp[i][j] = dp[i-1][j-1] +1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n1][n2];
}