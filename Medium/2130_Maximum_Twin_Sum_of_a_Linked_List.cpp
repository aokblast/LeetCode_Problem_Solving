//
//Runtime 259
//Memory Usage 126.7

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), dp[n][m];
        memset(dp, 0, sizeof(dp));

        for(int j = m - 2; j >= 0; --j) {
            for(int i = 0; i < n; ++i) {
                if(mat[i][j] == 1) {
                    dp[i][j] = dp[i][j + 1] + 1;
                }
            }
        }

        int res = 0;

        for(int j = 0; j < m; ++j) {
            for(int i = 0; i < n; ++i) {
                int cur = INT_MAX;
                for(int k = i; k < n; ++k) {
                    cur = min(cur, dp[k][j]);
                    res += cur;
                }
            }
        }

        
        return res;
    }
};