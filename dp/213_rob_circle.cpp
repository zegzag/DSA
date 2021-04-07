#include<vector>
using namespace std;
/* 环形情况很容易想到分为1. 第0个位置不偷 or 2. 第0个位置偷
 * 其实做两个区分也是涉及到如果时环形情况，递推怎么启动问题，即怎么初始化(自底向上的底怎么构建)
  * 问题关键在于这两种情况区分后，对应到代码上应该怎么写。
  *  区分1：直接将dp_p(即nums[0])置为0即可，然后从i = 1开始遍历，遍历至n-1(即最后一个元素)
  *  区分2：这里需要注意两点：
  *  2.1: 如果nums[0]开始偷，我们可以直接从 i = 2的位置开始遍历。
  *  2.2: 第0个位置偷意味着最后一个位置不偷，只能遍历到n-2。
  *  2.3: 第0个位置开始偷初始状态怎么确定，即dp[0] = nums[0](在0时偷), dp[1] = nums[0] + 0(在0时偷，在1时不偷，其总和还是nums[0])
  *  2.4: 还没开始遍历时, dp的初始值是多少？在1.情况下我们可以直接设成0，但时在2.的情况下，可能存在还没开始就结束的情况，即不遍历
  *           只盗窃1的情形。那么这时候dp = 0是错误的。为了把初始化和遍历统一起来，我们把dp的初始值设置为我们行为定义的开始状态，即
  *            区分1: dp = nums[1], 区分2: dp = nums[0];
  */
int robCircle(vector<int>& nums) {
    size_t n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    int dp_pp = 0, dp_p = 0, dp = nums[1];
    for (size_t i = 1; i < n; i++) {
        dp = max(dp_p, dp_pp + nums[i]);
        dp_pp = dp_p;
        dp_p = dp;
    }
    int s1 = dp;
    dp_pp = nums[0];
    dp_p = nums[0];
    dp = nums[0];
    for (size_t i = 2; i < n-1; i++) {
        dp = max(dp_p, dp_pp + nums[i]);
        dp_pp = dp_p;
        dp_p = dp;
    }
    int s2 = dp;
    return max(s1, s2);
}