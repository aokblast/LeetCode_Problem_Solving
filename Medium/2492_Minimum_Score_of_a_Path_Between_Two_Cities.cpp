//
//Runtime 379
//Memory Usage 101.1

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        int dis[n + 1], djs[n + 1];

        for(int i = 0; i <= n; ++i) 
            dis[i] = INT_MAX, djs[i] = i;

        function<int(int)> parent = [&](int u) {
            return u == djs[u] ? u : djs[u] = parent(djs[u]);
        };

        for(const auto &r : roads) {
            int p1 = parent(r[0]), p2 = parent(r[1]);
            
            if(dis[p1] > dis[p2])
                djs[p1] = p2, dis[p2] = min(dis[p2], r[2]);
            else
                djs[p2] = p1, dis[p1] = min(dis[p1], r[2]);
        }

        return dis[parent(n)];
    }
};