//dfs
//Runtime 3
//Memory Usage 8.2
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        
        
        for(int i = 1; i <= n; ++i) {
            int w = books[i - 1][0], h = books[i - 1][1];
            dp[i] = dp[i - 1] + h;
            for(int j = i - 2; j >= 0 && w + books[j][0] <= shelfWidth; --j) {
                h = max(h, books[j][1]);
                w += books[j][0];
                dp[i] = min(dp[j] + h,  dp[i]);
            }
        }

        return dp[n];
    }
};