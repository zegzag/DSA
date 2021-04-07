#include "binary_tree.h"
#include <vector>
using namespace std;

/* dfs() sum参数可以用引用，也可以用非引用*/
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        int sum = 0;
        dfs(root, path, ans, sum, targetSum);
        return ans;
    }
    void dfs(TreeNode* node, 
                      vector<int>& path, 
                      vector<vector<int>>& ans,
                      int sum,
                      const int& targetSum) {
        if (node == nullptr) return;
        sum += node->val;
        path.emplace_back(node->val);
        if (node->left == nullptr &&
             node->right == nullptr && 
             sum == targetSum) {
            ans.emplace_back(path);
        }
        dfs(node->left, path, ans, sum, targetSum);
        dfs(node->right, path, ans, sum, targetSum);
        path.pop_back();
        //sum -= node->val;
        return;
    }
};