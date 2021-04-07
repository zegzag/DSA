#include<vector>
#include<limits.h>
using namespace std;

/* ÿ������󣬻ᴦ������״̬���е�һ�֡�
    * 0: δ�����κβ���
    * 1: ������һ�������
    * 2: ������һ��������Ĳ���
    * 3: ������һ��������Ĳ������ֽ�����һ���������
    * 4: ��������������ˡ�
    * ���������Ƕ���״̬ת�Ʒ���dp[i][k] := ��i��ʱ����״̬kʱ���������
    * ת�ƹ�ʽ��
    * dp[i+1][0] = dp[i][0] = 0
        dp[i+1][1] = max(dp[i][1], dp[i][0] - price[i])
        dp[i+1][2] = max(dp[i][2], dp[i][1] + price[i])
        dp[i+1][3] = max(dp[i][3], dp[i][2] - price[i])
        dp[i+1][4] = max(dp[i][4], dp[i][3] + price[i])
        �����޺�ЧӦ�����ǿ���ֱ�����ĸ��������档
        tips:������
        1. dp1, dp2, dp3, dp4 �ڳ�ʼ����ʱ��ֱ�Ӧ�ö�Ӧʲô��
        2. dp2��dp4Ӧ�÷���dp1, dp3֮ǰ����Ϊ��ֻ������֮��
        3. ��һ�����������2�Ļ����������
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