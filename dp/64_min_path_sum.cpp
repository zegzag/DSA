#include<vector>
using namespace std;
/* dp[i][j] := 走到[i][j]时 最小路径和
    * dp[i+1][j] = dp[i][j] + grid[i+1][j]
    * dp[i][j+1] = dp[i][j] + grid[i][j+1]
    * dp[i+1][j+1] = min(dp[i+1][j], dp[i][j+1]) + grid[i+1][j+1]
    */

int minPathSum(vector<vector<int>>& grid) {
    size_t m = grid.size();
    if (m == 0) return 0;
    size_t n = grid[0].size();
    if (n == 0) return 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j <n; j++) {
            if (i == 0) {
                if (j == 0) {
                    dp[i][j] = grid[i][j];
                } else {
                    dp[i][j] = dp[i][j-1] + grid[0][j];
                }
            } else {
                if (j == 0) {
                    dp[i][j] = dp[i-1][j] + grid[i][0];
                } else {
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
                }
            }
        }
    }
    return dp[m-1][n-1];
}