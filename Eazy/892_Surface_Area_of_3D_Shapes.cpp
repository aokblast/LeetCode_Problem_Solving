//
//Runtime 11
//Memory Usage 9.1

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size(), res = 0;
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                int v = grid[i][j];
                int a = j > 0 ? min(v, grid[i][j - 1]) : 0;
                int b = i > 0 ? min(v, grid[i - 1][j]) : 0;
                int c = j < n - 1 ? min(v, grid[i][j + 1]) : 0;
                int d = i < n - 1 ? min(v, grid[i + 1][j]) : 0;
                res += (v > 0 ? 2 : 0) + (v << 2) - (a + b + c + d);
            }
        }
        return res;
    }
};
