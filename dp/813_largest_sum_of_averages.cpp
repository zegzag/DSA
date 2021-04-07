#include <vector>
using namespace std;

/* 1. dp[k][i]  := 在i位置时划分k次下的最大值。
  * 2. dp[k][i]  = max_j(dp[k-1][j] + avg(j+1, i)) for ( 0<= j < i);
  * 2.1 状态空间的理解关键是要搞清楚：
  *         用j来指代状态转移时的划分位置，用k保留切分多少次，
  *         然后用max的最优子空间性质把j, k统一到能表示的状态空间上。
  * 注意:
  *  1. 怎么起步？dp怎么初始化?
  *  2. dp[k][i]的空间复杂度能否优化？
  *  2.1 关于空间优化方面，不需要反着定义状态空间，只需要遍历i的时候反着遍历就行了。
  *          因为最终结果与i的遍历顺序无关(0维)，且i的结果与j的遍历顺序无关。
  *          所以只要保证遍历j的时候，k-1时候的状态能够找到就行了，那么即 i的遍历反着来就可以了，
  *          最内层的j遍历不管正着还是反着都可以。
  */
double largestSumOfAverages(vector<int>& A, int K) {
    int n = A.size();
    if (n == 0) return 0;
    vector<double> preSum(n, A[0]);
    for (size_t i = 1; i <n; i++) {
        preSum[i] = preSum[i-1] +A[i];
    }
    vector<vector<double>> dp(K+1, vector<double>(n, 0));
    for (size_t i = 0; i < n; i++) {
        dp[1][i] = preSum[i] / (i+1);
    }
    for (int k = 2; k <= K; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                double sub_curr = dp[k-1][j]+ (preSum[i] - preSum[j])/(i - j);
                dp[k][i] = max(sub_curr, dp[k][i]);
            };
        }
    }
    return dp[K][n-1];
}