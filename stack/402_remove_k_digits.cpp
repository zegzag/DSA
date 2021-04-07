#include<deque>
#include<string>
using namespace std;

// 402
class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<char> dq;
        int raw_k = k;
        for (auto& c : num) {
            while(!dq.empty() && c < dq.back() && k > 0) {
                dq.pop_back();
                --k;
            }
            dq.emplace_back(c);
        }
        int res = num.size() - raw_k;
        string ans = "";
        bool first_zero = true;
        while(res > 0 && !dq.empty()) {
            if (first_zero && dq.front() != '0') {
                first_zero = false;
            }
            if (!first_zero) {
                ans += dq.front();
            }
            dq.pop_front();
            --res;
        }
        return ans.empty() ?  "0" : ans;
    }
};