#include<vector>
using namespace std;
/*´ý¶¨
  */
int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.size() == 0)
        return 0;
    int rn = matrix.size();
    int ln = matrix[0].size();
    int area = 0;
    vector<vector<int>> dp(rn, vector<int>(ln, 0));
    for(int i = 0; i<rn; i++)
        for(int j = 0; j<ln; j++){
            if(j == 0)
                dp[i][j] = matrix[i][j]=='1'?1:0;
            else{
                dp[i][j] = matrix[i][j]=='1'?dp[i][j-1]+1:0;
            }
            int a = dp[i][j];
            for(int k = i; k>=0; k--){
                a = min(a,dp[k][j]);
                area = max(a*(i-k+1), area);
            }
        }
    return area;
}