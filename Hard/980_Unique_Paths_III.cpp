//dfs
//Runtime 2
//Memory 7.1
class Solution {
public:
    int steps = 1, n, m, tx, ty, res = 0;
    
    void dfs(vector<vector<int>>& g, int x, int y, int s){
        if(x < 0 || y < 0 || x >= n || y >= m || g[x][y] == -1)
            return;
        if(x == tx && y == ty)
            return void(res += s == steps);
        g[x][y] = -1;
        s += 1;
        dfs(g, x + 1, y, s);
        dfs(g, x - 1, y, s);
        dfs(g, x, y + 1, s);
        dfs(g, x, y - 1, s);
        g[x][y] = 0;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int sx = 0, sy = 0;
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 0)
                    ++steps;
                else if(grid[i][j] == 1)
                    sx = i, sy = j;
                else if(grid[i][j] == 2)
                    tx = i, ty = j;
            }
        }

        dfs(grid, sx, sy, 0);
        return res;
    }
};
