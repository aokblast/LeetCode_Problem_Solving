//dfs
//Runtime 64
//Memory Usage 21.7

class Solution {
public:
    
    constexpr static int dirs[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
    
    int n, m;
    
    void dfs(vector<vector<int>> &grid, int x, int y) {
        if(x < 0 || y < 0 || x >= n || y >= m || !grid[x][y])
            return ;
        grid[x][y] = 0;
        
        for(int i = 0; i < 4; ++i)
            dfs(grid, x + dirs[i][0], y + dirs[i][1]);
        
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        
        for(int i = 0; i < n; ++i){
            if(grid[i][0])
                dfs(grid, i, 0);
            if(grid[i][m - 1])
                dfs(grid, i, m - 1);
        }
        
        for(int i = 0; i < m; ++i){
            if(grid[0][i])
                dfs(grid, 0, i);
            if(grid[n - 1][i])
                dfs(grid, n - 1, i);
        }
        int res = 0;
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                res += grid[i][j];
        return res;
    }
};