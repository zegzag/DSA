#include<vector>
#include<unordered_map>
using namespace std;
/*为了k==0单独写那么几行代码对于强迫症来说真得不爽
  */
bool checkSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    if (k == 0) {
        int len = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0){
                len++;
            } else {
                len=0;
            }
            if (len>=2) return true;
        }
        return false;
    }
    unordered_map<int, int> hash;
    int s = 0;
    hash.emplace(0, 0);
    for (int i = 0; i < n; i++) {
        s += nums[i];
        if (s%k == 0 && i > 1) {
            return true;
        }
        if (hash.count(s%k) && (i+1 - hash.at(s%k))>=2) {
            return true;
        } else {
            hash.emplace(s%k, i+1);
        }
    }
    return false;
}