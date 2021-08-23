//dp
//Runtime 0
//Memory Usage 7.5

class Solution {
    int dp[105][105];
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        dp[0][0] = 1;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if((i - 1) >= 0 && !obstacleGrid[i - 1][j]) dp[i][j] += dp[i - 1][j];
                if((j - 1) >= 0 && !obstacleGrid[i][j - 1]) dp[i][j] += dp[i][j - 1];
            }
        }
        return ((obstacleGrid[m - 1][n - 1] == 0) ? dp[m - 1][n - 1] : 0);
    }
};
