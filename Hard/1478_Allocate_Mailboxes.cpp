//dp
//Runtime 12
//Memory Usage 7.6
class Solution {
public:
    int minDistance(vector<int>& houses, int K) {
        sort(houses.begin(), houses.end());
        int n = houses.size(), dp[n], acc[n + 1];

        memset(dp, 0x3f, sizeof(dp));
        acc[0] = 0;

        for(int i = 0; i < n; ++i)
            acc[i + 1] = acc[i] + houses[i];

        for(int k = 1; k <= K; ++k) {
            for(int j = n - 1; j > k - 2; --j) {
                for(int i = k - 2; i < j; ++i) {
                    int m1 =  (i + j + 1) / 2, m2 = (i + j + 2) / 2;
                    int last = (acc[j + 1] - acc[m2]) - (acc[m1 + 1] - acc[i + 1]);
                    dp[j] = min(dp[j], (i >= 0 ? dp[i] : 0) + last);
                }
            }
        }
        
        return dp[n - 1];
    }
};