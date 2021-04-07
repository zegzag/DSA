#include "binary_tree.h"
#include <vector>
using namespace std;

/*这题关键在于：
    任意一条路径均可以被看作由某个节点为起点，从其左儿子和右儿子向下遍历的路径拼接得到。
    然后根据递归，求左儿子和右儿子深度和，然后求最大值。
  */
 
int diameterOfBinaryTree(TreeNode* root) {
    int ans = 1;
    dfs(root, ans);
    return ans-1;
}
int dfs(TreeNode* node, int& ans) {
    if (node == nullptr) return 0;
    int L = dfs(node->left, ans);
    int R = dfs(node->right, ans);
    ans = max(ans, L+R+1);
    return max(L, R) + 1;
}