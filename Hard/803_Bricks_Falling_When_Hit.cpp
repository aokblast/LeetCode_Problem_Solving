//
//Runtime 280
//Memory Usage 103.2
class Solution {
public:
    int djs[40000] = {0};
    int cnt[40000] = {0};
    bool con[40000] = {false};
    int parent(int u){
        return u == djs[u] ? u : djs[u] = parent(djs[u]);
    }
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size(), n = grid[0].size(), k = hits.size();
        vector<int> res(k);
        int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
        for(int i = 0; i < m * n; ++i)
            djs[i] = i, cnt[i] = 1;
        for(const auto &hit : hits)
            grid[hit[0]][hit[1]] -= 1;
        for(int i = 0; i < n; ++i)
            con[i] = true;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] != 1)
                    continue;
                if(i + 1 < m && grid[i + 1][j] == 1){
                    int pa = parent(i * n  + j), pb = parent((i + 1) * n + j);
                    if(pa != pb)
                        djs[pa] = pb, cnt[pb] += cnt[pa], con[pa] = con[pb] = con[pa] | con[pb];
                }
                if(j + 1 < n && grid[i][j + 1] == 1){
                    int pa = parent(i * n + j), pb = parent(i * n + j + 1);
                    if(pa != pb)
                        djs[pa] = pb, cnt[pb] += cnt[pa], con[pa] = con[pb] = con[pa] | con[pb];
                }
            }
        
        }
        for(int i = k - 1; i >= 0; --i){
            int x = hits[i][0], y = hits[i][1], p = parent(x * n + y), tmp = 0;
            if(++grid[x][y] != 1)
                continue;
            for(int j = 0; j < 4; ++j){
                int xx = x + dir[j][0], yy = y + dir[j][1];
                if(xx < 0 || yy < 0 || xx >= m || yy >= n || grid[xx][yy] != 1 )
                    continue;
                int pp = parent(xx * n + yy);
                if(p == pp)
                    continue;
                if(!con[pp])
                    tmp += cnt[pp];
                djs[pp] = p, cnt[p] += cnt[pp], con[p] = con[pp] = con[p] | con[pp];
            }
            res[i] = tmp;
        }
        return res;
        
        
    }
};