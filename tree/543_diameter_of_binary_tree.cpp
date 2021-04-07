#include "binary_tree.h"
#include <vector>
using namespace std;

/*����ؼ����ڣ�
    ����һ��·�������Ա�������ĳ���ڵ�Ϊ��㣬��������Ӻ��Ҷ������±�����·��ƴ�ӵõ���
    Ȼ����ݵݹ飬������Ӻ��Ҷ�����Ⱥͣ�Ȼ�������ֵ��
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