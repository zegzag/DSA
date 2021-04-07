#include <vector>
#include <queue>
using namespace std;

// 广度优先搜索
/* 拓扑排序问题*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        for (auto& pre : prerequisites) {
            ++indegree[pre[0]];
        }
        vector<vector<int>> graph(numCourses, vector<int>());
        for (auto& pre : prerequisites) {
            graph[pre[1]].emplace_back(pre[0]);
        }
        queue<int> que;
        for (size_t i = 0; i<indegree.size(); i++) {
            if (indegree[i] == 0) {
                que.emplace(i);
            }
        }
        while(!que.empty()) {
            int course = que.front();
            que.pop();
            --numCourses;
            for (auto& nxt_course : graph[course]) {
                --indegree[nxt_course];
                if (indegree[nxt_course] == 0) {
                    que.emplace(nxt_course);
                }
            }
        }
        return numCourses == 0;
    }
};

// 深度优先搜索
/* 这里关键的一点就是在遍历完所有的邻接节点后，即递归回溯时，
  * 将当前的节点状态置-1
  */
 /* 检查图中是否有环*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> flags(numCourses, 0);
        vector<vector<int>> graph(numCourses, vector<int>());
        for (size_t i = 0; i < prerequisites.size(); i++) {
            auto& edge = prerequisites[i];
            graph[edge[1]].emplace_back(edge[0]);
        }
        bool no_circle = true;
        for (int node = 0; node < numCourses; node++) {
            no_circle = no_circle && dfs(node, flags, graph);
        }
        return no_circle;
   }
   bool dfs(int node, vector<int>& flags, const vector<vector<int>>& graph) {
        if (flags[node] == 1) return false;
        if (flags[node] == -1) return true;
        flags[node] = 1;
        bool no_circle = true;
        for (auto nxt : graph[node]) {
            no_circle = no_circle && dfs(nxt, flags, graph);
        }
        if (no_circle) {
            flags[node] = -1;
            return true;
        } else {
            return false;
        }
    }
};
