#include "binary_tree.h"
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr) return root;
        auto new_root = root;
        int val = root->val;
        if (val < low) {
            root->left = nullptr;
            new_root = root->right;
            root = nullptr;
            return trimBST(new_root, low, high);
        } else if (val > high) {
            root->right = nullptr;
            new_root = root->left;
            root = nullptr;
            return trimBST(new_root, low, high);
        } else {
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
        }
        return new_root;
    }
};