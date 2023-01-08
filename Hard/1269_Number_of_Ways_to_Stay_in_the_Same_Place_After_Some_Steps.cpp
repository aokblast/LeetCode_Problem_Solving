//dp
//Runtime 11
//Memory Usage 6

class Solution {
public:
    int numWays(int steps, int arrLen) {
        int lim = min(steps, arrLen);
        int dp[lim + 2], pre[lim + 2];

        const int MOD = 1e9 + 7;

        memset(dp, 0, sizeof(dp));
        memset(pre, 0, sizeof(dp));

        dp[0] = 1;

        for(int i = 0; i < steps; ++i) {
            memcpy(pre, dp, sizeof(pre));
            memset(dp, 0, sizeof(dp));
            
            dp[0] = (pre[1] + pre[0]) % MOD;
            
            if(lim >= 2)
            dp[lim - 1] = (pre[lim - 2] + pre[lim - 1]) % MOD;

            for(int j = 1; j < lim - 1; ++j)
                dp[j] = ((pre[j] + pre[j - 1]) % MOD + pre[j + 1]) % MOD;
        }

        return dp[0];

    }
};