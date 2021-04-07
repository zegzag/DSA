#include <vector>
using namespace  std;
/* dp[i] := ���ߵ�iʱ�������������ôdp[i]���ڶ����أ�
 * ��dp[i]ʱ����������ǰ���ת��״̬��
 * ���dp[i-1]��ȡ����ôdp[i]�Ͳ�����ȡ, ��dp[i] = dp[i-1];
 * ���dp[i-1]����ȡ, ��ôdp[i] ���ض�����ȡ����dp[i] = dp[i-2] + nums[i]
 * ע������ض��������������ӽṹ
 * ����dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
 * tips:
 * 1. ���ﲻҪ�յ�����������к�������������к͵�Ӱ�졣dp[i]��λ�ò�һ����Ҫ������ȡ,
 *      dp[i]ֻ���嵽��iλ��ʱ�Ľ�"��״̬"��ǰ����λ�õ�״̬ת�ƶ�����
 * 2. ��� i == 2��ʱ��Ϊ�˱���һ�£��ɼ�����-1��λ���ɸ����Ϊ0���û�����ȡ�ˣ�
 *      ��˼����Щ����ͷָ�롣
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