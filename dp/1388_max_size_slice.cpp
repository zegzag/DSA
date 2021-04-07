#include <vector>
using namespace std;

/**����**/
/* 1. ������<=> ��3n��������ѡȡn�������ڵ����֣�ʹ������
  * 2. dp[i][j] := ��ǰi������ѡ����j�������ڵ��������͡�
  * 2.1 j�ı�����ΧΪ0-n��֤������ȡ��n, i�ı�����ΧΪ0-3nΪ��������ı�����
  * 2.2 Ϊʲô�ڴ�ҽ���II�п���һ�α�������������Ҫ���α���?
  */
int calculate(const vector<int>& slices) {
    int n = slices.size();
    int choose = (n + 1) / 3;
    vector<vector<int>> dp(n + 1, vector<int>(choose + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= choose; ++j) {
            dp[i][j] = max(dp[i - 1][j], (i - 2 >= 0 ? dp[i - 2][j - 1] : 0) + slices[i - 1]);
        }
    }
    return dp[n][choose];
}

int maxSizeSlices(vector<int>& slices) {
    vector<int> v1(slices.begin() + 1, slices.end());
    vector<int> v2(slices.begin(), slices.end() - 1);
    int ans1 = calculate(v1);
    int ans2 = calculate(v2);
    return max(ans1, ans2);
}