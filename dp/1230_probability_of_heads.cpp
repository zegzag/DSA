#include<vector>
using namespace std;

/* dp[i][j] := �����i��Ӳ��ʱ��j�泯�ϵĸ��ʡ�
  * ״̬ת�Ʒ���: dp[i][j] = dp[i-1][j-1] * prob[i] + prob[i-1][j] * (1- prob[i])
  * tips:
  *  1. ע���ʼ����ʱ����dp[n-1][target]? ����dp[n-1][n];
  *  2. ע��dp[i][0] ����ôת�����������ϵĴ���������Ϊ����
  *  3. dp ����ά�ȣ�dp[n][n] ? dp[n+1][n+1]? dp[n][n+1]? 
  *       ���������Ϊ��
  *             ǰһά��Ϊ����i�����������Գ���Ϊn��
  *             ��һά��Ϊ���ϵĸ�����Ϊ0-n�����Գ���Ϊn+1��
  *             ������forѭ����ʱ�򣬲��ܸ��巶Χ(for j in [0, j+1])
  */
 
double probabilityOfHeads(vector<double>& prob, int target) {
    size_t n = prob.size();
    vector<vector<double>>  dp(n, vector<double>(n+1, 0));
    dp[0][1] = prob[0];
    dp[0][0] = 1 - prob[0];
    for (size_t i = 1; i <n; i++) {
        for (size_t j =0; j <= i+1; j++) {
            if (j == 0) {
                dp[i][j] = dp[i-1][0]*(1-prob[i]);
            } else {
                dp[i][j] = dp[i-1][j] * (1 - prob[i]) + dp[i-1][j-1]*prob[i];
            }
        }
    }
    return dp[n-1][target];
}