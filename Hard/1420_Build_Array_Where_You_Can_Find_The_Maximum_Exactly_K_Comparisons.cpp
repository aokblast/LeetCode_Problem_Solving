//dp
//Runtime 4
//Memory 5.8
class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        int dp[2][m + 1][k + 1];
        constexpr int MOD = 1e9 + 7;
        memset(dp, 0, sizeof(dp));

        for(int i = 1; i <= m; ++i)
            dp[0][i][1] = i;

        for(int i = 1; i < n; ++i) 
            for(int j = 1; j <= m; ++j) 
                for(int l = 1; l <= min({i + 1, j, k}); ++l)
                    dp[i & 1][j][l] = (dp[i & 1][j - 1][l] + ((long)(dp[(i - 1) & 1][j][l]) - dp[(i - 1) & 1][j - 1][l]) * j + dp[(i - 1) & 1][j - 1][l - 1]) % MOD;    
        
        return (dp[(n - 1) & 1][m][k] + MOD) % MOD;
    }
};