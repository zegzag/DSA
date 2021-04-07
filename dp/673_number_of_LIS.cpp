#include<vector>
#include<iostream>

using namespace std;

/* 需注意两种情况
  * 1. 内层j循环的时候，dp[i] 是在不断变化的，所以dp[j] + 1和 dp[i] 的关系><=都有可能。
  * 2. 存在nums[j] >= nums[i] 的情况，这种情况直接跳过。count是不会更新的，所以可能会存在多个max_len下的记录。
  *      所以最后需要再次遍历一遍count求和。
  */
int numberOfLIS(vector<int>& nums) {
    size_t n = nums.size();
    if (n == 0) return 0;
    vector<int> dp(n, 1);
    vector<int> count(n, 1);
    int max_len = 0;
    int max_count = 0;
    for (size_t i = 0; i < n; ++i)  {
        for (size_t j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                if (dp[j]+1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                } else if (dp[j] + 1 == dp[i]) {
                    count[i] += count[j];
                }
            }
        }
        max_len = max(max_len, dp[i]);
    }
    for (size_t k = 0; k < n; k++){
        if (dp[k] == max_len) {
            max_count += count[k];
        }
    }
    return max_count;
}
