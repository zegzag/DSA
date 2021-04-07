#include<vector>
using namespace std;
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return;
        int n = matrix[0].size();
        S.resize(m+1);
        for (auto& s : S) {
            s.resize(n+1);
        }
        for (int i = 1; i <=m; i++) {
            for (int j = 1; j <=n; j++) {
                S[i][j] = S[i][j-1] + S[i-1][j] - S[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        return;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return S[row2+1][col2+1] - S[row2+1][col1] - S[row1][col2+1] + S[row1][col1];
    }
private:
    vector<vector<int>> S;
};