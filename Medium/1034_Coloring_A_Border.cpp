//dfs
//Runtime 19
//Memory Usage 13.4

class Solution {
public:
    
    constexpr static int dirs[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        
        int n = grid.size(), m = grid[0].size();
        
        
        bool vis[n][m];
        memset(vis, 0, sizeof(vis));
    
        
        int curColor = grid[row][col];
        
        function<bool(int, int)> dfs = [&](int x, int y){

            bool cur = true;
         
            for(int i = 0; i < 4; ++i){
                int xx = x + dirs[i][0], yy = y + dirs[i][1];
                if(xx < 0 || yy < 0 || xx >= n || yy >= m || grid[xx][yy] != curColor)
                    cur = false;
            }
            vis[x][y] = true;
            
            for(int i = 0; i < 4; ++i){
                int xx = x + dirs[i][0], yy = y + dirs[i][1];
                if(xx < 0 || yy < 0 || xx >= n || yy >= m || grid[xx][yy] != curColor || vis[xx][yy])
                    continue;
                dfs(xx, yy);
            }   
            
            if(!cur)
                grid[x][y] = color;
            return true;
            
        };
        
        dfs(row, col);
        return grid;
        
        
    }
};