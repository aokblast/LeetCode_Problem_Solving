//
//Runtime 21
//Memory Usage 11.4

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> res;

        int r[n], c[m];
        memset(r, 0x3f, sizeof(r));
        memset(c, 0, sizeof(c));

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                r[i] = min(r[i], matrix[i][j]);
                c[j] = max(c[j], matrix[i][j]);
            }
        }

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(r[i] == c[j])
                    res.push_back(r[i]);
            }
        }

        return res;
    }
};