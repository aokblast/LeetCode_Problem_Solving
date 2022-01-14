//
//Runtime 23
//Memory 10.4
class Solution {
public:
    int dp[1001][1001] = {{0}};
    int kInversePairs(int n, int m) {
        int mod = 1e9 + 7;
        dp[0][0] = 1;
        for(int i = 1; i <= n; ++i){
            dp[i][0] = 1;
            for(int j = 1; j <= m; ++j){
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
                if(j - i >= 0) dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + mod) % mod;
            }
        }
        return dp[n][m];
        
    }
};