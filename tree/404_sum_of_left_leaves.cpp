#include<vector>
#include"binary_tree.h"
using namespace std;

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        dfs(root, false, ans);
        return ans;
    }
    void dfs(TreeNode* node, bool is_left, int& ans) {
        if (node == nullptr) return;
        if (node->left == nullptr &&
             node->right == nullptr &&
             is_left) {
            ans += node->val;
            return;
        }
        dfs(node->left, true, ans);
        dfs(node->right, false, ans);
    }
};