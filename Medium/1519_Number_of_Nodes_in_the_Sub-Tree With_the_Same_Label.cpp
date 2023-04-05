//dfs
//Runtime 544
//Memory Usage 205.8

class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> adjs[n];
        int cnt[26] = {0};
        vector<int> res(n);
        int vis[n];
        memset(vis, 0, sizeof(vis));

        for(const auto &e: edges)
            adjs[e[0]].push_back(e[1]), adjs[e[1]].push_back(e[0]);

        function<array<int, 26>(int)> dfs = [&](int u) {
            if(vis[u])
                return array<int, 26>{};
            vis[u] = true;
            array<int, 26> cur{};

            for(const auto v : adjs[u]) {
                auto c = dfs(v);                
                for(int i = 0; i < 26; ++i)
                    cur[i] += c[i];
            }

            res[u] = ++cur[labels[u] - 'a'];
            return cur;            
        };

        dfs(0);
        return res;
    }
};