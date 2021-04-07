#include "binary_tree.h"

/*pre_sum = pre_sum * 10 + node->val 比string <-> int相互转换要更好*/
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0, pre_sum = 0;
        dfs(root, pre_sum, ans);
        return ans;
    }
    void dfs(TreeNode* node,  int pre_sum, int& ans) {
        if (node == nullptr) return;
        if (node->left == nullptr &&
             node->right == nullptr) {
            ans += pre_sum*10 + node->val;
        }
        pre_sum = pre_sum*10 + node->val;
        dfs(node->left, pre_sum, ans);
        dfs(node->right, pre_sum,  ans);
    }
};