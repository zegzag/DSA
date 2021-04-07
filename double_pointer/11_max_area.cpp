#include <vector>
using namespace std;

// 思路看代码吧
// 这道题跟google的偏序矩阵那道题有点像，比较巧妙。
class Solution {
public:
    int maxArea(vector<int>& height) {
        int lp = 0,  ans = 0, cur_ans = 0;
        int rp = height.size()-1;
        while (rp > lp) {
            auto& lh = height[lp];
            auto& rh = height[rp];
            cur_ans = min(lh, rh) * (rp-lp);
            ans = max(ans, cur_ans);
            if (lh < rh) {
                ++lp;
            } else {
                --rp;
            }
        }
        return ans;
    }
};