//dp
//Runtime 19
//Memory Usage 14.1

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int dp[n + 1];
        
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i <= n; ++i) {
            int l = max(0, i - ranges[i]), r = min(n, i + ranges[i]);
            dp[l] = max(dp[l], r - l);
        }

        int res = 0, r = 0;

        for(int i = 0, cur = 0; i < n; ++i) {
            if(i > r)
                return -1;
            cur = max(cur, i + dp[i]);
            if(i == r)
                res++, r = cur;
        }
        return r >= n ? res : -1;
    }
};