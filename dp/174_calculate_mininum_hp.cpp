#include<vector>
#include<limits.h>
using namespace std;
/*这道题可以和Google的那个有序矩阵从左下角到右上角联系。
  *包括三角形的最小路径和问题。状态空间迭代的顺序巧妙地解开问题。
    *状态空间的定义真得太他妈比得巧妙而重要了。
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