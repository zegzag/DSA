#include "binary_tree.h"
#include <math>

class Solution {
public:
    int findTilt(TreeNode* root) {
        int slop = 0;
        int sum = dfs(root, slop);
        return slop;
    }
    int dfs(TreeNode* node,  int& slop) {
        if (node == nullptr) return 0;
        int L = dfs(node->left, slop);
        int R = dfs(node->right, slop);
        slop += abs(L-R);
        return L+R+node->val;
    }
};