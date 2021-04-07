#include<cstdio>
#include<vector>
using namespace std;
/*
递归这玩意，真的是巧妙又难解啊！
*/
struct TreeNode
{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

vector<TreeNode*> genTreesUtil(int beg, int end) {
    vector<TreeNode*> trees;
    if (end < beg){
        trees.push_back(NULL);
        return trees;
    } 
    if (end == beg){
        auto t=new TreeNode(beg);
        trees.push_back(t);
        return trees;
    }
    for (int i = beg; i <= end; ++i) {

        auto leftTrees = genTreesUtil(beg, i - 1);
        auto rightTrees = genTreesUtil(i + 1, end);

        for (auto& l : leftTrees)
            for (auto& r : rightTrees) {
                auto t = new TreeNode(i);
                t->left = l;
                t->right = r;

                trees.push_back(t);
            }
    }

    return trees;
}

vector<TreeNode*> generateTrees(int n) {
    if (n == 0){
        vector<TreeNode*> trees;
        return trees;
    }
    return genTreesUtil(1, n);
}

int main(){
    int n;
    scanf("%d",&n);
    vector<TreeNode*> trees;
    trees = generateTrees(n);
    return 0;
}