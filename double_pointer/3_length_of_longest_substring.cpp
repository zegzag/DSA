#include<unordered_map>
#include<string>
using namespace std;

/* �ؼ�һ�㣺
  * ��ָ�뷢���ظ�����ĸ��
  * ֻ��Ҫ�ƶ�ǰָ�뵽�ظ�����ĸ�󼴿ɣ�
  * ��ָ����Ա��ֲ�����
  * Ȼ�󲻶������ֵ��
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