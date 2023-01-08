//Prefix Sum
//Runtime 10
//Memory Usage 9.4

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        int ps[n + 1][m + 1];
        
        memset(ps, 0, sizeof(ps));

        for(int i = 0; i < n; ++i) 
            for(int j = 0; j < m; ++j) 
                ps[i + 1][j + 1] = mat[i][j] + ps[i + 1][j] + ps[i][j + 1] - ps[i][j];

        vector<vector<int>> res(n, vector<int>(m));

        for(int i = 0; i < n; ++i) 
            for(int j = 0; j < m; ++j) {
                int mx = min(i + k + 1, n), my = min(j + k + 1, m);
                int nx = max(i - k, 0), ny = max(j - k, 0);
                res[i][j] = ps[mx][my] - ps[mx][ny] - ps[nx][my] + ps[nx][ny];;
            }

        return res;
    }
};