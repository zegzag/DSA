#include <vector>
using namespace  std;
/* dp[i] := 当走到i时的最大金额数。那么dp[i]等于多少呢？
 * 在dp[i]时候有两种由前面的转移状态。
 * 如果dp[i-1]窃取，那么dp[i]就不能窃取, 则dp[i] = dp[i-1];
 * 如果dp[i-1]不窃取, 那么dp[i] 【必定】窃取，则dp[i] = dp[i-2] + nums[i]
 * 注意这里【必定】表明了最优子结构
 * 综上dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
 * tips:
 * 1. 这里不要收到最长上升子序列和最大连续子序列和的影响。dp[i]的位置不一定非要进行窃取,
 *      dp[i]只定义到达i位置时的金额，"该状态"由前两个位置的状态转移而来。
 * 2. 针对 i == 2的时候，为了保持一致，可假设在-1的位置由个金额为0的用户被窃取了，
 *      其思想有些类似头指针。
 */
int rob(vector<int>& nums) {
    size_t n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    int dp_pp = 0;
    int dp_p = nums[0];
    int dp = 0;
    for (size_t i = 1; i < n; i++) {
        dp = max(dp_pp + nums[i], dp_p);
        dp_pp = dp_p;
        dp_p = dp;
    }
    return max(dp_p, dp);
}