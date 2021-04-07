#include <vector>
#include <algorithm>
using namespace std;

//发现双指针的提都有些共性
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int start = 1, end = len -1;
        int sum = nums[0] + nums[start] + nums[end];
        int ans = sum;
        for (int i = 0; i < len; i++) {
            start = i+1;
            end = len - 1;
            while(start < end) {
                sum = nums[i] + nums[start] + nums[end];
                if (abs(target - sum) < abs(target - ans)) {
                    ans = sum;
                }
                if (sum == target) {
                    return target;
                }
                if (sum > target) {
                    --end;
                } else {
                    ++start;
                }
            }
        }
        return ans;
    }
};