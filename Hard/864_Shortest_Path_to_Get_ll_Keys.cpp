//BFS
//Runtime 30
//Memory Usage 9.9
class Solution {
public:
    struct E{
        int x, y, cur;
    };
    int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
    
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size(), m = grid[0].size();
        int sx, sy, cnt = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(grid[i][j] == '@')
                    sx = i, sy = j, grid[i][j] = '.';
                else if(islower(grid[i][j]))
                    ++cnt;
                
                
        queue<E> q;
        q.push({sx, sy, 0});
        int mxKey = 1 << cnt;
        bool visit[n][m][mxKey];
        memset(visit, 0, sizeof(visit));
        visit[sx][sy][0] = true;
        int res = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [x, y, cur] = q.front(); q.pop();
                if(cur == mxKey - 1)
                    return res;
                for(int i = 0; i < 4; ++i){
                    int xx = x + dir[i][0], yy = y + dir[i][1];
                    if(xx < 0 || yy < 0 || xx >= n || yy >= m)
                        continue;
                    char c = grid[xx][yy];
                    int key = cur;
                    if(c == '#')
                        continue;
                    else if(islower(c))
                        key |= (1 << (c - 'a'));
                    else if(isupper(c) && !(cur & (1 << (c - 'A'))))
                        continue;
                    if(!visit[xx][yy][key]){
                        visit[xx][yy][key] = true;
                        q.push({xx, yy, key});
                    }
                }
                
            }
            res++;
        }
        return -1;
        
    }
};