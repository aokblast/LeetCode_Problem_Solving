//
//Runtime 12
//Memory Usage 9.7

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        if(n == 1)
            return matrix[0][0];
        
        int dp[n], next[n];
        
        for(int i = 0; i < n; ++i)
            dp[i] = matrix[0][i];
        
        for(int i = 1; i < n; ++i){
            next[0] = min(dp[0], dp[1]) + matrix[i][0];
            
            for(int j = 1; j < n - 1; ++j)
                next[j] = min({dp[j - 1], dp[j], dp[j + 1]}) + matrix[i][j];
            
            next[n - 1] = min(dp[n - 1], dp[n - 2]) + matrix[i][n - 1];
            memcpy(dp, next, sizeof(next));
        }
        int res = INT_MAX;
        for(int i = 0; i < n; ++i)
            res = min(res, dp[i]);
        return res;
        
    }
};