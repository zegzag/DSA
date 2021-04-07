#include<vector>
#include<iostream>

using namespace std;

/* ��ע���������
  * 1. �ڲ�jѭ����ʱ��dp[i] ���ڲ��ϱ仯�ģ�����dp[j] + 1�� dp[i] �Ĺ�ϵ><=���п��ܡ�
  * 2. ����nums[j] >= nums[i] ��������������ֱ��������count�ǲ�����µģ����Կ��ܻ���ڶ��max_len�µļ�¼��
  *      ���������Ҫ�ٴα���һ��count��͡�
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
