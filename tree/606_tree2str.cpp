#include "./tree/tree.h"
#include<string>
#include<stack>
#include<iostream>
using namespace std;

string tree2str_1(TreeNode* t){
    if(t == nullptr)
        return "";
    string s;
    stack<TreeNode*> S1;
    stack<int> S2;
    int level = 0;
    S1.push(t);
    while(true){
        while(t){
            s += "(";
            s += to_string(t->val);
            if(t->right){
                S1.push(t->right);
                S2.push(level+1);
                if(!t->left)
                    s += "()";
            }           
            t = t->left;
            level++;
        }
        if(S1.empty() || S2.empty())
            break;
        t = S1.top();
        S1.pop();
        for(int i = S2.top(); i<level;i++){
            s +=")";
        }
        level = S2.top();
        S2.pop();
    }
    for(int i = 0; i < level -1;i++)
        s += ")";
    return s.substr(1);
}

string tree2str_2(TreeNode* t){
    string s;
    create_str(s, t);
    return s;
}

void create_str(string &s, TreeNode* t){
    if(t == nullptr)
        return;
    s+=to_string(t->val);
    if(t->left){
        s+="(";
        create_str(s, t->left);
        s+=")";
    }
    else if(t->right)
        s+="()";
    if(t->right){
        s+="(";
        create_str(s, t->right);
        s+=")";
    }
}

long TailRescuvie(long n, long a){
    if(n == 1)
        return a;
    return TailRescuvie(n-1, a*n);
}
