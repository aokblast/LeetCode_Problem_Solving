//dfs + memo
//Runtime 0
//Memory Usage 6.1

class Solution {
public:
    int tilingRectangle(int n, int m) {
        int dp[15][15];
        
        memset(dp, 0, sizeof(dp));
        
        function<int(int, int)> dfs = [&](int n, int m) {
            if(n > m)
                return dfs(m, n);
            
            if(n == 0)
                return 0;
            if(n == m)
                return 1;
            if(n == 1)
                return m;
            
            if(dp[n][m])
                return dp[n][m];
            
            int res = INT_MAX;
            
            for(int i = 1; i <= n; ++i) {
                res = min(res, 1 + dfs(n - i, m) + dfs(i, m - i));
                res = min(res, 1 + dfs(n, m - i) + dfs(n - i, i));
                
                for(int j = n - i + 1; j < n && j < m - i; ++j)
                    res = min(res, 2 + dfs(n - i, m - j) + dfs(i + j - n, m - i - j) + dfs(n - j, m - i));
            }
            
            return dp[n][m] = res;
        };
        
        
        return dfs(n, m);
    }
};