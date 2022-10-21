//dp
//Runtime 0
//Memory Usage 10.8

class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        int dp[n + 1][k + 1];
        
        memset(dp, 0, sizeof(dp));
        
        auto cnt = [](int n) {
            return n >= 100 ? 4 : n >= 10 ? 3 : n > 1 ? 2 : 1;
        };
        
        for(int i = n - 1; i >= 0; --i) {
            for(int j = 0; j <= k; ++j) {
                int rem = j;
                int res = j == 0 ? INT_MAX : dp[i + 1][j - 1];
                int tu = 0;
                for(int k = i; k < n && rem >= 0; ++k) {
                    if(s[i] == s[k]) {
                        ++tu;
                        res = min(res, cnt(tu) + dp[k + 1][rem]);
                    } else {
                        --rem;
                    }
                }
                dp[i][j] = res;
            }
        }
        
        return dp[0][k];
        
    }
};