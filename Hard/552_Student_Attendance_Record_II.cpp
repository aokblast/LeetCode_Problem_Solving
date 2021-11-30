//DP
//Runtime 48
//Memory Usage 7.3
class Solution {
    int dp[100005][3] = {{0}};

    const int MOD = 1e9 + 7;
public:
    int checkRecord(int n) {
        dp[0][0] = dp[0][1] = dp[0][2] = 1;
        dp[1][1] = 3, dp[1][2] = 2;
        dp[2][2] = 4;
        for(int i = 1; i < n; ++i){
            dp[i][0] = ((((dp[i  - 1][0] + dp[i - 1][1]) % MOD) + dp[i - 1][2]) % MOD);
            if(i >= 2)dp[i][1] = (((dp[i - 1][0] + dp[i - 1][2])  % MOD) + ((dp[i - 2][0] + dp[i - 2][2])  % MOD)) % MOD;
            if(i >= 3)dp[i][2] = ((((dp[i - 1][2] + dp[i - 2][2] ) % MOD) + dp[i - 3][2])) % MOD;
        }
        return (((dp[n - 1][0] + dp[n - 1][1]) % MOD) + dp[n - 1][2])  % MOD;
    }
};
