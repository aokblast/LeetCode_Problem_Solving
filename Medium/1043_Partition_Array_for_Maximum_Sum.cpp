//dp
//Runtime 12
//Memory Usage 8.4

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        int dp[n + 1];
        
        memset(dp, 0, sizeof(dp));
        
        for(int i = 1; i <= n; ++i){
            int mx = 0;
            int mxv = 0;
            for(int j = i; j >= max(1, i - k + 1); --j){
                mx = max(arr[j - 1], mx);
                mxv = max(mxv, mx * (i - j + 1) + dp[j - 1]);
            }
            dp[i] = mxv;
        }
        
        return dp[n];
    }
};