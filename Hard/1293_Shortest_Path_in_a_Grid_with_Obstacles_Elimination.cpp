//
//Runtime 66
//Memory Usage 15.6
class Solution {
public:
    
    struct E {
        int x, y, rem;
    };
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        queue<E> q;
        q.push({0, 0, k});
        bool vis[n][m][k + 1];
        
        memset(vis, 0, sizeof(vis));
        
        constexpr static int dirs[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
        
        int st = 0;
        while(q.size()) {
            int sz = q.size();
            while(sz--) {
                auto[x, y, s] = q.front(); q.pop();
                
                
                
                if(x == n - 1 && y == m - 1)
                    return st;
                
                if(grid[x][y] == 1) {
                    if(s-- <= 0) 
                        continue;
                    
                } 
                
                for(int i = 0; i < 4; ++i) {
                    int xx = x + dirs[i][0], yy = y + dirs[i][1];
                    
                    if(xx < 0 || yy < 0 || xx >= n || yy >= m || vis[xx][yy][s])
                        continue;
                    
                    vis[xx][yy][s] = true;
                    
                    q.push({xx ,yy, s});
                }
            }
            ++st;
        }
        return -1;
        
    }
};