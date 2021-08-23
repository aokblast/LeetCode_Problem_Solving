//dp
//Runtime 12
//Memory Usage 10.8
class Solution {
public:
    int dp[1005][1005];
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        const int mod = 1e9 + 7;
        for(int i = 0; i  <= m; ++i) dp[0][i] = 1; 
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                dp[i][j] = (dp[i][j - 1] + (t[i - 1] == s[j-  1] ? dp[i - 1][j - 1] : 0 )) % mod; 
            }
        }
        return (int)dp[n][m];
    }
};
