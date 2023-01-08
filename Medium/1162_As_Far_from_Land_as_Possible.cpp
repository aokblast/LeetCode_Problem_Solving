//dp
//Runtime 49
//Memory Usage 16.7

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), res = 0, dp[n][n];
        memset(dp, 0, sizeof(dp));
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1) 
                    continue;
                dp[i][j] = 1e3;
                if(i - 1 >= 0)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                if(j - 1 >= 0)
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
        }
        
        
        for(int i = n - 1; i >= 0; --i) {
            for(int j = n - 1; j >= 0; --j) {
                if(grid[i][j] == 1)
                    continue;
                if(i + 1 < n)
                    dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                if(j + 1 < n)
                    dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
                res = max(res, dp[i][j]);
            }
        }
        return (res == 0 || res == 1e3) ? -1 : res;
    }
};