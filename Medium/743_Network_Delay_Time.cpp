//dij
//Runtime 108
//Memory usage 39.8
class Solution {
public:
    vector<pair<int, int>> adjs[100];

    int dij(int u, int n){
        priority_queue<pair<int, int>> q;
        q.push({0, u});
        int dis[n];
        memset(dis, 0x3f, sizeof(dis));
        dis[u] = 0;
        while(!q.empty()){
            const auto [d, u]  = q.top(); q.pop();
            for(const auto [v, c] : adjs[u]){
                if(d + c < dis[v]){
                    dis[v] = d + c;
                    q.push({d + c, v});
                }
            }
        }
        int res = 0;
        for(int i = 0; i < n; ++i){
            if(dis[i] == 0x3f3f3f3f)
                return -1;
            res = max(res, dis[i]);
        }
        return res;
            
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(const auto &v : times)
            adjs[v[0] - 1].push_back({v[1] - 1, v[2]});
        return dij(k - 1, n);
    }
};