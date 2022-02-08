//dfs
//Runtime 15
//Memory Usage 23

class Solution {
public:
    int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
    int m, n;
    int dfs(int x, int y, vector<vector<int>>& g){
        if(x < 0 || y < 0 || x >= m || y >= n || !g[x][y])
            return 0;
        g[x][y] = 0;
        int res = 1;
        for(int i = 0; i < 4; ++i)
            res += dfs(x + dir[i][0], y + dir[i][1], g);
        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(grid[i][j])
                    res = max(res, dfs(i, j, grid));
        return res;
    }
};