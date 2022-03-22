//unordered_set
//Runtime 0
//Memory Usage 7.1
class Solution {
public:
    int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
    int vis[500][500] = {{0}};
    int area[250000] = {0};
    int n;
    int col = 0;
    int dfs(int x, int y, vector<vector<int>>& g){
        if(x < 0 || y < 0 || x >= n || y >= n || vis[x][y] || g[x][y] == 0)
            return 0;
        vis[x][y] = col;
        return 1 + dfs(x + 1, y, g) + dfs(x, y + 1, g) + dfs(x - 1, y, g) + dfs(x, y - 1, g);
    }
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(grid[i][j])
                    ++col, area[col] = dfs(i, j, grid);
        
        int res = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(!grid[i][j]){
                    unordered_set<int> s;
                    if(i > 0)
                        s.insert(vis[i - 1][j]);
                    if(j > 0)
                        s.insert(vis[i][j - 1]);
                    if(i < n - 1)
                        s.insert(vis[i + 1][j]);
                    if(j < n - 1)
                        s.insert(vis[i][j + 1]);
                    int cur = 1;
                    for(const int id : s)
                        cur += area[id];
                    res = max(res, cur);
                    
                }
            }
        }
        return res == 0 ? n * n : res;
        
        
    }
};