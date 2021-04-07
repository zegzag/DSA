#include "binary_tree.h"
using namespace std;
/*如何递归地去思考问题，详见题解*/
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int left_level = countLevel(root->left);
        int right_level = countLevel(root->right);
        if (left_level == right_level) {
            return countNodes(root->right) + (1<<left_level);
        } else {
            return countNodes(root->left) + (1<<right_level);
        }
    }
    int countLevel(TreeNode* node) {
        if (node == nullptr) return 0;
        int level = 0;
        while(node) {
            level++;
            node = node->left;
        }
        return level;
    }
};