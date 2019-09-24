#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int maxLoc(vector<int> nums, int low, int high){
    int mx = nums[low], mloc = low;
    while(++low<high){
        if(nums[low]>=mx)
            mloc = low;
    }
    return mloc;
}

TreeNode* subBinTree(vector<int> nums, int low, int high){
    if(low == high)
        return NULL;
    int mloc = maxLoc(nums, low, high);
    TreeNode* root = new TreeNode(nums[mloc]);
    root->left = subBinTree(nums, low, mloc);
    root->right = subBinTree(nums, mloc+1, high);
    return root;
}
TreeNode* constructMaximumBinaryTree(vector<int>& nums){
    return subBinTree(nums, 0, nums.size());
}