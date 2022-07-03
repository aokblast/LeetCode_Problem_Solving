//dfs
//Runtime 10
//Memory 9.4
class Solution {
public:
    bool vis[90][90] = {{false}};
    static constexpr int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
    int n;
    void dfs(int x, int y){
        if(x < 0 || y < 0 || x >= n || y >= n || vis[x][y])
            return;
        vis[x][y] = true;
        for(int i = 0; i < 4; ++i){
            int xx = x + dir[i][0], yy = y + dir[i][1];
            dfs(xx, yy);
        }
            
    }
    int regionsBySlashes(vector<string>& grid) {
        n = grid.size();
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(grid[i][j] == '\\'){
                    vis[i * 3][j * 3] = true;
                    vis[i * 3 + 1][j * 3 + 1] = true;
                    vis[i * 3 + 2][j * 3 + 2] = true;
                }else if(grid[i][j] == '/'){
                    vis[i * 3][j * 3 + 2] = true;
                    vis[i * 3 + 1][j * 3 + 1] = true;
                    vis[i * 3 + 2][j * 3] = true;
                }
        int res = 0;
        n *= 3;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(!vis[i][j]){
                    ++res;
                    dfs(i, j);
                }
            }
                
        }
        return res;
    }
};