#include <vector>
#include<string>
#include<queue>
#include<limits.h>
#include "binary_tree.h"
using namespace std;
/*这道题更加深了你对递归的理解
  *如何从一个序列建树
  */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        preorder(root, s);
        return s;
    }
    void preorder(TreeNode* node, string& s) {
        if (node == nullptr) return;
        s += to_string(node->val) + ",";
        preorder(node->left, s);
        preorder(node->right, s);
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string sval = "";
        queue<int> Q;
        for(int i =  0; i < data.size(); ++i) {
            if (data[i] == ',') {
                int val = atoi(sval.c_str());
                Q.emplace(val);
                sval = "";
                continue;
            }
           sval += data[i];
        }
        return helper(INT_MIN, INT_MAX, Q);
    }
    TreeNode* helper(int lower, int upper, queue<int>& q) {
        if (q.empty()) return nullptr;
        int val = q.front();
        if (val < lower || val > upper) {
            return nullptr;
        }
        q.pop();
        TreeNode* node = new TreeNode(val);
        node->left = helper(lower, val, q);
        node->right = helper(val, upper, q);
        return node; 
    }
};