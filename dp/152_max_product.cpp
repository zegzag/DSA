#include<vector>
#include<math.h>
using namespace std;
/**
 * ���˻����������С�
 * dp[i]  := ��i��β��������������еĳ˻���
 * dp[i] = max(dp[i-1]*num[i], num[i])
 * ����Ͳ�ͬ��ʱ���˻�ǰ�������������ˣ���߻����Խ�����(��������)��ע�����︺�������������ø��ݡ�
 * ��μ�¼�Ƿ��ܽ�����������ά��һ������
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