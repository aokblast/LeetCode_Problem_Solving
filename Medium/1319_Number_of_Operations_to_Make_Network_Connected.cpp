//djs
//Runtime 122
//Memory Usage 37.2

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n - 1 > connections.size())
            return -1;

        int djs[n];
        memset(djs, 0, sizeof(djs));

        for(int i = 0;  i < n; ++i)
            djs[i] = i;

        int res = n - 1;

        function<int(int)> parent = [&](int u) {
            return u == djs[u] ? u : djs[u] = parent(djs[u]);
        };

        for(const auto &c : connections) {
            int px = parent(c[0]), py = parent(c[1]);
            res -= px != py;
            djs[px] = py;
        }

        return res;

    }
};