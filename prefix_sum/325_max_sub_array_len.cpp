#include<vector>
#include<unordered_map>
using namespace std;
/*ǰ׺������ı��֣��ر�ע����ϵhashmap���key: value��valueֵʱ������
  *�Լ������䳤��ʱʱ i - hash.at(s-k) ���� i+1 - hash.at(s-k)
  */

int maxSubArrayLen(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0) return 0;
    unordered_map<int, int> hash;
    hash.emplace(0, 0);
    int s = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        s  += nums[i];
        if (!hash.count(s)) {
            hash.emplace(s, i+1);
        }
        if (hash.count(s - k)) {
            ans = max(ans, i+1 - hash.at(s-k));
        }
    }
    return ans;
}