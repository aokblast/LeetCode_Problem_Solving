//dp
//Runtime 16
//Memory Usage 7.2
class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        long dp[n + 1][6], sum[n + 1];
        
        const long MOD = 1e9 + 7;
        
        memset(dp, 0, sizeof(dp));
        memset(sum, 0, sizeof(sum));
        
        sum[0] = 1;
        
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < 6; ++j) {
                for(int k = 1; k <= rollMax[j] && i - k >= 0; ++k) {
                    dp[i][j] = (dp[i][j] + sum[i - k] - dp[i - k][j]) % MOD;
                }
                sum[i] = (sum[i] + dp[i][j]) % MOD;
            }
        } 
        return (sum[n] + MOD) % MOD;
        
        
    }
};