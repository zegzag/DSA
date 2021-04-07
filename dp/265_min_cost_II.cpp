#include<vector>
#include<limits.h>
using namespace std;

/* 此题思路和256题一样，问题是，能够优化出O(nk)时间复杂度的算法吗？
   */

int minCostII(vector<vector<int>>& costs) {
    size_t N = costs.size();
    if (N == 0) return 0;
    size_t K = costs[0].size();
    vector<vector<int>> dp(N, vector<int>(K, 0));
    for (size_t k = 0; k < K; k++) {
        dp[0][k] = costs[0][k];
    }
    for (size_t i = 1; i < N; i++) {
        for (size_t k = 0; k < K; k++) {
            int dp_pre = INT_MAX;
            for (size_t j = 0; j < K; j++) {
                if (j == k) continue;
                dp_pre = min(dp_pre, dp[i-1][j]);
            }
            dp[i][k] = dp_pre + costs[i][k];
        }
    }
    int result = INT_MAX;
    for (size_t k = 0; k < K; k++) {
        result = min(result, dp[N-1][k]);
    }
    return result;
}