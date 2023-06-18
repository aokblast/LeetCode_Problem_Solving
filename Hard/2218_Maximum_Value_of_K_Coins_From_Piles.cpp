//
//Runtime 196
//Memory Usage  10.8
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();

        int dp[k + 1], dp2[k + 1];
        memset(dp2, 0, sizeof(dp2));
        memset(dp, 0, sizeof(dp2));
        for(int i = 0; i < n; ++i) {
            int sz = piles[i].size();

            for(int j = 1; j < sz; ++j)
                piles[i][j] += piles[i][j - 1];

            for(int j = 1; j <= k; ++j) {
                int cur = 0;
                for(int t = 1; t <= sz; ++t) {
                    if((j - t) >= 0)
                        cur = max(cur, dp2[j - t] + piles[i][t - 1]);
                    else
                        break;
                }
                dp[j] = max(dp2[j], cur);
            }

            memcpy(dp2, dp, sizeof(dp));
        }

        return dp[k];
    }
};