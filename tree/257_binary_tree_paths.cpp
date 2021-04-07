#include <vector>
#include <string>
#include "binary_tree.h"
using namespace std;

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr)  return vec;
        string str = "";
        dfs(root, str);
        return vec;
    }
    void dfs(TreeNode* node, string str){
        str += "->"+ to_string(node->val);
        bool lc = node->left == nullptr;
        bool rc = node->right == nullptr;
        if (!lc) {
            dfs(node->left, str);
        } 
        if (!rc) {
            dfs(node->right , str);
        }
        if (lc && rc) {
            vec.emplace_back(str.substr(2));
            return;
        }
    }
private:
    vector<string> vec;
};