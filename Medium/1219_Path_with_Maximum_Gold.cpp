//dfs
//Runtime 355
//Memory Usage 7.3

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), res = 0;
        
        
        constexpr int dirs[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
        
        function<int(int, int)> dfs = [&](int x, int y) {
            int res = 0, tmp = grid[x][y];
            grid[x][y] = 0;
            
            for(int i = 0; i < 4; ++i) {
                int xx = x + dirs[i][0], yy = y + dirs[i][1];
                
                if(xx < 0 || yy < 0 || xx >= n || yy >= m || grid[xx][yy] == 0)
                    continue;
                res = max(res, dfs(xx, yy));
            }
            return res + (grid[x][y] = tmp);
        };
        
        
        for(int i = 0; i < n; ++i) 
            for(int j = 0; j < m; ++j)
                if(grid[i][j])
                    res = max(res, dfs(i, j));
        
        return res;
    }
};