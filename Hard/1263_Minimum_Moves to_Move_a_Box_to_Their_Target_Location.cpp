//dfs+ bfs
//Runtime 41
//Memory Usage 7.7
class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), sx = 0, sy = 0, tx = 0, ty = 0, px = 0, py = 0, res = 0;

        for (int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                char c = grid[i][j];

                if(c == 'S')
                    px = i, py = j;
                else if(c == 'T')
                    tx = i, ty = j;
                else if(c == 'B')
                    sx = i, sy = j; 

            }
        }

        queue<pair<int, int>> q;

        q.push({sx * m + sy, px * m + py});
        
        constexpr static int dirs[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
        bool vis[n][m][n][m];

        bool vis2[20][20];
        memset(vis, 0, sizeof(vis));

        
        while(!q.empty()) {
            ++res;
            int sz = q.size();

            while(sz--) {
                auto [s, p] = q.front(); q.pop();
                int sx = s / m, sy = s % m;
                grid[sx][sy] = '#';

                for(int i = 0; i < 4; ++i) {
                    int x = sx + dirs[i][0], y = sy + dirs[i][1], px = sx - dirs[i][0], py = sy - dirs[i][1];

                    if(x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == '#' 
                    || px < 0 || py < 0 || px >= n || py >= m || grid[px][py] == '#')
                        continue;

                    if(vis[x][y][px][py])
                        continue;
                    memset(vis2, 0, sizeof(vis2));

                    function<bool(int, int)> dfs = [&](int x, int y) {
                        if(x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == '#' || vis2[x][y])
                            return false;
                        
                        if(x == px && y == py)
                            return true;

                        vis2[x][y] = true;

                        for(int i = 0; i < 4; ++i)
                            if(dfs(x + dirs[i][0], y + dirs[i][1]))
                                return true;
                            
                        return false;
                    };

                    if(dfs(p / m, p % m)) {
                        if(x == tx && y == ty)
                            return res;
                        vis[x][y][px][py] = true;
                        q.push({x * m + y, px * m + py});
                    }
                }

                grid[sx][sy] = '.';

            }
        }
        return -1;
    }
};