#include<vector>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    size_t n = nums.size();
    vector<int> dp(n, 0);
    int len =  0;
    for (size_t i = 0; i < n; i++) {
        dp[i] = 1;
        for (size_t j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        len = max(len, dp[i]);
    }
    return len;
}