//dfs + bfs
//Runtime 48
//Memory Usage 87.9

class Solution {
public:
    const int dirs[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        bool vis[n][n];
        memset(vis, 0, sizeof(vis));
        queue<pair<int, int>> q;
        function<void(int, int)> dfs = [&](int x, int y){
            bool isv = true;
            vis[x][y] = true;
            for(int i = 0; i < 4; ++i){
                int xx = x + dirs[i][0], yy = y + dirs[i][1];
                if(xx < 0 || yy < 0 || xx >= n || yy >= n || vis[xx][yy])
                    continue;
                if(grid[xx][yy] == 0)
                    isv = false;
                else
                    dfs(xx, yy);
            }
            if(!isv)
                q.push({x, y});
        };
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j)
                if(grid[i][j]){
                    dfs(i, j);
                    goto find;
                }
        }
        
        find:
        
        
        int res = 0;
        while(!q.empty()){
            ++res;
            int sz = q.size();
            while(sz--){
                auto [x, y] = q.front(); q.pop();
                for(int i = 0; i < 4; ++i){
                    int xx = x + dirs[i][0], yy = y + dirs[i][1];
                    if(xx < 0 || yy < 0 || xx >= n || yy >= n || vis[xx][yy])
                        continue;
                    if(grid[xx][yy] == 1)
                        return res - 1;
                    vis[xx][yy]= true;
                    q.push({xx, yy});
                    
                }
            }
        }
        return 0;
            
    }
};