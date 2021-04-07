#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
using namespace std;

/* 关键点：每次拓扑排序后队列的元素不能超过1个
  * 难点：
  *     1. 根据sequence建图，需要考虑重复前缀以及孤立节点的问题。
  *     2. BFS完后的情况讨论
  */
class Solution {
public:
    using G = unordered_map<int, unordered_set<int>>;
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        G graph;
        unordered_map<int, int> indegree;
        for (const auto& sq : seqs) {
            int n = sq.size();
            for (int i = n-1; i >=0; i--) { // i >= 0 而不是 i>0 是因为如果存在一个孤立点，那么i>0就无法建图。
                auto& pre = sq[i];
                if (!indegree.count(pre)) {
                    indegree[pre] = 0;
                }
                if (i == 0) {
                    break;
                }
                auto& nxt = sq[i-1];
                if (indegree.count(nxt) && !graph[pre].count(nxt)) { // 多个seq公共前缀的问题。
                    ++indegree[nxt];
                } else {
                    indegree[nxt] = 1;
                }
                graph[pre].emplace(nxt);
            }
        }
        queue<int> que;
        vector<int> ans;
        int n1 = indegree.size();
        for (auto& kv : indegree) {
            if (kv.second == 0) {
                que.emplace(kv.first);
            }
        }
        if (que.empty()) {
            return false;
        }
        while(!que.empty()) {
            if (que.size() != 1) {
                return false;
            }
            auto node = que.front();
            ans.emplace_back(node);
            que.pop();
            --n1;
            for (auto& nxt : graph[node]) {
                --indegree[nxt];
                if (indegree[nxt] == 0) {
                    que.emplace(nxt);
                }
            }
        }
        if (n1 != 0) {
            return false;
        }
        if (ans.size() != org.size()) {
            return false;
        }
        int n = ans.size();
        bool flag = true;
        for (int i = 0; i < n; i++) {
            flag = flag && (ans[n-1-i] == org[i]);
            if (!flag) {
                return false;
            }
        }
        return true;
    }
};