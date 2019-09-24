#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

TreeNode* subBST(ListNode *head, ListNode *tail){
    
    ListNode *mid=head, *fast = head;
    if(head == NULL || head==tail)
        return NULL;
    else    
        while(fast->next!=tail&&fast->next->next!=tail){
            mid = mid->next;
            fast = fast->next->next;
        }
    TreeNode* root = new TreeNode(mid->val);
    root->left = subBST(head, mid);
    root->right = subBST(mid->next, tail);
    return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    return subBST(head, NULL);
}

void midTraverse(TreeNode* root){
    if(root == NULL)
        return;
    midTraverse(root->left);
    printf("%d ",root->val);
    midTraverse(root->right);
}



int main(){
    int v;
    ListNode* H = new ListNode(-1);
    while(cin>>v){
        ListNode* p = new ListNode(v);
        p->next = H->next;
        H->next = p;
    }
    TreeNode* root = sortedListToBST(H->next);
    midTraverse(root);
    scanf("%d",&v);
    return 0;
}

