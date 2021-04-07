#include<vector>
#include<unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> hash;
    hash.emplace(0, 1);
    int s = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        s += nums[i];
        if (hash.count(s - k)) {
            ans += hash.at(s-k);
        }
        if (!hash.count(s)) {
            hash.emplace(s, 1);
        } else {
            hash[s]++;
        }
    }
    return ans;
}