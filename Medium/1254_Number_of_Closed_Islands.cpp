//dfs
//Runtime 16
//Memory Usage 9.5


class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), res = 0;
        
        constexpr static int dirs[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
        
        function<bool(int, int)> dfs = [&](int x, int y) {
            if(x < 0 || y < 0 || x >= n || y >= m)
                return false;
            
            if(grid[x][y])
                return true;
            
            grid[x][y] = 1;
            
            bool res = true;
            
            for(int i = 0; i < 4; ++i) {
                bool cur = dfs(x + dirs[i][0], y + dirs[i][1]);
                res = res && cur;
            }

            return res;
        };
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(grid[i][j] == 0)
                    res += dfs(i, j);
        
        return res;
    }
};