#include<vector>
#include<map>
using namespace std;

//´íÎó
int oddEvenJumps(vector<int>& A) {
    int n = A.size();
    if (n == 0) return 0;
    vector<vector<bool>> dp(2, vector<bool>(n, false));
    dp[0][n-1] = true;
    dp[1][n-1] = true;
    map<int, int> idx;
    idx.emplace(A[n-1], n-1);
    int ans = 1;
    for (size_t i = n-1; i >= 0; i--)  {
        int v = A[i];
        if (idx.count(A[i])) {
            dp[0][i] = dp[1][idx[v]];
            dp[1][i] = dp[0][idx[v]];
        } else {
            const auto& low = idx.lower_bound(v);
            const auto& up = idx.lower_bound(-v);
            if (low != idx.end() && dp[0][low->second]) {
                dp[1][i] = true;
                ans++; 
            }
            if (up != idx.end() && up->first <0 && dp[1][up->second]){
                dp[0][i] = true;
            }
        }
        idx.emplace(v, i);
        idx.emplace(-v, i);
    }
    return ans;
}

//ÕýÈ·
int oddEvenJumps(vector<int>& A) {
    vector<vector<bool>> next(2, vector<bool>(A.size(), false));
    next[0].back() = true;
    next[1].back() = true;

    int ans = 1;
    map<int, int> mp;
    for (int i = A.size() - 1; i >= 0; i--) {
        auto it = mp.lower_bound(A[i]);
        if (it != mp.end() && next[0][it->second]) {
            next[1][i] = true;
            ans++;
        }
        it = mp.lower_bound(-A[i]);
        if (it != mp.end() && it->first <= 0 && next[1][it->second]) {
            next[0][i] = true;
        }

        mp[A[i]] = i;
        mp[-A[i]] = i;
    }

    return ans;
}

