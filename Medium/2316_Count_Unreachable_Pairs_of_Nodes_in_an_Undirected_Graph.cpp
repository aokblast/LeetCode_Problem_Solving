//
//Runtime 482
//Memory Usage 135.2

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        int djs[n], sz[n];

        for(int i = 0; i < n; ++i)
            djs[i] = i, sz[i] = 1;

        function<int(int)> parent = [&](int u) {
            return u == djs[u] ? u : djs[u] = parent(djs[u]);
        };


        for(const auto &e : edges) {
            int p1 = parent(e[0]), p2 = parent(e[1]);
            if(p1 != p2) {
                djs[p1] = p2;
                sz[p2] += sz[p1];
            }
        }

        vector<int> aaa;

        long res = 0, tot = 0;

        for(int i = 0; i < n; ++i)
            if(djs[i] == i)
                aaa.push_back(sz[i]), tot += sz[i];
        
        int m = aaa.size();

        for(int i = 0; i < m; ++i)
            res += aaa[i] * (tot - aaa[i]);
        
        return res / 2;
    }
};