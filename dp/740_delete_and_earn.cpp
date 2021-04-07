#include<vector>
using namespace std;
/* 1. 这个问题的关键在于构建具有最优子结构的状态空间。
 *       如果状态空间不是跟遍历数组有关，那么跟什么有关可以做到有最优子结构从而进行递推？
 *       根据整数的大小由小到大遍历，删除k数字时的所获得最大点数时，一定在删除k-1或k-2时也获得了最大点数？
 *       如果能想到这儿，就不难构造数据结构，然后往打家劫舍方向上转了。
 * 2. 删除后可选择等于nums[i]-1 【或】nums[i] + 1的元素，
 *      但是顺序count数组时，只涉及到删除nums[i]-1，这两者等价吗？
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