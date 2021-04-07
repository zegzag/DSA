#include<vector>
#include<math.h>
using namespace std;
/**
 * 最大乘积连续子序列。
 * dp[i]  := 以i结尾的最大连续子序列的乘积。
 * dp[i] = max(dp[i-1]*num[i], num[i])
 * 跟求和不同的时，乘积前面的连续数组断了，后边还可以接起来(负负得正)。注意这里负，就想让它负得更狠。
 * 如何记录是否能接起来，新增维护一个变量
 * dp_max[i] = max(dp_max[i-1]*num[i],  dp_min[i-1]*num[i], num[i]);
 * dp_min[i] = min(dp_min[i-1]*num[i], dp_min[i-1]*num[i], num[i]);
 * */

int maxProduct(vector<int>& nums) {
    int maxF = nums[0], minF = nums[0], ans = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        int mx = maxF, mn = minF;
        maxF = max(mx * nums[i], max(nums[i], mn * nums[i]));
        minF = min(mn * nums[i], min(nums[i], mx * nums[i]));
        ans = max(maxF, ans);
    }
    return ans;
}