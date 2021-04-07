#include <vector>
using namespace std;

//这个特么太屌了
//快慢指针
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res = 0;
        for (int fast = 0; res != fast || fast == 0;){
            res = nums[res];
            fast = nums[nums[fast]];
        } //找到环中的某个位置
        for (int i = 0; res != i; i = nums[i]){
            res = nums[res];
        } //找到环的入口位置，环的入口处一定不是0，所以从0开始进行第二次遍历。
        //第二次遍历可以保证一定在环的入口处停下，想想怎么从数学上证明呢？
        return res;
    }

    //二分查找？
    int findDuplicate(vector<int>& nums) {
        int res = 0;
        for (int fast = 0; res != fast || fast == 0;){
            res = nums[res];
            fast = nums[nums[fast]];
        } //找到环中的某个位置
        for (int i = 0; res != i; i = nums[i]){
            res = nums[res];
        } //找到环的入口位置，环的入口处一定不是0，所以从0开始进行第二次遍历。
        //第二次遍历可以保证一定在环的入口处停下，想想怎么从数学上证明呢？
        return res;
    }
};