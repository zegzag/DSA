#include "binary_tree.h"
#include<vector>
using namespace std;

vector<TreeNode*> genTreesUtil(int beg, int end){
    vector<TreeNode*> trees;
    if(end<beg){
        trees.push_back(NULL);
        return trees;
    }
    if(end == beg){
        auto t = new TreeNode(beg);
        trees.push_back(t);
        return trees;
    }
    for(int i = beg; i<= end; ++i){
        auto leftTrees = genTreesUtil(beg, i-1);
        auto rightTrees = genTreesUtil(i+1, end);
        
        for(auto& l: leftTrees)
            for(auto& r : rightTrees){
                auto t = new TreeNode(i);
                t->left = l;
                t->right = r;
                trees.push_back(t);
            }
    }
    return trees;
}

vector<TreeNode*> generateTrees(int n) {
    if(n==0){
        vector<TreeNode*> trees;
        return trees;
    }
    return genTreesUtil(1, n);
}