#include "binary_tree.h"

/* 思路很简单，检查is_left := 左子树是否含目标节点，
    is_right := 右子树是否含目标节点, is_curr = 当前节点是否含目标节点
    然后根据这三者之间的关系讨论返回和赋值情况。
    后续遍历
  */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* result = nullptr;
        dfs(root, p, q, result);
        return result;
    }

    bool dfs(TreeNode* node, const TreeNode* p, const TreeNode* q, TreeNode*& result) {
        if (result != nullptr)
            return false;
        if (node == nullptr) 
            return false;
        bool is_left = dfs(node->left, p, q, result);
        bool is_right = dfs(node->right, p, q, result);
        if (is_left && is_right) {
            result = node;
            return false;
        }
        if (is_left || is_right) {
            if (node == p || node == q) {
                result = node;
            } 
            return true;
        }
        if (node == p || node == q) {
            if (p == q) {
                result = node;
            }
            return true;
        }
        return false;
    }
};