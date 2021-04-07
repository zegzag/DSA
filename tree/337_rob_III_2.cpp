#include "binary_tree.h"
#include <math>
using namespace std;

/*真的，只有你想不到的递归方式，真的6啊*/
class Solution {
public:
    int rob(TreeNode* root) {
        return dfs(root);
    }
    int dfs(TreeNode* node) {
        if (node == nullptr) return 0;
        int money = node->val;
        if (node->left) {
            money += rob(node->left->left) + rob(node->left->right);
        }
        if (node->right) {
            money += rob(node->right->left) + rob(node->right->right);
        }
        return max(money, rob(node->left)+rob(node->right));
    }
};

class Solution {
public:
    int rob(TreeNode* root) {
        return dfs(root);
    }
    int dfs(TreeNode* node) {
        if (node == nullptr) return 0;
        if (hash.count(node)) return hash.at(node);
        int money = node->val;
        if (node->left) {
            money += rob(node->left->left) + rob(node->left->right);
        }
        if (node->right) {
            money += rob(node->right->left) + rob(node->right->right);
        }
        int ans = max(money, rob(node->left)+rob(node->right));
        hash.emplace(node, ans);
        return ans;
    }
private:
    unordered_map<TreeNode*, int> hash;
};

class Solution {
public:
    int rob(TreeNode* root) {
        auto ans =  dfs(root);
        return max(ans[0], ans[1]);
    }
    int* dfs(TreeNode* node) {
        if (node == nullptr) return new int[2]();
        int* ans = new int[2]();
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        ans[0] = max(left[0], left[1]) + max(right[0], right[1]);
        ans[1] = left[0] + right[0] + node->val;
        return ans;
    }
};