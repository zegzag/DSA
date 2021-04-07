#include<vector>
#include<limits.h>
using namespace std;

/* 每天结束后，会处于五中状态当中的一种。
    * 0: 未进行任何操作
    * 1: 进行了一次买操作
    * 2: 进行了一次买和卖的操作
    * 3: 进行了一次买和卖的操作，又进行了一次买操作。
    * 4: 两次买卖都完成了。
    * 由以上我们定义状态转移方程dp[i][k] := 第i天时处于状态k时的最大利润。
    * 转移公式：
    * dp[i+1][0] = dp[i][0] = 0
        dp[i+1][1] = max(dp[i][1], dp[i][0] - price[i])
        dp[i+1][2] = max(dp[i][2], dp[i][1] + price[i])
        dp[i+1][3] = max(dp[i][3], dp[i][2] - price[i])
        dp[i+1][4] = max(dp[i][4], dp[i][3] + price[i])
        由于无后效应，我们可以直接用四个变量代替。
        tips:几个点
        1. dp1, dp2, dp3, dp4 在初始化的时候分别应该对应什么。
        2. dp2，dp4应该放在dp1, dp3之前，因为卖只能在买之后。
        3. 想一下如果不遵守2的话会出问题吗？
    */
int maxProfit(vector<int>& prices) {
    size_t n = prices.size();
    if (n < 2) return 0;
    int dp1 = -prices[0], dp2 = 0, dp3 = INT_MIN, dp4 = 0;
    for (size_t i = 1; i < n; i++) {
        dp2 = max(dp2, dp1 + prices[i]);
        dp1 = max(dp1,  -prices[i]);
        if (i >= 3) {
            dp4 = max(dp4, dp3 + prices[i]);
        }
        if (i >= 2) {
            dp3 = max(dp3, dp2 - prices[i]);
        }
    }
    return max(max(dp1, dp2), max(dp3, dp4));
}