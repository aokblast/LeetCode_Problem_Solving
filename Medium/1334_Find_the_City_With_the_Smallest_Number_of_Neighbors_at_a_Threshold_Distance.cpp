//
//Runtime 29
//Memory Usage 11.5

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int dis[n][n];

        memset(dis, 0x3f, sizeof(dis));

        for(int i = 0; i < n; ++i)
            dis[i][i] = 0;

        for(const auto &e : edges) 
            dis[e[0]][e[1]] = dis[e[1]][e[0]] = e[2];
        
        for(int k = 0; k < n; ++k) 
            for(int i = 0; i < n; ++i) 
                for(int j = 0; j < n; ++j)
                    dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);

        int cnt = INT_MAX, res = 0;

        for(int i = n - 1; i >= 0; --i) {
            int cur = 0;

            for(int j = 0; j < n; ++j) 
                cur += (dis[i][j] <= distanceThreshold);
            
            if(cur < cnt)
                cnt = cur, res = i;
        }

        return res;
    }
};