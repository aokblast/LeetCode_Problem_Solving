//bfs
//Runtime 48
//Memory Usage 12.8
class Solution {
public:
    int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
    bool visit[200][200] = {{false}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size(), ans = 0, mh = INT_MIN;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(!i || !j || i == m - 1 || j == n - 1)q.push({heightMap[i][j], i * n + j}), visit[i][j] = true;
            }
        }
        while(!q.empty()){
            pair<int, int> t = q.top(); q.pop();
            int x =  t.second / n, y = t.second % n;
            mh = max(mh, t.first);
            for(int i = 0; i < 4 ; ++i){
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if(nx < 0 || ny < 0 || nx >= m || ny >= n || visit[nx][ny])continue;
                visit[nx][ny] = true;
                if(heightMap[nx][ny] < mh) ans += mh - heightMap[nx][ny];
                q.push({heightMap[nx][ny], nx * n + ny});
            }
        }
        return ans;
        
    }
};
