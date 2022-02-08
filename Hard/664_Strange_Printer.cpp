//dp
//Runtime 20
//Memory Usage 6.2
class Solution {
public:
    int dp[105][105] = {{0}};
    int strangePrinter(string s) {
        int n = s.size();
        for(int r = 0; r < n; ++r){
            for(int l = r; l >= 0; --l){
                dp[l][r] = l == r ? 1 : 1 + dp[l + 1][r];
                for(int k = l + 1; k <= r; ++k){
                   if(s[l] == s[k])dp[l][r] = min(dp[l][r], dp[l + 1][k - 1] + dp[k][r]);
                }
            }
        }
        return n == 0 ? 0 : dp[0][n - 1];
    }
};