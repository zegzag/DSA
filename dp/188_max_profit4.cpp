#include<vector>
#include<limits.h>
using namespace std;
/* 从III很容易推广至IV，每天结束后，会处于以下k+1种状态中。
    * 1. dp[i][-1] := 未进行任何买卖
    * 2. dp[i][0] := 只进行了一次买
    * 3. dp[i][1] := 进行了一次买和卖
    * ...
    * 2k dp[i][2k-1] := 进行了k次买和卖
    * 则易得状态转移方程为:
        dp[i+1][u] = max(dp[i][u], dp[i][u-1] + prices[i+1]) if u%2 != 0 && u > 0
        dp[i+1][v] = max(dp[i][v], dp[i][v-1] - prices[i+1]) if v%2 == 0 && v > 0
        dp[i+1][k] = max(dp[i][k], -prices[i]) if k == 0
        这里u, v, k 是为了分别区分出奇，偶和0的情况
* 同时借鉴III的初始化方法，便不难写出代码了。
* tips:
* 1.注意dp的初始化值
* 2. 从II推广到IV， 和从III推广到IV可以导出什么不一样的状态空间。
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

/*看看这个状态空间时怎么定义的*/
public int maxProfit(int k, int[] prices) {
    /**
    当k大于等于数组长度一半时, 问题退化为贪心问题此时采用 买卖股票的最佳时机 II
    的贪心方法解决可以大幅提升时间性能, 对于其他的k, 可以采用 买卖股票的最佳时机 III
    的方法来解决, 在III中定义了两次买入和卖出时最大收益的变量, 在这里就是k租这样的
    变量, 即问题IV是对问题III的推广, t[i][0]和t[i][1]分别表示第i比交易买入和卖出时
    各自的最大收益
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
