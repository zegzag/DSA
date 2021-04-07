#include <vector>
#include <limits.h>

using namespace std;
/* 这题的状态空间说想也好想，说不好想也不好想，关键是一下子不好理解题目的意思。
  * dp[k][j] = min(max(dp[k-1][x-1], dp[k][j-x])) + 1 (1<=x<=j)，结果为dp[K][N]
  * tips:
  * 1. 如何进行初始化？
  *  2. 边界定义，比如当x = 1的时候，dp[k-1][0]等于多少？
  *  Core：这题关键是用二分查找去求x
  *  二分查找和平常直接的也有些不太一样，是一个变种。
  */

int superEggDrop(int K, int N) {
    vector<vector<int>> dp(K+1, vector<int>(N+1, 0));
    for (int j= 1; j <= N; j++) {
        dp[1][j] = j;
    }

    for (int i = 1; i <= K; i++) {
        dp[i][1] = 1;
    }
    for (int k = 2; k <= K; k++) { 
         // 如果这里k从1开始就会出现错误dp[1][2] = min(max(dp[0][1], dp[1][0])) +1 ，0个鸡蛋一层楼，1个鸡蛋0层楼都是无意义的状态，转移后为1结果错误。
         //在定义状态转移时，一定要搞清楚初始条件和转移的结束条件，一处细节都不能遗漏。
        for (int j = 1; j <= N; j++) {
            int dp_s = INT_MAX;
            for (int x = 1; x <= j; x++) {
                int dp_ss = max(dp[k-1][x-1], dp[k][j-x]);
                dp_s = min(dp_ss, dp_s);
            }
            dp[k][j] = dp_s + 1;
        }
    }
    return dp[K][N];
}

//二分法的拓展运用，求两个单调函数最大值的最小值
//这里mid代表什么，以及while退出条件，真的特别难以搞清楚
int superEggDrop(int K, int N) {
    vector<vector<int>> dp(K+1, vector<int>(N+1, 0));
    for (int j= 1; j <= N; j++) {
        dp[1][j] = j;
    }

    for (int i = 1; i <= K; i++) {
        dp[i][1] = 1;
    }
    for (int k = 2; k <= K; k++) {
        for (int j = 1; j <= N; j++) {
            int right = j, left = 1, mid = (left + right) / 2;
            while( left <= mid -1) {
                if (dp[k-1][mid-1] >= dp[k][j-mid]) {
                    right = mid;
                } else {
                    left = mid;
                }
                mid = (left + right) /2;
            }
            int dp_s = min(dp[k-1][mid], dp[k][j-mid]);
            dp[k][j] = dp_s + 1;
        }
    }
    return dp[K][N];
}

int superEggDrop(int K, int N) {
    vector<vector<int>> dp(K+1, vector<int>(N+1, 0));
    for (int j= 1; j <= N; j++) {
        dp[1][j] = j;
    }

    for (int i = 1; i <= K; i++) {
        dp[i][1] = 1;
    }
    for (int k = 2; k <= K; k++) {
        for (int j = 1; j <= N; j++) {
            int right = j, left = 1, mid = left;
            while( left < right -1 ) {
                mid = (left + right) / 2;
                int val1 = dp[k-1][mid-1];
                int val2 = dp[k][j-mid];
                if (val1 > val2) {
                    right = mid;
                } else if (val1 < val2){
                    left = mid;
                } else {
                    break;
                }
            }
            int dp_s = max(dp[k-1][mid-1], dp[k][j-mid]); //这里是取max还是取min？为什么这里要取max ?
            dp[k][j] = dp_s + 1;
        }
    }
    return dp[K][N];
}