//djs
//Runtime 423
//Memory Usage 110.1

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        int un[n];

        for(int i = 0; i < n; ++i)
            un[i] = i;

        function<int(int)> parent = [&](int u) {
            return u == un[u] ? u : un[u] = parent(un[u]);
        };

        for(const auto &e : edges)
            un[parent(e[0])] = parent(e[1]);

        return parent(s) == parent(d);
    }
};