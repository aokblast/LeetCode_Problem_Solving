//
//Runtime 24
//Memory Usage 14


class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), mn = m * n;
        
        vector<vector<int>> res(m, vector<int>(n));
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                int id = (i * n + j + k) % mn;
                res[id / n][id % n] = grid[i][j];
            }
        }
        return res;
    }
};