//djs
//Runtime 604
//Memory Usage 130.5

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        int djs[n];
        int sz[n];

        for(int i = 0; i < n; ++i) 
            djs[i] = i, sz[i] = 1;
        
        int res = 0;

        sort(edges.begin(), edges.end(), [&](const auto &a, const auto &b) {
            return max(vals[a[0]], vals[a[1]]) < max(vals[b[0]], vals[b[1]]);
        });

        function<int(int)> parent = [&](int u) {return u == djs[u] ? u : djs[u] = parent(djs[u]);};

        for(const auto &e : edges) {
            int p1 = parent(e[0]), p2 = parent(e[1]);

            if(vals[p1] == vals[p2])
                res += sz[p1] * sz[p2], djs[p1] = p2, sz[p2] += sz[p1];
            if(vals[p1] > vals[p2])
                djs[p2] = p1;
            else
                djs[p1] = p2;
        }

        return res + n;
    }
};