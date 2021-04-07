#include<queue>
#include<vector>
#include<string>
#include<stack>
#include<unordered_map>
using namespace std;


/* �ж�һ��ͼ�Ƿ�Ϊŷ��ͼ
  * ����Ĺؼ���
  * 1. ����������ȱ���ʱ��ÿ�α�������ǰ�ڵ㼴ɾ���ñ�(��ֻ֤����һ��)��
  * 2. �ȷ�����С�Ľڵ�
  * 3. �������������
  */

 // �ݹ鷽��
class Solution {
public:
    using adj = priority_queue<string, vector<string>, greater<string>>;
    using graph = unordered_map<string, adj>;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        graph G;
        for (auto& edge : tickets) {
                G[edge[0]].emplace(edge[1]);
        }
        stack<string> result;
        vector<string> ans;
        dfs("JFK", G, result);
        while(!result.empty()) {
            ans.emplace_back(result.top());
            result.pop();
        }
        return ans;
    }

    void dfs(string node, graph& G, stack<string>& result) {
        auto& node_adjs= G[node];
        while(!node_adjs.empty()) {
            auto nxt = node_adjs.top();
            node_adjs.pop();
            dfs(nxt, G, result);
        }
        result.push(node);
        return;
    }
};

//��������