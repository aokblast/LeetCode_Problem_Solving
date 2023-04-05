//dfs
//Runtime 174
//Memory Usage 60.4

class Solution {
public:
    int minTime(int n, vector<vector<int>>& _edges, vector<bool>& hasApple) {
        bool vis[n];

        memset(vis, 0, sizeof(vis));

        vector<int> edges[n];

        for(const auto &e :_edges)
            edges[e[0]].push_back(e[1]), edges[e[1]].push_back(e[0]);
        
        function<int(int)> dfs = [&](int u) {
            if(vis[u])
                return 0;
            
            vis[u] = true;

            int res = 0;

            for(const auto v : edges[u])
                res += dfs(v);
            
            return res == 0 && !hasApple[u] ? 0 : res + 2;
        };

        int res = dfs(0);
        return res == 0 ? 0 : res - 2;
    }
};