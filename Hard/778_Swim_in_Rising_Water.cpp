//BFS
//Runtime 12
//Memory 8.6
class Solution {
public:

    int swimInWater(vector<vector<int>>& grid) {
        int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({grid[0][0], 0});
        int n = grid.size();
        bool visit[n][n];
        memset(visit, 0, sizeof(visit));
        visit[0][0] = true;
        if(n == 1)
            return 0;
        int res = grid[n - 1][n - 1];
        while(!q.empty()){
            auto [dis, cur] = q.top(); q.pop();
            res = max(res, grid[cur / n][cur % n]);
            for(int i = 0; i < 4; ++i){
                int xx = cur / n + dir[i][0], yy = cur % n + dir[i][1];
                if(xx < 0 || yy < 0 || xx >= n || yy >= n || visit[xx][yy])
                    continue;
                q.push({grid[xx][yy], xx * n + yy});
                visit[xx][yy] = true;
                if(xx == n - 1 && yy == n - 1)
                    return res;
            }
        }
        return res;
        
    }
};