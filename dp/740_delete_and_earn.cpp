#include<vector>
using namespace std;
/* 1. �������Ĺؼ����ڹ������������ӽṹ��״̬�ռ䡣
 *       ���״̬�ռ䲻�Ǹ����������йأ���ô��ʲô�йؿ��������������ӽṹ�Ӷ����е��ƣ�
 *       ���������Ĵ�С��С���������ɾ��k����ʱ�������������ʱ��һ����ɾ��k-1��k-2ʱҲ�������������
 *       ������뵽������Ͳ��ѹ������ݽṹ��Ȼ������ҽ��᷽����ת�ˡ�
 * 2. ɾ�����ѡ�����nums[i]-1 ����nums[i] + 1��Ԫ�أ�
 *      ����˳��count����ʱ��ֻ�漰��ɾ��nums[i]-1�������ߵȼ���
 */
int deleteAndEarn(vector<int>& nums) {
    size_t n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    int max_num = nums[0];
    for (auto& num : nums){
        max_num = max(max_num, num);
    }
    vector<int> count(max_num+1, 0);
    for (auto& num : nums) {
        count[num] += 1;
    }
    int dp_pp = 0, dp_p = 0, dp = count[1];
    for (size_t i = 1; i <=max_num; i++) {
        int tmp = dp_pp + i * count[i];
        dp =std:: max(dp_p, tmp);
        dp_pp  = dp_p;
        dp_p = dp;
    }
    return dp;
}