#include<queue>
#include<vector>
#include<string>
#include<stack>
#include<unordered_map>
using namespace std;


/* 判断一个图是否为欧拉图
  * 此题的关键：
  * 1. 进行深度优先遍历时，每次遍历到当前节点即删除该边(保证只访问一次)。
  * 2. 先访问序小的节点
  * 3. 最后逆序输出结果
  */

 // 递归方法
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

//迭代方法