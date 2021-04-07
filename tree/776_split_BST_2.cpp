#include <vector>
#include "binary_tree.h"
using namespace std;

/*��ô����ô����صݹ鰡*/
/* ���ȣ��ݹ鶼����vector��
     ��Σ��ݹ�ʱvectro���Ҷ�Ӧ������������ϵ����Ӧ
     ��󣬵ݹ鷵��ǰ���¸��ڵ�
     �������Ҳ̫�����ˣ�ܳ
  */
class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        if (root == nullptr) {
            return vector<TreeNode*>(2, nullptr);
        } else if (root->val <= V) {
            auto bns = splitBST(root->right, V);
            root->right = bns[0];
            bns[0] = root;
            return bns;
        } else {
            auto bns = splitBST(root->left, V);
            root->left = bns[1];
            bns[1] = root;
            return bns;
        }
    }
};