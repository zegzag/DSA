#include<vector>
using namespace std;
/* dp[i][0] := 第i天未持有股票时的收益。
    * dp[i][1] := 第i天持有股票时的收益。
    * dp[i+1][0] = max(dp[i][0], dp[i][1] + price[i])
    * dp[i+1][1] = max(dp[i][1], dp[i][0] - price[i])
    *  tips:
    *      1. 注意这里动态规划转移方程和T121的区别。
    */
int maxProfit(vector<int>& prices) {
    size_t n = prices.size();
    if (n < 2) return 0;
    int dp_0 = 0, dp_1 = -prices[0];
    for (size_t i = 1; i < n; i++) {
        dp_0 = max(dp_0, dp_1 + prices[i]);
        dp_1 = max(dp_1, dp_0 - prices[i]);
    }
    return max(dp_0, dp_1);
}