//dfs + djs
//Runtime 12
//Memory Usage 9.9
class Solution {
public:
    int djs[305 * 305];
    bool visit[305][305];
    int m, n;
    int parent(int id){
        return id == djs[id] ? id : djs[id] = parent(djs[id]);
    }
    void dfs(int x, int y, int &ans, vector<vector<char>>& grid){
        if(visit[x][y]) return;
        visit[x][y] = true;
        int p1 = parent(x * n + y);
        if((y + 1) < n && !visit[x][y + 1]){
            int p2 = parent(x * n + y + 1);
            if(p1 != p2) --ans, djs[p2] = p1, dfs(x, y + 1, ans, grid);
        }
        if((x + 1) < m && !visit[x + 1][y]){
            int p2 = parent((x + 1) * n + y);
            if(p1 != p2) --ans, djs[p2] = p1, dfs(x + 1, y, ans, grid);
        }
        if((y - 1) >= 0 && !visit[x][y - 1]){
            int p2 = parent(x * n + y - 1);
            if(p1 != p2) --ans, djs[p2] = p1, dfs(x, y - 1, ans, grid);
        }
        if((x - 1) >= 0 && !visit[x - 1][y]){
            int p2 = parent((x - 1) * n + y);
            if(p1 != p2) --ans, djs[p2] = p1, dfs(x - 1, y, ans, grid);
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans  = 0;
        m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '1'){
                    ++ans;
                    djs[i * n + j] = i * n + j;
                }else{
                    visit[i][j] = true;
                }
            }
        }
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(!visit[i][j]){
                    dfs(i, j, ans, grid);
                }
            }
        }
        return ans;
    }
};
