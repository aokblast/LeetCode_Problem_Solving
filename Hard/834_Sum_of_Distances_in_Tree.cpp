//dfs
//Runtime 309
//Memory Usage 87.3
class Solution {
public:
    int n;
    vector<vector<int>> es;
    vector<int> cnt, res;
    void dfs1(int u, int p){
        for(const int v : es[u]){
            if(p == v)
                continue;
            dfs1(v, u);
            cnt[u] += cnt[v];
            res[u] += res[v] + cnt[v];
        }
        ++cnt[u];
    }
    void dfs2(int u, int p){
        for(const int v : es[u]){
            if(p == v)
                continue;
            res[v] = res[u] + n - cnt[v] - cnt[v];
            dfs2(v, u);
        }
    }
    vector<int> sumOfDistancesInTree(int _n, vector<vector<int>>& edges) {
        n = _n;
        es.resize(n);
        cnt.resize(n);
        res.resize(n);
        
        for(const auto &edge : edges){
            int u = edge[0], v = edge[1];
            es[u].push_back(v), es[v].push_back(u);
        }
        dfs1(0, -1);
        dfs2(0, -1);
        return res;
    }
};