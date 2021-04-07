#include <vector>
#include <queue>
#include "binary_tree.h"
using namespace std;

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if (root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int level_size = size;
            double level_val = 0;
            while(size > 0) {
                auto node = q.front();
                q.pop();
                level_val += node->val;
                if (node->left) {
                    q.emplace(node->left);
                }
                if (node->right){
                    q.emplace(node->right);
                }
                size--;
            }
            ans.emplace_back(level_val/level_size);
        }
        return ans;
    }
};