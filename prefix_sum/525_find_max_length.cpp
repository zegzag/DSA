#include<vector>
#include<unordered_map>
using namespace std;
/*为什么能想到用count 根据 1/0 加减来建索引。
  *直观的理解是根据(a1, b1)其中a, b分别表示截止到i时前缀的0和1数量。
  * 但是能够继续简化吗？
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