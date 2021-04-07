#include<vector>
using namespace std;
/**最大子序和：
 * 这个问题很容易想到dp[i] := 以i为结尾的连续子串最大和。
 * 关键是状态转移方程。
 * 在某些情况下我们会跳过前面的子串，重新起一个串，那么在什么情况下会跳过呢？这边是状态转移方程的关键。
 * dp[i+1] = max(dp[i] + num[i+1], num[i+1]);
 * 思考角度不同，就会有不同的状态转移方程：
 * dp[i+1] = nums[i] + max(dp[i], 0) 这里的0即指如果前缀和为负数，那么根本就不需要前缀串，可以新起一个串nums[i]，即nums[i] + 0
 *  注意遍历到每个位置时，当前的num[i]一定要作为结尾(dp[i]的定义)，然后算连续子串的和。dp[i]的定义即为子问题的空间。
 * 然后看最终问题时怎么由子问题空间转移过来。
 * */
int maxSubArray(vector<int>& nums) {
    int dp = 0, s = nums[0];
    for (size_t i  = 0; i<nums.size(); i++){
        size_t n = nums.size();
        if (n == 0) return 0;
        int dp = 0, s = nums[0];
        for (size_t i  = 0; i<n; i++){
            dp = max(dp + nums[i], nums[i]);
            s = max(s, dp);
        }
        return s;
    }
    return s;
}