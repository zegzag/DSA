#include<unordered_map>
#include<string>
using namespace std;

/* 关键一点：
  * 后指针发现重复的字母后，
  * 只需要移动前指针到重复的字母后即可，
  * 后指针可以保持不动。
  * 然后不断求最大值。
  */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        unordered_map<int,int> hash;
        int k = -1, res = 0;
        for (int i = 0; i<len; i++) {
            auto& c = s[i];
            if (hash.count(c) && hash[c] > k) {
                k = hash[c];
                hash[c] = i;
            } else {
                hash[c] = i;
                res = max(res, i-k);
            }
        }
        return res;
    }
};