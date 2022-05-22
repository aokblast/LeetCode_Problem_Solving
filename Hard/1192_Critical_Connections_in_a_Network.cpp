//dfs
//Runtime 671
//Memory 160.1
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> res;
        vector<int> edges[n];
        for(const auto &conn : connections)
            edges[conn[0]].push_back(conn[1]), edges[conn[1]].push_back(conn[0]);
        
        int mark[n], back[n];
        memset(mark, 0, sizeof(mark));
        int tot = 0;
        function<void(int, int)> dfs = [&](int u, int p){
            mark[u] = back[u] = ++tot;
            for(const auto e : edges[u]){
                if(e == p)
                    continue;
                if(!mark[e])
                    dfs(e, u);
                back[u] = min(back[e], back[u]);
                if(mark[u] < back[e])
                    res.push_back({u, e});
            }            
        };
        
        dfs(0, -1);
        return res;
        
    }
};