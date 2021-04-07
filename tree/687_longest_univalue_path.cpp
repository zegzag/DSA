#include <vector>
#include <string>
#include "binary_tree.h"
using namespace std;

int longestUnivaluePath(TreeNode* root) {
    int ans = 0;
    maxPath(root, ans);
    return ans;
}
int maxPath(TreeNode* node, int& ans) {
    if (node == nullptr) return 0;
    int path = 0;
    int left_path = maxPath(node->left, ans);
    int right_path = maxPath(node->right, ans);
    auto& lc = node->left;
    auto& rc = node->right;
    bool extend_lc = lc != nullptr && lc->val == node->val;
    bool extend_rc = rc != nullptr && rc->val == node->val;
    if (extend_lc && extend_rc) {
        ans = max(ans, left_path + right_path +2);
    }
    if (extend_lc) {
        path = left_path+1;
    }
    if (extend_rc) {
        path = max(path, right_path + 1);
    }
    ans = max(ans, path);
    string a = "abc";
    string b = "a";
    auto c = a[0];
    

    return path;
}