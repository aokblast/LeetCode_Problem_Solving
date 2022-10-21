//dp 
//Runtime 28
//Memory Usage 6

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int dp[target + 1];
        int pre[target + 1];
        
        memset(dp, 0, sizeof(dp));
        memset(pre, 0, sizeof(pre));
        
        const int MOD = 1e9 + 7;
        
        pre[0] = 1;
        
        while(n--) {
            memset(dp, 0, sizeof(dp));
            
            
            for(int i = 1; i <= k; ++i) {
                for(int j = target; j >= i; --j) {
                    dp[j] = (dp[j] + pre[j - i]) % MOD;
                }
            }
            memcpy(pre, dp, sizeof(dp));
        }
        
        
        
        return dp[target];
    }
};