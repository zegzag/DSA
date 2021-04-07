 #include <vector>
 #include "binary_tree.h"
 using namespace std;

 /* ˫�ݹ��ү�����˶�*/
 /* ����ͨ���ݹ�(subtree_add())��¼��node�ľ����node�ܺ��롣
   * �ؼ�����dfs()��dfs()ͨ�����巵��ֵ=��ǰ�ڵ����node�ڵ�ľ���
   * ��������Ϊsubtree_add()�����롣
   *  ������ݹ�(dfs()һ��, subtree_add()һ��)��������һ�εݹ��£�©��
   *  �Ѿ������Ľڵ������(����targetλ��node�������У�����ʱ�Ѿ�������node��������)��
   */
  /* ����˫�ݹ���һ�ֽ������������¼���ڵ�Ҳ��һ�ֽ��������
    * ��¼���ڵ㲻һ��Ҫ�ı����Ķ��壬ͨ������Ŀռ临�Ӷ�(��ʵ�ı���
    *  �Ķ������ӵĿռ临�Ӷ�Ҳ��O(N))ֱ�Ӽ�¼����(map)��ָ��ֻ��һ���߼���
    *  ����һ����Ҫʱָ�롣
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