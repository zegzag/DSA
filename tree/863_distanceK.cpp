 #include <vector>
 #include "binary_tree.h"
 using namespace std;

 /* 双递归把爷整蒙了都*/
 /* 这题通过递归(subtree_add())记录到node的距离的node很好想。
   * 关键在于dfs()，dfs()通过定义返回值=当前节点距离node节点的距离
   * 来进而作为subtree_add()的输入。
   *  而两遍递归(dfs()一遍, subtree_add()一遍)，避免了一次递归下，漏过
   *  已经遍历的节点的问题(比如target位于node右子树中，而此时已经遍历完node的左子树)、
   */
  /* 这题双递归是一种解决方案，而记录父节点也是一种解决方案。
    * 记录父节点不一定要改变树的定义，通过额外的空间复杂度(其实改变树
    *  的定义增加的空间复杂度也是O(N))直接记录就行(map)，指向只是一种逻辑，
    *  并不一定非要时指针。
    */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        this->target = target;
        this->K = K;
        dfs(root);
        return ans;
    }
    // Return vertex distance from node to target if exists, else -1
    // Vertex distance: the number of vertices on the path from node to target
    int dfs(TreeNode* node) {
        if (node == nullptr)
            return -1;
        else if (node == target) {
            subtree_add(node, 0);
            return 1;
        } else {
            int L = dfs(node->left), R = dfs(node->right);
            if (L != -1) {
                if (L == K) ans.emplace_back(node->val);
                subtree_add(node->right, L + 1);
                return L + 1;
            } else if (R != -1) {
                if (R == K) ans.emplace_back(node->val);
                subtree_add(node->left, R + 1);
                return R + 1;
            } else {
                return -1;
            }
        }
    }
    // Add all nodes 'K - dist' from the node to answer.
    void subtree_add(TreeNode* node, int dist) {
        if (node == nullptr) return;
        if (dist == K) {
            ans.emplace_back(node->val);
        } else {
            subtree_add(node->left, dist + 1);
            subtree_add(node->right, dist + 1);
        }
    }
private:
    vector<int> ans;
    TreeNode* target;
    int K;
};