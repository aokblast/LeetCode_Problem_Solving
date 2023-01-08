//dp
//Runtime 84
//Memory Usage 26

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int res = 0, n = mat.size(), m = mat[0].size();

        int sum[n + 1][m + 1];

        memset(sum, 0, sizeof(sum));

        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                sum[i][j] = mat[i - 1][j - 1] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
                if((i - res) >= 1 && (j - res) >= 1 
                && (sum[i][j] - sum[i - res - 1][j] - sum[i][j - res - 1] + sum[i - res - 1][j - res - 1] <= threshold))
                ++res;
            }
        }

        return res;
    }
};