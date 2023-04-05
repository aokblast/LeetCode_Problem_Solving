//dp
//Runtime 12
//Memory Usage 8.1

class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        constexpr int MOD = 1e9 + 7;

        vector<int> peoples[41];

        for(int i = 0; i < n; ++i)
            for(const auto hat : hats[i])
                peoples[hat].push_back(i);
        
        int dp[1 << n], dp2[1 << n], lim = 1 << n;

        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        for(int i = 0; i <= 40; ++i) {
            memcpy(dp2, dp, sizeof(dp));
            for(int j = 0; j < lim; ++j) {
                dp[j] = dp2[j];
                for(const auto p : peoples[i]) {
                    if((j & (1 << p))) {
                        dp[j] = (dp[j] + (dp2[j ^ (1 << p)])) % MOD;
                    }
                }
            }
        }

        return dp[lim - 1];
    }
};