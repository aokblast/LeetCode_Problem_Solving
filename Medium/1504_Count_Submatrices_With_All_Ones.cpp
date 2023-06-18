//
//Runtime 96
//Memory Usage 14

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), dp[n][m];
        memset(dp, 0, sizeof(dp));


        for(int j = m - 2; j >= 0; --j) {
            for(int i = 0; i < n; ++i) {
                if(mat[i][j] == 1) {
                    mat[i][j] += mat[i][j + 1];
                }
            }
        }
        int res = 0;

        for(int j = 0; j < m; ++j) {
            for(int i = 0; i < n; ++i) {
                int cur = INT_MAX;
                for(int k = i; k < n; ++k) {
                    cur = min(cur, mat[k][j]);
                    res += cur;
                }
            }
        }

        return res;
    }
};