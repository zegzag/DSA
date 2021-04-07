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

/* ����Ĺؼ���������;
  * 1. ��¡ͼ��ʱ����Ϊʱ��������Բ��ܸ���neighbors;
  * 2. ���ʱ��ÿ��nodeֻ��һ����ַ�����Ա���ʱ��η���
  *      ����new������ַ��
  */
 //������ȱ���
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