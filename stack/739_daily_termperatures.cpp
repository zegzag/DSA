#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if (T.empty()) return vector<int>();
        stack<int> s;
        vector<int> ans(T.size(), 0);
        s.emplace(0);
        for(size_t i = 1; i < T.size(); i++) {
            while(!s.empty()) {
                auto& idx = s.top();
                if (T[i] > T[idx]) {
                    ans[idx] = i - idx;
                    s.pop();
                } else {
                    break;
                }
            }
            s.emplace(i);
        }
        while(!s.empty()) {
            auto& idx = s.top();
            ans[idx] = 0; 
            s.pop();
        }
        return ans;
    }
};