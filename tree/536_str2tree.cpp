#include "tree.h"
#include<string>
#include<stack>
#include<stdio.h>
#include<iostream>
using namespace std;

TreeNode* str2tree(string s){
    if (s.length() == 0) 
        return nullptr;
    stack<TreeNode*> S;
    for ( int i = 0; i< s.length(); i++){
        if(s[i] ==')') S.pop();
        else if (s[i] >= '0' && s[i] <= '9' || s[i] == '-'){
            int start = i;
            while (i < s.length() -1 && s[i+1] >= '0' && s[i+1] <= '9')
                i++;
            TreeNode* root = new TreeNode(stoi(s.substr(start, i-start+1)));
            //获取父节点
            if (!S.empty()){
                TreeNode* parent = S.top();
                if (parent->left == nullptr){
                    parent->left == root; //Fuck, why this statement doesn't work;
                    cout<<parent->left<<endl;
                }
                else{
                  parent->right = root;
                  cout<<parent->right<<endl;
                }
            }

            S.push(root);
        }
    }
    if (S.empty()) return nullptr;
    return S.top();
}
void midTraversal(TreeNode* t){
    if(t == nullptr)
        return;
    midTraversal(t->left);
    cout<<t->val<<' ';
    midTraversal(t->right);
}

int main(){
    string s;
    int pause;
    cin>> s;
    TreeNode* t = str2tree(s);
    midTraversal(t);
    cin>> pause;
    return 0;
}