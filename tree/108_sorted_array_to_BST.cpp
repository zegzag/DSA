#include "binary_tree.h"
#include <vector>
using namespace std;

TreeNode* sortedArrayToBST(vector<int>& nums) {
    if(nums.empty()) return NULL;
    return subBST(nums, 0, nums.size()-1);
}
TreeNode* subBST(vector<int>& nums, int left, int right){
    if(left > right) return NULL;
    int mid = (right-left)/2+left;

    TreeNode* root = new TreeNode(nums[mid]);
    root->left = subBST(nums, left, mid-1);
    root->right = subBST(nums, mid+1, right);
    return root;
}