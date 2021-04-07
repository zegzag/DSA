#include<vector>
using namespace std;
/* dp[i][j] := A[0, i], B[0, j]ʱ�������׺�ĳ��ȡ����ﶨ��ʱ���Ͱ�A[i] == B[j] ���������ˡ�
  * dp[i+1][j+1] = dp[i][j] +1 if A[i+1] == B[j+1] else 0;
  * ��ʱ��������������״̬�ռ�̫�࣬
  * �����ڶ���ʱ��״̬��ֹ����һЩ��
  * ֻҪ�ܽ��������������ˡ�
*/

int findLength(vector<int>& A, vector<int>& B) {
    size_t na = A.size();
    size_t nb = B.size();
    vector<vector<int>> dp(na+1, vector<int>(nb+1, 0));
    int ans = 0;
    for (size_t i = 1; i <=na; i++) {
        for (size_t j = 1; j <=nb; j++){
            dp[i][j] = (A[i-1] == B[j-1]) ? dp[i-1][j-1] + 1 : 0;
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}