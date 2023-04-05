//dp
//Runtime 4
//Memory Usage 8.6

class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();

        int select = n / 3;

        int dp1[select + 1][n];
        int dp2[select + 1][n];

        memset(dp1, 0, sizeof(dp1));
        memset(dp2, 0, sizeof(dp2));

        dp1[1][0] = slices[0];
        dp2[1][1] = slices[1];
        int mx1, mx2;

        for(int i = 1; i <= select; ++i) {
            mx1 = dp1[i - 1][0];
            mx2 = dp2[i - 1][0];

            for(int j = 2; j < n; ++j) {
                dp1[i][j] = mx1 + slices[j];
                dp2[i][j] = mx2 + slices[j];
                mx1 = max(mx1, dp1[i - 1][j - 1]);
                mx2 = max(mx2, dp2[i - 1][j - 1]);
            }
        }

        int res = 0;

        for(int i = 0; i < n - 1; ++i)
            res = max(res, dp1[select][i]);

        for(int i = 0; i < n; ++i)
            res = max(res, dp2[select][i]);
        
        return res;
    }
};