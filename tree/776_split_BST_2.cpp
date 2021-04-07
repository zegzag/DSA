#include <vector>
#include "binary_tree.h"
using namespace std;

/*怎么能这么巧妙地递归啊*/
/* 首先，递归都返回vector，
     其次，递归时vectro左右对应的左右子树关系都对应
     最后，递归返回前更新根节点
     这尼玛的也太巧妙了，艹
  */
class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        if (root == nullptr) {
            return vector<TreeNode*>(2, nullptr);
        } else if (root->val <= V) {
            auto bns = splitBST(root->right, V);
            root->right = bns[0];
            bns[0] = root;
            return bns;
        } else {
            auto bns = splitBST(root->left, V);
            root->left = bns[1];
            bns[1] = root;
            return bns;
        }
    }
};