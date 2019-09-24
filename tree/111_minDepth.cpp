#include "tree.h"
#include<algorithm>
using namespace std;
int minDepth(TreeNode* root) {
    if(!root)
        return 0;
    int l_depth = minDepth(root->left);
    int r_depth = minDepth(root->right);
    if(l_depth == 0)
        return r_depth + 1;
    if(r_depth == 0)
        return l_depth + 1;
    return min(l_depth, r_depth) + 1;
}