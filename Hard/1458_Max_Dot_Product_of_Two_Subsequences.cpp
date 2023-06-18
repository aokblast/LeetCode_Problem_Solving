//dp
//Runtime 20
//Memory Usage 10.1
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();

        int dp[n + 1][m + 1];
        memset(dp, -0x7f, sizeof(dp));

        for(int i = 1; i <= n; ++i) 
            for(int j = 1; j <= m; ++j) 
                dp[i][j] = max({dp[i - 1][j]
                , dp[i][j - 1], dp[i - 1][j - 1], max(dp[i - 1][j - 1], 0) + nums1[i - 1] * nums2[j - 1]});

        return dp[n][m];
    }
};