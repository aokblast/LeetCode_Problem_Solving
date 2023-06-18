//
//Runtime 162
//Memory Usage 26.2

class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int n = target.size(), res = 0, m = words[0].size(), cnts[m][26];
        constexpr int MOD = 1e9 + 7;
        memset(cnts, 0, sizeof(cnts));

        for(const auto &word : words) 
            for(int i = 0; i < m; ++i) 
                ++cnts[i][word[i] - 'a'];
        
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        for(int i = 0; i < m; ++i)
            for(int j = n - 1; j >= 0; --j)
                dp[j + 1] = (dp[j + 1] + (long)dp[j] * cnts[i][target[j] - 'a']) % MOD;

        
        return dp[n];
    }
};