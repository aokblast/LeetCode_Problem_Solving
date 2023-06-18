//dp
//Runtime 40
//Memory 8.2

class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        const int lim = 1 << n;
        int dp[lim];
        int pre[n];
        memset(dp, 0x3f, sizeof(dp));
        memset(pre, 0, sizeof(pre));

        for(const auto &rel : relations)
            pre[rel[1] - 1] |= (1 << (rel[0] - 1));
        dp[0] = 0;
        int idx[n];

        for(int cur = 0; cur < lim; ++cur) {
            if(dp[cur] == 0x3f3f3f3f)
                continue;
            int c = 0;
            int nc = 0;
            for(int j =0; j < n; ++j) {
                if(cur & (1 << j))
                    continue;
                if((cur & pre[j]) == pre[j])
                    idx[nc++] = j, c |= 1 << j;
            }
            if(nc <= k)
                dp[cur | c] = min(dp[cur | c], dp[cur] + 1);
            else {
                for (int s = (1<<k)-1; s < (1<<nc);) {    
                    int subsetk = 0;
                    for (int j = 0; j < nc; j++) {
                        if ((s >> j) & 1)
                            subsetk = subsetk | (1 << idx[j]);
                    }
                    dp[cur|subsetk] = min(dp[cur|subsetk], dp[cur]+1);
                    
                    int x = s & -s;
                    int y = s + x;
                    s = (((s & ~y) / x) >> 1) | y;
                }
            }
        }
        
        return dp[lim - 1];
    }
};