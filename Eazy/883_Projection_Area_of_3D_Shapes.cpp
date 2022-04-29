//
//Runtime 4
//Memory Usage 9.3
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size(), res = 0;
        for(int i = 0; i < n; ++i){
            int a = 0, b = 0;
            for(int j = 0; j < n; ++j)
                a = max(a, grid[i][j]), b = max(b, grid[j][i]), res += (!!grid[i][j]);
            res += a + b;
        }
        return res;
    }
};