#include <vector>
using namespace std;

//特么的，就地赋值比erase()强上一百倍
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return len;
        int j = 0;
        for (int i = 1; i < len; i++) {
            if (nums[i] != nums[j]) {
                nums[++j] = nums[i];
            }
        }
        return ++j;
};