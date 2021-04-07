#include<vector>
using namespace std;

/* 这个特么的也忒简单了点吧;
  * dp[i][0]= min(dp[i-1][1], dp[i-1][2]) + costs[i][0];
  * dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + costs[i][1];
  * dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + costs[i][2];
  * 在求dp[i]的时候根本不需要考虑前i-1的color状态时什么样的，
  *  因为递推关系已经保证了在每步递推时作色不相同，最后只要求最小值就行了。
  */

int minCost(vector<vector<int>>& costs) {
    size_t n = costs.size();
    if (n == 0) return 0;
    vector<vector<int>> dp(n, vector<int>(3, 0));
    dp[0][0] = costs[0][0];
    dp[0][1] = costs[0][1];
    dp[0][2] = costs[0][2];
    for (size_t i = 1; i < n; i++) {
        dp[i][0]= min(dp[i-1][1], dp[i-1][2]) + costs[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + costs[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + costs[i][2];
    }
    return min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
}

//貌似可以优化空间复杂度？
