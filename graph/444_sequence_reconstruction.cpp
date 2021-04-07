#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
using namespace std;

/* �ؼ��㣺ÿ�������������е�Ԫ�ز��ܳ���1��
  * �ѵ㣺
  *     1. ����sequence��ͼ����Ҫ�����ظ�ǰ׺�Լ������ڵ�����⡣
  *     2. BFS�����������
  */
class Solution {
public:
    using G = unordered_map<int, unordered_set<int>>;
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        G graph;
        unordered_map<int, int> indegree;
        for (const auto& sq : seqs) {
            int n = sq.size();
            for (int i = n-1; i >=0; i--) { // i >= 0 ������ i>0 ����Ϊ�������һ�������㣬��ôi>0���޷���ͼ��
                auto& pre = sq[i];
                if (!indegree.count(pre)) {
                    indegree[pre] = 0;
                }
                if (i == 0) {
                    break;
                }
                auto& nxt = sq[i-1];
                if (indegree.count(nxt) && !graph[pre].count(nxt)) { // ���seq����ǰ׺�����⡣
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