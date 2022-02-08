//dp
//Runtime 19
//Memory Usage 6.9

class Solution {
public:
    
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        int dp[m + 1][n + 1];
        
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = 0;
        
        for(int j = 1; j <= n; ++j)
            dp[0][j] = dp[0][j - 1] + s2[j - 1];
        for(int i = 1; i <= m; ++i){
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
            for(int j = 1; j <= n; ++j){
                if(s1[i - 1] != s2[j - 1])
                    dp[i][j] = min(dp[i][j - 1] + s2[j - 1],  dp[i - 1][j] + s1[i - 1]);
                else
                    dp[i][j] = dp[i - 1][j - 1];
            }
        }
        return dp[m][n];
    }
};