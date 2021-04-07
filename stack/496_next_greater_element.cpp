#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> S;
        unordered_map<int, int> result;
        int len2 = nums2.size();
        for (int i = 0; i < len2; i++) {
            while(!S.empty() && nums2[i] > S.top()) {
                result[S.top()] = nums2[i];
                S.pop();
            }
            S.emplace(nums2[i]);
        }
        while(!S.empty()) {
            result[S.top()] = -1;
            S.pop();
        }
        vector<int> ans;
        for(auto& v : nums1) {
            ans.emplace_back(result[v]);
        }
        return ans;
    }
};