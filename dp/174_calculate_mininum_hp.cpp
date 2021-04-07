#include<vector>
#include<limits.h>
using namespace std;
/*�������Ժ�Google���Ǹ������������½ǵ����Ͻ���ϵ��
  *���������ε���С·�������⡣״̬�ռ������˳������ؽ⿪���⡣
    *״̬�ռ�Ķ������̫����ȵ��������Ҫ�ˡ�
    */
int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int n = dungeon.size(), m = dungeon[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
    dp[n][m - 1] = dp[n - 1][m] = 1;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            int minn = min(dp[i + 1][j], dp[i][j + 1]);
            dp[i][j] = max(minn - dungeon[i][j], 1);
        }
    }
    return dp[0][0];
}