#include<vector>
#include<unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

/* 此题的关键在于两点;
  * 1. 克隆图的时候，因为时深拷贝，所以不能复制neighbors;
  * 2. 深拷贝时，每个node只有一个地址，所以遍历时多次访问
  *      不能new过个地址。
  */
 //深度优先遍历
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        auto& val = node->val;
        auto& neighbors = node->neighbors;
        if (visited.count(val)) {
            return visited[val];
        }
        Node* node_new = new Node(val);
        visited.emplace(val, node_new);
        for (auto& nb : neighbors) {
            node_new->neighbors.emplace_back(
                cloneGraph(nb)
            );
        }
        return node_new;
    }
private:
    unordered_map<int, Node*> visited;
};