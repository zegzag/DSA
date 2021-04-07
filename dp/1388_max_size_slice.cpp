#include <vector>
using namespace std;

/**待定**/
/* 1. 该问题<=> 在3n个数组中选取n个不相邻的数字，使其和最大。
  * 2. dp[i][j] := 在前i个数中选择了j个不相邻的数的最大和。
  * 2.1 j的遍历范围为0-n保证了最终取到n, i的遍历范围为0-3n为整个数组的遍历。
  * 2.2 为什么在打家劫舍II中可以一次遍历，而这里需要两次遍历?
  */
int calculate(const vector<int>& slices) {
    int n = slices.size();
    int choose = (n + 1) / 3;
    vector<vector<int>> dp(n + 1, vector<int>(choose + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= choose; ++j) {
            dp[i][j] = max(dp[i - 1][j], (i - 2 >= 0 ? dp[i - 2][j - 1] : 0) + slices[i - 1]);
        }
    }
    return dp[n][choose];
}

int maxSizeSlices(vector<int>& slices) {
    vector<int> v1(slices.begin() + 1, slices.end());
    vector<int> v2(slices.begin(), slices.end() - 1);
    int ans1 = calculate(v1);
    int ans2 = calculate(v2);
    return max(ans1, ans2);
}