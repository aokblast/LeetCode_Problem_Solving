//dfs
//Runtime 202
//Memory Usage 118.5

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();

        int dis[n], res = -1;
        bool in[n];

        memset(dis, -1, sizeof(dis));
        memset(in, 0, sizeof(in));

        function<void(int)> dfs = [&](int u) {
            in[u] = true;
            int v = edges[u];
            if(v == -1) {
                in[u] = false;
                return;
            }
            if(dis[v] != -1) {
                if(in[v])
                    res = max(res, dis[u] - dis[v] + 1);
            }  else {
                dis[v] = dis[u] + 1;
                dfs(v);
            }
            in[u] = false;
        };

        for (int i = 0; i < n; ++i) {
            if(dis[i] == -1) {
                dis[i] = 1;
                dfs(i);   
            }
        }
        
        return res;
    }
};