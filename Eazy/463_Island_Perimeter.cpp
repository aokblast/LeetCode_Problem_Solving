//
//Runtime 80 
//Memory Usage 96.1
class Solution {
public:
    int m , n;

    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j]) ans += (i == 0 || !grid[i - 1][j]) + (j == 0 || !grid[i][j - 1]) + (i == m - 1 || !grid[i + 1][j]) + (j == n - 1 || !grid[i][j + 1]); 
            }
        }
        return ans;
    }
};
