#include "tree.h"

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if(t1==NULL)
        if(t2 == NULL)
            return NULL;
        else
            return t2;
    else 
        if(t2 == NULL)
            return t1;
        else{
            TreeNode* sumt = new TreeNode(t1->val+t2->val);
            sumt->left = mergeTrees(t1->left, t2->left);
            sumt->right = mergeTrees(t1->right, t2->right);
            return sumt;
        }        
}