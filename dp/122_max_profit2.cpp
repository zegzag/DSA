#include<vector>
using namespace std;
/* dp[i][0] := ��i��δ���й�Ʊʱ�����档
    * dp[i][1] := ��i����й�Ʊʱ�����档
    * dp[i+1][0] = max(dp[i][0], dp[i][1] + price[i])
    * dp[i+1][1] = max(dp[i][1], dp[i][0] - price[i])
    *  tips:
    *      1. ע�����ﶯ̬�滮ת�Ʒ��̺�T121������
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