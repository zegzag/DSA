#include<vector>
#include<limits.h>
using namespace std;
/* ��III�������ƹ���IV��ÿ������󣬻ᴦ������k+1��״̬�С�
    * 1. dp[i][-1] := δ�����κ�����
    * 2. dp[i][0] := ֻ������һ����
    * 3. dp[i][1] := ������һ�������
    * ...
    * 2k dp[i][2k-1] := ������k�������
    * ���׵�״̬ת�Ʒ���Ϊ:
        dp[i+1][u] = max(dp[i][u], dp[i][u-1] + prices[i+1]) if u%2 != 0 && u > 0
        dp[i+1][v] = max(dp[i][v], dp[i][v-1] - prices[i+1]) if v%2 == 0 && v > 0
        dp[i+1][k] = max(dp[i][k], -prices[i]) if k == 0
        ����u, v, k ��Ϊ�˷ֱ����ֳ��棬ż��0�����
* ͬʱ���III�ĳ�ʼ���������㲻��д�������ˡ�
* tips:
* 1.ע��dp�ĳ�ʼ��ֵ
* 2. ��II�ƹ㵽IV�� �ʹ�III�ƹ㵽IV���Ե���ʲô��һ����״̬�ռ䡣
*/
int maxProfit(int k, vector<int>& prices) {
    if (k == 0) return 0;
    size_t n = prices.size();
    if (n < 2) return 0;
    vector<vector<int>> dp(n, vector<int>(2*k, INT_MIN));
    dp[0][0] = -prices[0];
    int result = 0;
    for(size_t i = 1; i < n; i++) {
        for (size_t j = 0; j < 2*k; j++) {
            if (j > i) {
                break;
            }
            if (j % 2 == 1) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + prices[i]);
            } else if (j > 0){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] - prices[i]);
            } else {
                dp[i][j] = max(dp[i-1][j], -prices[i]);
            }
            result = max(result, dp[i][j]);
        }
    }
    return result;
}

/*�������״̬�ռ�ʱ��ô�����*/
public int maxProfit(int k, int[] prices) {
    /**
    ��k���ڵ������鳤��һ��ʱ, �����˻�Ϊ̰�������ʱ���� ������Ʊ�����ʱ�� II
    ��̰�ķ���������Դ������ʱ������, ����������k, ���Բ��� ������Ʊ�����ʱ�� III
    �ķ��������, ��III�ж������������������ʱ�������ı���, ���������k��������
    ����, ������IV�Ƕ�����III���ƹ�, t[i][0]��t[i][1]�ֱ��ʾ��i�Ƚ������������ʱ
    ���Ե��������
    **/
    if(k < 1) return 0;
    if(k >= prices.length/2) return greedy(prices);
    int[][] t = new int[k][2];
    for(int i = 0; i < k; ++i)
        t[i][0] = Integer.MIN_VALUE;
    for(int p : prices) {
        t[0][0] = Math.max(t[0][0], -p);
        t[0][1] = Math.max(t[0][1], t[0][0] + p);
        for(int i = 1; i < k; ++i) {
            t[i][0] = Math.max(t[i][0], t[i-1][1] - p);
            t[i][1] = Math.max(t[i][1], t[i][0] + p);
        }
    }
    return t[k-1][1];
}

private int greedy(int[] prices) {
    int max = 0;
    for(int i = 1; i < prices.length; ++i) {
        if(prices[i] > prices[i-1])
            max += prices[i] - prices[i-1];
    }
    return max;
}
