#include "binary_tree.h"

/* ˼·�ܼ򵥣����is_left := �������Ƿ�Ŀ��ڵ㣬
    is_right := �������Ƿ�Ŀ��ڵ�, is_curr = ��ǰ�ڵ��Ƿ�Ŀ��ڵ�
    Ȼ�����������֮��Ĺ�ϵ���۷��غ͸�ֵ�����
    ��������
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