#include<vector>
using namespace std;
/* dp[i][0] := 第i天结束时未持有股票的利润。
    * dp[i][1] := 第i天结束时持有股票的利润。
    * dp[i+1][0]  = max(dp[i][0], dp[i][1] + price[i+1])
    * dp[i+1][1]  = max(dp[i][1], -price[i+1])
    * tips:
    *  1.这里dp[i][1]的定义好像有些功能过了，不行要杀鸡用牛刀的样子。
    *  2. 注意dp[i+1][1]的递推公式，为什么就把"只买卖一次"的信息给包括进去了。
    */
int maxProfit(vector<int>& prices) {
    size_t n = prices.size();
    if (n < 2) return 0;
    int dp_0 = 0, dp_1 = -prices[0];
    for (int i  = 1;  i < n; i++) {
        dp_0 = max(dp_0, dp_1 + prices[i]);
        dp_1 = max(dp_1, -prices[i]);
    }
    return dp_0;
}