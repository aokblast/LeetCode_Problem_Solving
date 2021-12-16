//dp
//Runtime 4
//Memory Usage 7.2

class Solution {
public:
    long dp[51][51][51] = {{{0}}};
    long MOD = 1e9 + 7;   
    int findPaths(int m, int n, int maxMove, int sr, int sc) {
        for(int s = 1; s <= maxMove; ++s){
            for(int i = 0; i < m; ++i){
                for(int j = 0; j < n; ++j){
                    long long v1 = i == 0 ? 1 : dp[s - 1][i - 1][j];
                    long long v2 = i == m - 1 ? 1 : dp[s  - 1][i + 1][j];
                    long long v3 = j == 0 ? 1 : dp[s - 1][i][j - 1];
                    long long v4 = j == n - 1 ? 1 : dp[s - 1][i][j + 1];
                    dp[s][i][j] = (v1 + v2 + v3 + v4) % MOD;
                }
            }
        }
        return dp[maxMove][sr][sc];
        
    }
};