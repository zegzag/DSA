#include <vector>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
    // using graph = unordered_map<int, unordered_set<int>>;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        unordered_map<int, vector<int>> G;
        vector<int> ans;
        queue<int> Q;
        for (auto& edge : prerequisites) {
            G[edge[1]].emplace_back(edge[0]);
            ++indegree[edge[0]];
        }
        for (int i =0; i < numCourses; i++) {
            if (indegree[i]  == 0) {
                Q.push(i);
            }
        }
        while(!Q.empty()) {
            auto node = Q.front();
            Q.pop();
            ans.emplace_back(node);
            --numCourses;
            for(auto& nxt : G[node]) {
                --indegree[nxt];
                if (indegree[nxt] == 0) {
                    Q.push(nxt);
                }
            }
        }
        if (numCourses == 0) {
            return ans;
        } else {
            return vector<int>();
        }
    }
};