//dp
//Runtime 5
//Memory Usage 8.2

class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        
        int dp[n][n];
        
        memset(dp, 0, sizeof(dp));
        
        for(int len = 3; len <= n; ++len){
            for(int l = 0; l + len <= n; ++l){
                int r = l + len - 1;
                int ans = INT_MAX;
                for(int k = l + 1; k < r; ++k){
                    ans = min(ans, dp[l][k] + dp[k][r] + values[l] * values[k] * values[r]);
                }
                dp[l][r] = ans;
            }
        }
        return dp[0][n - 1];
    }
    
};