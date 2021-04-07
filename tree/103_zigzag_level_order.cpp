#include <vector>
#include<queue>
#include "binary_tree.h"
using namespace std;

/*我的解答*/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> level_ans;
        if (root == nullptr) return ans;
        queue<TreeNode*> Q1;
        queue<TreeNode*> Q2;
        int curr_left_num = 1;
        int next_level_num = 0;
        int level = 0;
        Q1.emplace(root);
        Q2.emplace(root);
        while(!Q1.empty()){
            auto node1 = Q1.front();
            auto node2 = Q2.front();
            Q1.pop();
            Q2.pop();
            curr_left_num--;
            int val = level % 2 == 0 ? node1->val : node2->val;
            level_ans.emplace_back(val);
            if (node1->left) {
                Q1.emplace(node1->left);
                next_level_num++;
            }
            if (node1->right) {
                Q1.emplace(node1->right);
                next_level_num++;
            }
            if (node2->right) {
                Q2.emplace(node2->right);
            }
            if (node2->left) {
                Q2.emplace(node2->left);
            }
            if (curr_left_num == 0) {
                ans.emplace_back(level_ans);
                curr_left_num = next_level_num;
                next_level_num = 0;
                level_ans.clear();
                level++;
            }
        }
        return ans;
    }
};

/*大佬的解答*/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode *> q;
        if (root) q.push(root);

        bool lr = true;
        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size, 0);
            while (size--) {
                root = q.front(); q.pop();
                level[lr ? level.size() - size - 1 : size] = root->val;
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            res.push_back(move(level));
            lr = !lr;
        }
        return res;
    }
};