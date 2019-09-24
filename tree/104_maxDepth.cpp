#include "tree.h"
#include<cmath>
#include<algorithm>
using namespace std;

int maxDepth(TreeNode* root) {
    if(root == nullptr) return 0;
    int ldepth = maxDepth(root->left);
    int rdepth = maxDepth(root->right);
    return max(ldepth, rdepth)+1;
    
}