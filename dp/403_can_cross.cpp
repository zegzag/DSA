#include <vector>
using namespace std;

/* dp[i][k] := 能否通过k步从上一位置跳到当前(i)石头上来
 */
bool canCross(vector<int>& stones) {
    int n = stones.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    dp[0][0] = true;
    for (int i = 1; i < n; i++) {
        if (stones[i] - stones[i-1] > i) return false;
        for (int j = i-1; j >= 0; j--) {
            int k = stones[i] - stones[j];
            if (k > j+1) break;
            dp[i][k] = dp[j][k] | dp[j][k-1] | dp[j][k+1];
        }
    }
    for (int x = 0;  x < n; x++) {
        if (dp[n-1][x]) {
            return true;
        }
    }
    return false;
}