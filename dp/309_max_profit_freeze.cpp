#include<vector>
#include<limits.h>
using namespace std;
/* dp[i][0] := 第i天时无股票-不操作时的收益
    * dp[i][1] := 第i天时无股票-买入股票后的收益
    * dp[i][2] := 第i天时有股票-不操作时的收益
    * dp[i][3] := 第i天时有股票-卖出股票后的收益
    * 状态转移方程：
        dp[i][0] = max(dp[i-1][0], dp[i-1][3])
        dp[i][1] = dp[i-1][0] - prices[i]
        dp[i][2] = max(dp[i-1][2], dp[i-1][1])
        dp[i][3] = max(dp[i-1][2] + prices[i], dp[i-1][1] + prices[i])
    */
int maxProfit(vector<int>& prices) {
    size_t n = prices.size();
    if (n < 2) return 0;
    int dp0 = 0, dp1 = -prices[0];
    int dp2 = INT_MIN, dp3 = 0;
    for (size_t i = 1; i < n; i++) {
        int tmp = dp0;  // 他妈的，一定要搞清楚四个状态的执行顺序以及会不会被覆盖。
        dp0 = max(dp0, dp3);
        dp2 = max(dp2, dp1);
        dp3 = max(dp2 + prices[i], dp1 + prices[i]);
        dp1 = tmp - prices[i];
    }
    return max(dp3, dp0);
}

//看看这个情况下的状态转移方程时怎么定义的？
int maxProfit2(vector<int> &prices){
    int len = prices.size();
    if(len<2)
        return 0;

    int dp_i_0 = 0, dp_pre_0 = 0, dp_i_1 = INT_MIN;
    for(int i = 0; i<len; i++){
        int tmp = dp_i_0;
        dp_i_0 = max(dp_i_0, dp_i_1+prices[i]);
        dp_i_1 = max(dp_i_1, dp_pre_0 - prices[i]);
        dp_pre_0 = tmp;
    }
    return dp_i_0;
}