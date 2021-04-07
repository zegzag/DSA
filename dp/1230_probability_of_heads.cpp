#include<vector>
using namespace std;

/* dp[i][j] := 到达第i个硬币时有j面朝上的概率。
  * 状态转移方程: dp[i][j] = dp[i-1][j-1] * prob[i] + prob[i-1][j] * (1- prob[i])
  * tips:
  *  1. 注意初始化的时候是dp[n-1][target]? 还是dp[n-1][n];
  *  2. 注意dp[i][0] 该怎么转化过来，向上的次数不可能为负。
  *  3. dp 的两维度，dp[n][n] ? dp[n+1][n+1]? dp[n][n+1]? 
  *       比如下面的为：
  *             前一维度为数组i的索引，所以长度为n。
  *             后一维度为向上的个数，为0-n，所以长度为n+1。
  *             这样在for循环的时候，才能搞清范围(for j in [0, j+1])
  */
 
double probabilityOfHeads(vector<double>& prob, int target) {
    size_t n = prob.size();
    vector<vector<double>>  dp(n, vector<double>(n+1, 0));
    dp[0][1] = prob[0];
    dp[0][0] = 1 - prob[0];
    for (size_t i = 1; i <n; i++) {
        for (size_t j =0; j <= i+1; j++) {
            if (j == 0) {
                dp[i][j] = dp[i-1][0]*(1-prob[i]);
            } else {
                dp[i][j] = dp[i-1][j] * (1 - prob[i]) + dp[i-1][j-1]*prob[i];
            }
        }
    }
    return dp[n-1][target];
}