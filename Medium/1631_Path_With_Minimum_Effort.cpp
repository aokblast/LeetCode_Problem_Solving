//
//Runtime 137
//Memory Usage 17.6

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        int dis[n * m];
        memset(dis, 0x3f, sizeof(dis));
        dis[0] = 0;
        using pii = pair<int, int>;
        int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
        
        priority_queue<pii, vector<pii>, greater<pii>> q;
        
        q.push({0, 0});
        
        while(!q.empty()){
            auto [cost, u] = q.top(); q.pop();
            
            int x = u / m, y = u % m;
            for(int i = 0; i < 4; ++i){
                int xx = x + dir[i][0], yy = y + dir[i][1];
                if(xx < 0 || yy < 0 || xx >= n || yy >= m)
                    continue;
                int v = xx * m + yy;
                int nc = max(cost, abs(heights[xx][yy] - heights[x][y]));
                if(dis[v] > nc){
                    q.push({nc, v});
                    dis[v] = nc;
                }
            }
            
        }
        return dis[n * m - 1];

    }
};