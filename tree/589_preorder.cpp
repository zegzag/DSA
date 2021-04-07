#include<vector>
#include<stack>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


vector<int> preOrder(Node* root) {
    vector<int> result;
    preorder_recurr(root, result);
    return result;
}
void preorder_recurr(Node* node, vector<int>& result){
    if (node == nullptr) return;
    result.emplace_back(node->val);
    for (auto& nd : node->children) {
        preorder_recurr(nd, result);
    }
}

vector<int> preOrder(Node* root) {
    vector<int> result;
    if (root == nullptr) return result;
    stack<Node*> S;
    S.emplace(root);
    while(!S.empty()) {
        auto node = S.top();
        S.pop();
        result.emplace_back(node->val);
        int n = node->children.size();
        for (int i = n-1; i>=0; i--) {
            auto nd = node->children[i];
            if (nd != nullptr)
                S.emplace(node->children[i]);
        }
    }
    return result;
}