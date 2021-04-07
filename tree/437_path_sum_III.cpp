#include <unordered_map>
#include "binary_tree.h"
using namespace std;

/*树，前缀和*/
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> hash;
        hash.emplace(0, 1);  //关键这一步和线性前缀和不一样，想想为什么。
        int pre_sum = 0;
        int ans = 0;
        dfs(root, hash, pre_sum, ans, sum);
        return ans;
    }
    void dfs(TreeNode* node, 
                      unordered_map<int, int>& hash, 
                      int pre_sum,
                      int& ans,
                      const int& sum) {
        if (node == nullptr) return;
        pre_sum += node->val;
        if (hash.count(pre_sum - sum)) {
                ans += hash.at(pre_sum - sum);
        } //这一步判断出现在了emplace操作之前，Line:10
        if (hash.count(pre_sum)) {
            hash[pre_sum]++;
        } else {
            hash[pre_sum] = 1;
        }
        dfs(node->left, hash, pre_sum, ans, sum);
        dfs(node->right, hash, pre_sum, ans, sum);
        hash[pre_sum]--;
        return;
    }
};