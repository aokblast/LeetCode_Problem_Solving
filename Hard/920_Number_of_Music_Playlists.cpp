//
//Runtime 3
//Memory Usage  6
class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        long dp[goal + 1][n + 1];
        const int MOD = 1e9 + 7;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i = 1; i <= goal; ++i){
            for(int j = 1; j <= n; ++j){
                dp[i][j] = (dp[i - 1][j - 1] * (n - j + 1)) % MOD;
                dp[i][j] = (dp[i][j] + dp[i - 1][j] * max(j - k, 0)) % MOD;
                
            }
        }
        return dp[goal][n];      
    }
};