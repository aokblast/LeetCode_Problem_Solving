//dp
//Runtime 40
//Memory Usage 9
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int dp[n][n];
        memset(dp, -1, sizeof(dp));
        dp[0][0] = grid[0][0];
        int lim = (n << 1) - 1;
        for(int s = 1; s < lim; ++s ){
            for(int i = n - 1; i >= 0; --i){
                for(int p = n - 1; p >= 0; --p){
                    int j = s - i, q = s - p;
                    if(j < 0 || q < 0 || j >= n || q >= n || grid[i][j] < 0 || grid[p][q] < 0){
                        dp[i][p] = -1;
                        continue;
                    }
                    if(i > 0)
                        dp[i][p] = max(dp[i][p], dp[i - 1][p]);
                    if(p > 0)
                        dp[i][p] = max(dp[i][p], dp[i][p - 1]);
                    if(i > 0 && p > 0)
                        dp[i][p] = max(dp[i][p], dp[i - 1][p - 1]);
                    if(dp[i][p] >= 0)
                        dp[i][p] += grid[i][j] + (i != p ? grid[p][q] : 0);
                    
                }
            }
        }
        return max(dp[n - 1][n - 1], 0);
        
    }
};