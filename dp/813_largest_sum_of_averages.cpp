#include <vector>
using namespace std;

/* 1. dp[k][i]  := ��iλ��ʱ����k���µ����ֵ��
  * 2. dp[k][i]  = max_j(dp[k-1][j] + avg(j+1, i)) for ( 0<= j < i);
  * 2.1 ״̬�ռ�����ؼ���Ҫ�������
  *         ��j��ָ��״̬ת��ʱ�Ļ���λ�ã���k�����зֶ��ٴΣ�
  *         Ȼ����max�������ӿռ����ʰ�j, kͳһ���ܱ�ʾ��״̬�ռ��ϡ�
  * ע��:
  *  1. ��ô�𲽣�dp��ô��ʼ��?
  *  2. dp[k][i]�Ŀռ临�Ӷ��ܷ��Ż���
  *  2.1 ���ڿռ��Ż����棬����Ҫ���Ŷ���״̬�ռ䣬ֻ��Ҫ����i��ʱ���ű��������ˡ�
  *          ��Ϊ���ս����i�ı���˳���޹�(0ά)����i�Ľ����j�ı���˳���޹ء�
  *          ����ֻҪ��֤����j��ʱ��k-1ʱ���״̬�ܹ��ҵ������ˣ���ô�� i�ı����������Ϳ����ˣ�
  *          ���ڲ��j�����������Ż��Ƿ��Ŷ����ԡ�
  */
double largestSumOfAverages(vector<int>& A, int K) {
    int n = A.size();
    if (n == 0) return 0;
    vector<double> preSum(n, A[0]);
    for (size_t i = 1; i <n; i++) {
        preSum[i] = preSum[i-1] +A[i];
    }
    vector<vector<double>> dp(K+1, vector<double>(n, 0));
    for (size_t i = 0; i < n; i++) {
        dp[1][i] = preSum[i] / (i+1);
    }
    for (int k = 2; k <= K; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                double sub_curr = dp[k-1][j]+ (preSum[i] - preSum[j])/(i - j);
                dp[k][i] = max(sub_curr, dp[k][i]);
            };
        }
    }
    return dp[K][n-1];
}