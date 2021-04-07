#include<vector>
#include<queue>
using namespace std;

/*思路，由外层像内层进行层次遍历*/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n, vector<int>());
        vector<int> degree(n, 0);
        vector<int> ans;
        queue<int> que;
        for (auto& eg : edges) {
            graph[eg[0]].emplace_back(eg[1]);
            graph[eg[1]].emplace_back(eg[0]);
            ++degree[eg[0]];
            ++degree[eg[1]];
        }
        for (int i = 0; i < n; i++) {
            if (degree[i] <= 1) { // 注意这里时<=1 ，包含了只有一个节点的孤点的特殊情况。
                que.emplace(i);
            }
        }
        while(que.size() != n) {
            int level_size = que.size();
            n -= level_size; // 有效n的更新在while之前，因为层次遍历时，que的size已经变了。
            while(level_size > 0) {
                auto nd = que.front();
                que.pop();
                --level_size;
                for (auto& nxt : graph[nd]) {
                    --degree[nxt];
                    if (degree[nxt] == 1) {
                        que.emplace(nxt);
                    } 
                }
            }
        }
        while (!que.empty()) {
            ans.emplace_back(que.front());
            que.pop();
        }
        return ans;
    }
};