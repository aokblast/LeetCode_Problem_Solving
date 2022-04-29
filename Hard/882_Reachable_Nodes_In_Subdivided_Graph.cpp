//Dijstra
//Runtime 151
//Memory Usage 43.6
class Solution {
public:
    using pii = pair<int, int>;
    vector<pii> edges[3005];
    bool visit[3005] = {false};
    int dis[3005];
    int reachableNodes(vector<vector<int>>& es, int maxMoves, int n) {
        for(const auto &e : es)
            edges[e[0]].push_back({e[1], e[2]}), edges[e[1]].push_back({e[0], e[2]});
        
        priority_queue<pii, vector<pii>, greater<pii>> q;
        
        int res = 0;
        memset(dis + 1, 0x3f, sizeof(dis) - 4);
        q.push({0, 0});
        
        
        
        
        while(!q.empty()){
            auto [cur, u] = q.top(); q.pop();
            
            for(const auto [v, cost] : edges[u]){
                int dist = dis[u] + cost + 1;
                if(dist < dis[v] && dist <= maxMoves){
                    dis[v] = dist;
                    q.push({dist, v});
                }
            }
        }
        
        
        for(const auto &e : es){
            int u = e[0], v = e[1];
            int mn = min(dis[u], dis[v]), mx = max(dis[u], dis[v]);
            if(mn == 0x3f3f3f3f)
                continue;
            if(mx == 0x3f3f3f3f)
                res += min(e[2], maxMoves - mn);
            else
                res += min((maxMoves << 1) - mn - mx, e[2]);
        }
        for(int i = 0; i < n; ++i)
            res += dis[i] <= maxMoves;
        
        return res;
            
    }
};