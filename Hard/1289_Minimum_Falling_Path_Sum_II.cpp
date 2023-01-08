//dp
//Runtime 329
//Memory Usage 14.6

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 1)
            return grid[0][0];

        int dp[n], pre[n];

        for(int i = 0; i < n; ++i) 
            pre[i] = grid[0][i];

        for(int i = 1; i < n; ++i) { 
            memset(dp, 0x3f, sizeof(dp));
            for(int j = 0; j < n; ++j) {
                for(int k = 0; k < n; ++k) {
                    if(j != k) 
                        dp[k] = min(dp[k], pre[j] + grid[i][k]);
                }
            }

            memcpy(pre, dp, sizeof(pre));
        }

        return *min_element(dp, dp + n);
    }
};