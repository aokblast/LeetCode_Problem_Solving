//dp
//Runtime 0
//Memory Usage 7.5

class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int n = seats.size(), m = seats[0].size(), lim = 1 << m;

        int dp[lim], pre[lim];

        memset(pre, -1, sizeof(pre));
        memset(dp, 0, sizeof(dp));

        int ava[n + 1];

        for(int i = 0; i < n; ++i) {
            int cur = 0;
            for(int j = 0; j < m; ++j)
                cur = cur << 1 | (seats[i][j] == '.');
            ava[i + 1] = cur;
        }
        pre[0] = 0;

        for(int i = 1; i <= n; ++i) {

            for(int j = 0; j < lim; ++j) {
                int cur = __builtin_popcount(j);
                if((ava[i] & j) == j && !(j & (j >> 1)) && !(j & (j << 1))) {
                    for(int k = 0; k < lim; ++k) {
                        if(!(j & (k >> 1)) && !(j & (k << 1)) && pre[k] != -1)
                            dp[j] = max(dp[j], pre[k] + cur);
                    }
                }
            }

            memcpy(pre, dp, sizeof(dp));
        }

        return *max_element(dp, dp + lim);
    }
};