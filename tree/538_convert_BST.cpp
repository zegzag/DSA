#include "binary_tree.h"
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int pre_val = 0;
        dfs(root, pre_val);
        return root;
    }
    void dfs(TreeNode* node, int& pre_val) {
        if (node == nullptr) return;
        dfs(node->right, pre_val);
        node->val += pre_val;
        pre_val = node->val;
        dfs(node->left, pre_val);
        return;
    }
};