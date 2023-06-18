//
//Runtime 356
//Memory Usage 113.7

class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
                ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n = q.size();
        long long dp[n + 1], res = 0;
        memset(dp, 0, sizeof(dp));
        
        for(int i = 0; i < n; ++i) {
            int ni = min(i + q[i][1] + 1, n);
            dp[i + 1] = max(dp[i + 1], dp[i]);
            res = max(res, dp[ni] = max(dp[ni], dp[i] + q[i][0]));
        }

        return res;
    }
};