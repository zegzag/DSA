#include<vector>
using namespace std;
/* dp[i][j] := A[0, i], B[0, j]时最长公共后缀的长度。这里定义时，就吧A[i] == B[j] 包含在内了。
  * dp[i+1][j+1] = dp[i][j] +1 if A[i+1] == B[j+1] else 0;
  * 有时候如果定义问题后状态空间太多，
  * 不妨在定义时把状态限止得死一些，
  * 只要能解出最后的问题就行了。
*/

int findLength(vector<int>& A, vector<int>& B) {
    size_t na = A.size();
    size_t nb = B.size();
    vector<vector<int>> dp(na+1, vector<int>(nb+1, 0));
    int ans = 0;
    for (size_t i = 1; i <=na; i++) {
        for (size_t j = 1; j <=nb; j++){
            dp[i][j] = (A[i-1] == B[j-1]) ? dp[i-1][j-1] + 1 : 0;
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}