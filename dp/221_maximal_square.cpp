#include<vector>
using namespace std;
/*dp[i][j] := ��[i][j]Ϊ���½ǵ������εı߳�
    dp[i+1][j+1] = min(dp[i+1][j], dp[i][j+1], dp[i][j]) + 1;
    ������Ƽ򵥵�ת�Ʒ��̣���ʵ�ȼ��Էǳ������롣
    */
int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size();
    if (m == 0)  return 0;
    int n = matrix[0].size();
    if (n == 0) return 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    vector<vector<int>> s2(m, vector<int>(n, 0));
    int side = 0;
    for (int i = 0; i < m; i++) {
        dp[i][0] = matrix[i][0] - 48;
        side = max(side, dp[i][0]);
    }
    for (int j = 0; j < n; j++) {
        dp[0][j] = matrix[0][j] - 48;
        side = max(side, dp[0][j]);
    }
    for (int i = 1; i < m ; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == '1') {
                dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
            }
            side = max(side, dp[i][j]);
        }
    }
    return side*side;
}