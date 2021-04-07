#include <vector>
#include <limits.h>

using namespace std;
/* �����״̬�ռ�˵��Ҳ���룬˵������Ҳ�����룬�ؼ���һ���Ӳ��������Ŀ����˼��
  * dp[k][j] = min(max(dp[k-1][x-1], dp[k][j-x])) + 1 (1<=x<=j)�����Ϊdp[K][N]
  * tips:
  * 1. ��ν��г�ʼ����
  *  2. �߽綨�壬���統x = 1��ʱ��dp[k-1][0]���ڶ��٣�
  *  Core������ؼ����ö��ֲ���ȥ��x
  *  ���ֲ��Һ�ƽ��ֱ�ӵ�Ҳ��Щ��̫һ������һ�����֡�
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
         // �������k��1��ʼ�ͻ���ִ���dp[1][2] = min(max(dp[0][1], dp[1][0])) +1 ��0������һ��¥��1������0��¥�����������״̬��ת�ƺ�Ϊ1�������
         //�ڶ���״̬ת��ʱ��һ��Ҫ�������ʼ������ת�ƵĽ���������һ��ϸ�ڶ�������©��
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

//���ַ�����չ���ã������������������ֵ����Сֵ
//����mid����ʲô���Լ�while�˳�����������ر����Ը����
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
            int dp_s = max(dp[k-1][mid-1], dp[k][j-mid]); //������ȡmax����ȡmin��Ϊʲô����Ҫȡmax ?
            dp[k][j] = dp_s + 1;
        }
    }
    return dp[K][N];
}