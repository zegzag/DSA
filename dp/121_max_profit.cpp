#include<vector>
using namespace std;
/* dp[i][0] := ��i�����ʱδ���й�Ʊ������
    * dp[i][1] := ��i�����ʱ���й�Ʊ������
    * dp[i+1][0]  = max(dp[i][0], dp[i][1] + price[i+1])
    * dp[i+1][1]  = max(dp[i][1], -price[i+1])
    * tips:
    *  1.����dp[i][1]�Ķ��������Щ���ܹ��ˣ�����Ҫɱ����ţ�������ӡ�
    *  2. ע��dp[i+1][1]�ĵ��ƹ�ʽ��Ϊʲô�Ͱ�"ֻ����һ��"����Ϣ��������ȥ�ˡ�
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