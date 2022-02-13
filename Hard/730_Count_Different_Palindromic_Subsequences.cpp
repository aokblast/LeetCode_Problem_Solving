//dp
//Runtime 90
//Memory Usage 10.6
class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        int dp[n + 1][n + 1];
        const int MOD = 1e9 + 7;
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; ++i)
            dp[i][i] = 1;
        for(int len = 2; len <= n; ++len){
            for(int l = 0; l + len <= n; ++l){
                int r = l + len - 1;
                if(s[l] == s[r]){
                    int i = l + 1, j = r - 1;
                    while(i <= j && s[i] != s[l])
                        ++i;
                    while(i <= j && s[j] != s[l])
                        --j;
                    if(i > j)
                        dp[l][r] = dp[l + 1][r - 1] * 2 + 2;
                    else if(i == j)
                        dp[l][r] = dp[l + 1][r - 1] * 2 + 1;
                    else
                        dp[l][r] = dp[l + 1][r - 1] * 2 - dp[i + 1][j - 1];
                }else{
                    dp[l][r] = dp[l + 1][r] + dp[l][r - 1] - dp[l + 1][r - 1];
                }
                dp[l][r] = (dp[l][r] < 0) ? dp[l][r] + MOD : dp[l][r] % MOD;
            }
        }
        return dp[0][n - 1];
    }
};