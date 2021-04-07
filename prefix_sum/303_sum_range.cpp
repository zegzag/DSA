#include<vector>
using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        S.resize(n+1);
        for (int i = 1; i <= n; i++) {
            S[i] = S[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        return S[j+1] - S[i];
    }
private:
    vector<int> S;
};