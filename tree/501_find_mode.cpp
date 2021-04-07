#include<vector>
#include "binary_tree.h"
using namespace std;

/*���е�˼·666�����벻����T.T
  * ע������ʱpre, count, max_count, ans����ȫ�ֱ���
  */
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        TreeNode* pre = nullptr;
        int count = 1, max_count = 1;
        dfs(root, pre, count, max_count, ans);
        return ans;
    }
    void dfs(TreeNode* node , TreeNode*& pre, int& count, int& max_count, vector<int>& ans) {
        if (node == nullptr) return;
        dfs(node->left, pre, count, max_count, ans);
        if (pre == nullptr) {
            count = 1;
        } else if (pre->val == node->val) {
            count++;
        } else {
            count = 1;
        }
        pre = node;
        if (count == max_count) {
            ans.emplace_back(node->val);
        } 
        if (count > max_count) {
            max_count = count;
            ans.clear();
            ans.emplace_back(node->val);
        }
        dfs(node->right, pre, count, max_count, ans);
        return;
    }
};