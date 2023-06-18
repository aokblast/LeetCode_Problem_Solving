//DFS
//Runtime 119
//Memory Usage 14.2

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<int> adjs[n];
        bool vis[n];

        auto get_distance = [](const vector<int> &v1, const vector<int> &v2) {
            const long long x = v1[0] - v2[0], y = v1[1] - v2[1];
            return x * x + y * y;
        };

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(i != j && get_distance(bombs[i], bombs[j]) <= (long long)bombs[i][2] * bombs[i][2])
                    adjs[i].push_back(j);

        int res = 0;

        function<int(int)> dfs = [&](int u) {
            vis[u] = true;
            int res = 1;

            for(const auto v : adjs[u]) 
                if(!vis[v])
                    res += dfs(v);
            

            return res;
        };

        for(int i = 0; i < n; ++i) {
            memset(vis, 0, sizeof(vis));
            res = max(res, dfs(i));
        }
            
        
        return res;
    }
};