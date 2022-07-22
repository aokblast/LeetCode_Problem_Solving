//bfs
//Runtime 5
//Memory Usage 13.1
class Solution {
public:
    constexpr static int dirs[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
    int orangesRotting(vector<vector<int>>& grid) {
        int cur = 0;
        
        queue<pair<int, int>> q;
        
        int n = grid.size(), m = grid[0].size();
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 1)
                    ++cur;
                else if(grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        
        int res = 0;
        if(cur == 0)
            return 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [x, y] = q.front(); q.pop();
                for(int i = 0; i < 4; ++i){
                    int xx = x + dirs[i][0], yy = y + dirs[i][1];
                    if(xx < 0 || yy < 0 || xx >= n || yy >= m || grid[xx][yy] != 1)
                        continue;
                    grid[xx][yy] = 2;
                    --cur;
                    q.push({xx, yy});
                }
            }
            
            ++res;
        }
        
        return cur == 0 ? (res - 1) : -1;
    }
};