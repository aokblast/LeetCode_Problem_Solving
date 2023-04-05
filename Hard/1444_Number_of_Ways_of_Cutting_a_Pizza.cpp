//
//Runtime 13
//Memory Usage 7.5

class Solution {
public:
    int ways(vector<string>& pizza, int K) {
        int n = pizza.size(), m = pizza[0].size();

        int dp[n][m][K], ps[n + 1][m + 1];

        constexpr int MOD = 1e9 + 7;
        memset(ps, 0, sizeof(ps));

        for(int i = 1; i <= n; ++i) 
            for(int j = 1; j <= m; ++j) 
                ps[i][j] = ps[i][j - 1] + ps[i - 1][j] - ps[i - 1][j - 1] + (pizza[i - 1][j - 1] == 'A');
            
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                dp[i][j][0] = (ps[n][m] + ps[i][j] - ps[n][j] - ps[i][m]) > 0;

        for(int i = n - 1; i >= 0; --i)
            for(int j = m - 1; j >= 0; --j)  
                for(int k = 1; k < K; ++k)  {
                    int ans = 0;

                    for(int x = i; x < n - 1; ++x)
                        if((ps[x + 1][m] + ps[i][j] - ps[x + 1][j] - ps[i][m]) > 0)
                            ans = (ans + dp[x + 1][j][k - 1]) % MOD;

                    for(int y = j; y < m - 1; ++y)
                        if((ps[n][y + 1] + ps[i][j] - ps[n][j] - ps[i][y + 1]) > 0)
                            ans = (ans + dp[i][y + 1][k - 1]) % MOD;

                    dp[i][j][k] = ans;
                } 

        
        return dp[0][0][K - 1];
    }
};