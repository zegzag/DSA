#include<vector>
#include<unordered_map>
using namespace std;
/*Ϊʲô���뵽��count ���� 1/0 �Ӽ�����������
  *ֱ�۵�����Ǹ���(a1, b1)����a, b�ֱ��ʾ��ֹ��iʱǰ׺��0��1������
  * �����ܹ���������
  */
int findMaxLength(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> hash;
    hash.emplace(0, 0);
    int count = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        count += (nums[i] == 1) ? 1: -1;
        if (hash.count(count)) {
            ans = max(ans, i+1 - hash.at(count));
        } else {
            hash.emplace(count, i+1);
        }
    }
    return ans;
}