#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
    
    

 //Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 }; 
    
TreeNode* invertTree(TreeNode* root) {
    if(root == NULL)
        return NULL;
    swap(root->left, root->right);
    return root;
    
}
void swap(TreeNode* &t1, TreeNode* &t2){
    if(t1 == NULL && t2 == NULL)
        return;
    TreeNode *tmp = new TreeNode(t1->val);
    tmp = t1;
    t1 = t2;
    t2 = tmp;
    if(t1!=NULL)
        swap(t1->left, t1->right);
    if(t2!=NULL)
        swap(t2->left, t2->right);
}

int main(){
    TreeNode* tmp;

}