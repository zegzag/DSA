#include <vector>
#include<algorithm>
using namespace std;

/**300_最长上升子序列的进阶版。**/
/*step_1： 按照某一维sort
    step_2：根据另一维的排序情况求最长上升子序列长度。
    tips：
        注意排序相等情况下对另一维的排序
*/

int maxEnvelopes(vector<vector<int>>& envelopes) {
    size_t len = envelopes.size();
    if (len < 2) {
        return len;
    }
    sort(envelopes.begin(), envelopes.end(), 
                [&] (auto& a, auto&b) {
                    return (a[0] < b[0] ) || (a[0] == b[0] && a[1] > b[1]);
                });
    
    return numOfLTS(envelopes, 1);

}

int numOfLTS(vector<vector<int>>& envelopes_sort,  int idx) {
    size_t n = envelopes_sort.size();
    if (n == 0) return 0;
    vector<int> dp(n, 1);
    int num = 1;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < i; j++) {
            if (envelopes_sort[j][idx] < envelopes_sort[i][idx]){
                dp[i] = max(dp[i], dp[j] +1);
            }
        }
        num = max(num, dp[i]);
    }
    return num;
}