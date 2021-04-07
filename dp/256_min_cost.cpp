#include<vector>
using namespace std;

/* �����ô��Ҳ߯���˵��;
  * dp[i][0]= min(dp[i-1][1], dp[i-1][2]) + costs[i][0];
  * dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + costs[i][1];
  * dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + costs[i][2];
  * ����dp[i]��ʱ���������Ҫ����ǰi-1��color״̬ʱʲô���ģ�
  *  ��Ϊ���ƹ�ϵ�Ѿ���֤����ÿ������ʱ��ɫ����ͬ�����ֻҪ����Сֵ�����ˡ�
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

//ò�ƿ����Ż��ռ临�Ӷȣ�
