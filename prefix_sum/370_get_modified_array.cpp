#include<vector>
using namespace std;
/*前缀和的逆向，查分应用*/
vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
    vector<int> ans(length, 0);
    int k = updates.size();
    for (int i = 0; i < k; i++) {
        int start = updates[i][0];
        int end = updates[i][1];
        int inc = updates[i][2];
        ans[start] += inc;
        if (end + 1 < length){
            ans[end+1] -= inc;
        }
    }
    for (int i =  1; i < length; i++) {
        ans[i] += ans[i-1];
    }
    return ans;
}