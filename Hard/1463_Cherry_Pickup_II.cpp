//dp
//Runtime 28
//Memory Usage 11.7
class Solution {
public:
    int dp[75][75][75] = {{{-1}}};
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        int res= 0 ;
        memset(dp[0], -1, sizeof(dp[0]));
        dp[0][0][n - 1] = grid[0][0] + grid[0][n - 1];
        for(int k = 1; k < m; ++k){
            for(int x = 0; x < n; ++x){
                for(int y = 0; y < n; ++y){
                    
                    int pre = -1;
                    for(int i = -1; i <= 1; ++i){
                        for(int j = -1; j  <= 1; ++j){
                            if(x + i < 0 || y + j < 0 || x + i >= n || y + j >= n ||  dp[k - 1][x + i][y + j] == -1)continue;
                            pre = pre == -1 ? dp[k - 1][x + i][y + j] : max(pre, dp[k - 1][x + i][y + j]);
                        }
                    }
                    dp[k][x][y] = pre == -1 ? -1 : pre + (x == y ? grid[k][x] : (grid[k][x] + grid[k][y]));
                    res = max(res, dp[k][x][y]);
                    
                } 
            }
        }
        return res;
    }
};