//
//Runtime 3
//Memory Usage 8.4
class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        int n = cost.size(), dp[n + 1][target + 1];

        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;

        for(int i = 1; i <= n; ++i) {
            int c = cost[i - 1];
            for(int j = 0; j <= target; ++j) {
                if(j < c) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    int x = dp[i - 1][j];
                    if(dp[i][j - c] != -1)
                        x = max(x, dp[i][j - c] + 1);
                    dp[i][j] = x;
                }
            }
        }
        string res;
        
        int r = n, c = target;
        if(dp[r][c] == -1)
            return "0";

        while(c) {
            int v = cost[r - 1];
            if(v > c)
                --r;
            else
                if(dp[r][c] == (dp[r][c - v] + 1))
                    res += (char)('0' + r), c -= v;
                else
                    --r;
        }

        return res;
    }
};

