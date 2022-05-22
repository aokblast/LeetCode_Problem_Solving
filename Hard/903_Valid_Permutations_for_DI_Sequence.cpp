//
//Runtime 3
//Memory Usage  6.4
class Solution {
public:
    int dp[205][205] = {{0}};
    static const int MOD = 1e9 + 7;
    int numPermsDISequence(string s) {
        int n = s.size();
        for(int i = 0; i <= n; ++i)
            dp[0][i] = 1;
        
        
        for(int i = 1; i <= n; ++i){
            int cur = 0;
            if(s[i - 1] == 'D'){
                for(int j = n - i; j >= 0; --j){
                    cur = (cur + dp[i - 1][j + 1]) % MOD;
                    dp[i][j] = cur;
                }
            }else{
                for(int j = 0; j <= n - i; ++j){
                    cur = (cur + dp[i - 1][j]) % MOD;
                    dp[i][j] = cur;
                }
            }
        }
        return dp[n][0];
    }
};