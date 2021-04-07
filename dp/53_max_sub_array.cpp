#include<vector>
using namespace std;
/**�������ͣ�
 * �������������뵽dp[i] := ��iΪ��β�������Ӵ����͡�
 * �ؼ���״̬ת�Ʒ��̡�
 * ��ĳЩ��������ǻ�����ǰ����Ӵ���������һ��������ô��ʲô����»������أ������״̬ת�Ʒ��̵Ĺؼ���
 * dp[i+1] = max(dp[i] + num[i+1], num[i+1]);
 * ˼���ǶȲ�ͬ���ͻ��в�ͬ��״̬ת�Ʒ��̣�
 * dp[i+1] = nums[i] + max(dp[i], 0) �����0��ָ���ǰ׺��Ϊ��������ô�����Ͳ���Ҫǰ׺������������һ����nums[i]����nums[i] + 0
 *  ע�������ÿ��λ��ʱ����ǰ��num[i]һ��Ҫ��Ϊ��β(dp[i]�Ķ���)��Ȼ���������Ӵ��ĺ͡�dp[i]�Ķ��弴Ϊ������Ŀռ䡣
 * Ȼ����������ʱ��ô��������ռ�ת�ƹ�����
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