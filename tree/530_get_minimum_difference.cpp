#include "binary_tree.h"
#include <math>
using namespace std;

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int pre_val = -1, result = INT_MAX;
        dfs(root, pre_val, result);
        return result;
    }
    void dfs(TreeNode* node, int& pre_val, int& result) {
        if (node == nullptr) return;
        dfs(node->left, pre_val, result);
        if (pre_val != -1) {
            result = min(result, abs(pre_val - node->val));
        }
        pre_val = node->val;
        dfs(node->right, pre_val, result);
    }
};