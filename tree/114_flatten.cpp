#include <vector>
#include <stack>
#include "binary_tree.h"
using namespace std;

void flatten(TreeNode* root) {
    if (root == nullptr) return;
    TreeNode *head = new TreeNode(-1);
    head->right = root;
    TreeNode *last_node = head;
    stack<TreeNode*> S;
    S.emplace(head->right);
    while(!S.empty()) {
        auto rc = S.top();
        S.pop();
        last_node->right = rc;
        last_node = last_node->right;
        while(true) {
            if (last_node->left != nullptr) {
                if (last_node->right != nullptr) {
                    S.emplace(last_node->right);
                }
                last_node->right = last_node->left;
                last_node->left = nullptr;
            }
            if (last_node->right != nullptr) {
                last_node = last_node->right;
            } else {
                break;
            }
        }
    }
}