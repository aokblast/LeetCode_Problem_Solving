//dp
//Runtime 10
//Memory Usage 6.4

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int dp[high + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        const int MOD = 1e9 + 7;
        int res = 0;
        for(int i = 0; i <= high; ++i) {
            if(i + zero <= high)
                dp[i + zero] = (dp[i + zero] + dp[i]) % MOD;
            if(i + one <= high)
                dp[i + one] = (dp[i + one] + dp[i]) % MOD;

            if(low <= i)
                res = (res + dp[i]) % MOD;
        }
        
        return res;
    }
};