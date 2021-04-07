#include<string>
#include<stack>
#include<deque>
#include<unordered_map>
#include<unordered_set>
using namespace std;

/*几点：
  * 1. 字典序最小说明了：从左到右遍历，如果当前元素小于前一个元素，那么就可以删掉前一个元素。
  *      即可以使用贪心算法。
  *  2. 删掉元素后在之后还可能出现相应的元素，这时候需要一个set来标记该元素是否出现过。
  *  3. 注意set在while循环中的位置，while内外的操作以及while的判断条件。
  */
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> count;
        for (auto& c: s) {
            if (count.count(c)) {
                ++count[c];
            } else {
                count[c]=1;
            }
        }
        deque<char> S;
        unordered_set<char> set;
        for (auto& c : s) {
            if (!set.count(c)) { 
                while(!S.empty() && c < S.back() && count[S.back()] > 0) {
                    set.erase(S.back());
                    S.pop_back();
                }
                set.emplace(c);
                S.push_back(c);
            } // if set 保证了进入栈的元素必定为1个
            --count[c]; // 所以如果已经在set里了，就可以直接跳过，计数--
        }
        string ans = "";
        while(!S.empty()) {
            ans += S.front();
            S.pop_front();
        }
        return ans;
    }
};