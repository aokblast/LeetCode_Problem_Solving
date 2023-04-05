//
//Runtime 35
//Memory Usage  9.8

class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n = s.size();
        constexpr int MOD = 1e9 + 7;

        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        for(int i = 1; i <= n; ++i) {
            if(s[i - 1] == '0')
                continue;
            int cur = 0;

            for(int j = i; ((j - i + 1) <= 9) && j <= n; ++j) {
                cur = cur * 10 - '0' + s[j - 1];
                if(cur > k)
                    break;
                dp[j] = (dp[j] + dp[i - 1]) % MOD;
            }
            
        }

        return dp[n];
    }
};