//
//Runtime 38
//Memory Usage 17.7
class Solution {
public:
    int dir[2][2] = {-1, 1, 1, -1};
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> ans(m * n);
        int i = 0, x = 0, y = 0, d = 0;
        for(i; i < m * n; ++i){
            ans[i] = mat[x][y];
            x += dir[d][0], y += dir[d][1];
            if(x >= n)x = n - 1, y += 2, d = 1 - d;
            if(y >= m)y = m - 1, x += 2, d = 1 - d;
            if(x < 0)x = 0, d = 1 - d;
            if(y < 0)y = 0, d = 1 - d;

        }
        return ans;
    }
};
