#include "binary_tree.h"

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        bool flag = false;
        dfs(root, k, flag);
        return flag;
    }
    void dfs(TreeNode* node, int k, bool& flag) {
        if (node == nullptr) return;
        if (flag == true) return;
        dfs(node->left, k, flag);
        if (comp.count(k - node->val)) {
            flag = true;
            return;
        }
        comp.emplace(node->val);
        dfs(node->right, k, flag);
    }
private:
    unordered_set<int> comp;
};