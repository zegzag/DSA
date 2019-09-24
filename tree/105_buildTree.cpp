#include "tree.h"
#include<vector>
#include<iostream>
using namespace std;

TreeNode* subTree(vector<int> &preorder, 
                  vector<int> &inorder,
                  int &loc,
                  int left,
                  int right){
    if(right < left)
        return nullptr;
    ++loc;
    int root_val = preorder[loc];
    TreeNode* root = new TreeNode(root_val);
    int mid = left;
    while(mid <= right && inorder[mid] != preorder[loc])
         mid++;
    root->left = subTree(preorder, inorder, loc, left, mid-1);
    root->right = subTree(preorder, inorder, loc, mid+1, right);
    return root;
}

TreeNode* buildTree(vector<int> &preorder, vector<int> inorder){
    int loc = -1;
    return subTree(preorder, inorder, loc, 0, preorder.size()-1);

}

void preTraverse(TreeNode* root){
    if(root == NULL)
        return;
    printf("%d ", root->val);
    preTraverse(root->left);
    preTraverse(root->right);
}

void inTraverse(TreeNode* root){
    if(root = NULL)
        return;
    inTraverse(root->left);
    printf("%d ", root->val);
    inTraverse(root->right);
}

int main(){
    int pre, in, len;
    vector<int> preorder, inorder;
    scanf("%d", &len);
    cout<<"please cin preorder value"<<endl;
    for(int i = 0; i < len; i++){
        scanf("%d", &pre);
        preorder.push_back(pre);
    }
    cout<<"please cin inorder value"<<endl;
    for(int i = 0; i < len; i++){
        scanf("%d", &in);
        inorder.push_back(in);
    }
    TreeNode* root = buildTree(preorder,inorder);
    preTraverse(root);
    inTraverse(root);
}