#include "tree.h"
#include<vector>
#include<queue>
#include<stack>
using namespace std;
vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> L;
    stack<vector<int>> LL;
    vector<int> level;
    if(root == nullptr) return L;
    int s = 1, ns = 0;
    queue<TreeNode*> Q;
    Q.push(root);
    while(!Q.empty()){
        TreeNode* node = Q.front();
        Q.pop();
        
        if(s > 0){
            level.push_back(node->val);
            s--;
        }
        if(s == 0){
            LL.push(level);
            level.clear();
        }
        
        if(node->left){
            Q.push(node->left);
            ns++;
        }
        if(node->right){
            Q.push(node->right);
            ns++;
        }
        
        if(s==0){
            s = ns;
            ns = 0;
        }
    }
    while(!LL.empty()){
        L.push_back(LL.top());
        LL.pop();
    }
            
    return L;
}