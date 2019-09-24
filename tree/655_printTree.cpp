#include "tree.h"
#include<vector>
#include<string>
#include<cmath>
using namespace std;


vector<vector<string>> printTree(TreeNode* root) {
    int height = getDepth(root);
    int width = pow(2, height) - 1;
    vector<vector<string>> V(height, vector<string>(width, ""));
    
    writeTree(V, root, 0, 0, width-1);
    
    return V;
}

int getDepth(TreeNode* root){
    if(root == NULL)
        return 0;
    return max(getDepth(root->left), getDepth(root->right))+1;
}

void writeTree(vector<vector<string>> &V, TreeNode* root, int level, int lc, int rc){
    if(rc < lc || root == NULL)
        return;
    int mid = lc + (rc-lc)/2;
    V[level][mid] = to_string(root->val);
    writeTree(V, root->left, ++level, lc, mid);
    writeTree(V, root->right, ++level, mid+1, rc);
}