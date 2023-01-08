//dp
//Runtime 67
//Memory Usage 23.8
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int dp[n+ 1][m + 1];
        
        memset(dp, 0, sizeof(dp));
        
        for(int i = 1; i <= n; ++i) 
            for(int j = 1; j <= m; ++j) 
                if(matrix[i - 1][j - 1])
                    dp[i][j] = min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]}) + 1;
                
            
        int res = 0;

        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                res += dp[i][j];
        
        return res;
    }
};