//
//Runtime 20
//Memory Usage 12.9

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adjs[105];
        for(const auto &adj : flights)
            adjs[adj[0]].push_back({adj[1], adj[2]});
        using pii = pair<int, int>;
        queue<pii> q;
        int d[105];
        memset(d, 0x3f, sizeof(d));
        d[src] = 0;
        q.push({0, src});
        if(src == dst)
            return 0;
        ++k;
        while(!q.empty() && k--){
            int sz = q.size();
            while(sz--){
                auto [dist, cur] = q.front(); q.pop();
                for(const auto [adj, cost] : adjs[cur]){
                    if(dist + cost < d[adj])
                        d[adj] = dist + cost, q.push({dist + cost, adj});
                    
                }
            }
            
        }
        return d[dst] == 0x3f3f3f3f ? -1 : d[dst];
        
        
    }
};