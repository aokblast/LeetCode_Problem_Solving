//bfs
//Runtime 452
//Memory Usage 73.5
class Solution {
public:
    struct N{
        int x, y, step;
        bool operator<(const N &n) const{
            return step < n.step;
        }
    };
    

    
    int cutOffTree(vector<vector<int>>& forest) {
        int n = forest.size(), m = forest[0].size();
        int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
        int vis[n][m];
        auto bfs = [&](int sx, int sy, int dx, int dy){
            if(sx == dx && sy == dy)
                return 0;
            queue<pair<int, int>> q;
            memset(vis, 0, sizeof(vis));
            int res = 0;
            q.push({sx, sy});
            
            while(!q.empty()){
                int sz = q.size();
                ++res;
                while(sz--){
                    auto [x, y] = q.front(); q.pop();
                    
                    for(int i = 0; i < 4; ++i){
                        int nx = x + dir[i][0], ny = y + dir[i][1];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny] || forest[x][y] == 0)
                            continue;
                        if(nx == dx && ny == dy)
                            return res;
                        q.push({nx, ny});
                        vis[nx][ny] = true;
                    }
                }

                
                
            }
            return INT_MAX;
        };
        
        vector<N> v;
        
        int res = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(forest[i][j] > 1)
                    v.push_back({i, j, forest[i][j]});
        
        sort(v.begin(), v.end());
        int x = 0, y = 0;
        
        for(auto &[nx, ny, val] : v){
            int cur = bfs(x, y, nx, ny);
            
            if(cur == INT_MAX)
                return -1;
            
            res += cur;
            x = nx, y = ny;
        }
        return res;
    }
};