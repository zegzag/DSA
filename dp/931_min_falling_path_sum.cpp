#include<vector>
#include<limits.h>
using namespace std;
/*dp[i][j] := 到达[i][j] 时候的下降路径最小和
    *dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]) + matrix[i][j];
    */

int minFallingPathSum(vector<vector<int>>& matrix) {
    int m = matrix.size();
    if (m == 0)  return 0;
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int ans = INT_MAX;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0) {
                dp[i][j] = matrix[i][j];
            } else {
                if (j == 0) {
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j+1]) + matrix[i][j];
                } else if (j == n-1) {
                    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + matrix[i][j];
                } else {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i-1][j+1])) \
                                        + matrix[i][j];
                }
            }
        }
    }
    for (int j = 0; j < n; j++) {
        ans = min(ans, dp[m-1][j]);
    }
    return ans;
}