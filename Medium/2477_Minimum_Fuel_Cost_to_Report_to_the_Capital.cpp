//Topology Sort
//Runtime 593
//Memory Usage 155.2


class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        long long res = 0;
        int n = roads.size() + 1;

        int cd[n], dp[n];

        vector<int> adjs[n];

        memset(cd, 0, sizeof(cd));
        memset(dp, 0, sizeof(dp));

        for(const auto &r : roads)
            adjs[r[0]].push_back(r[1]), adjs[r[1]].push_back(r[0]), cd[r[0]]++, cd[r[1]]++;

        queue<int> q;

        bool vis[n];
        memset(vis, 0, sizeof(vis));

        for(int i = 0; i < n; ++i) {
            if(cd[i] == 1)
                q.push(i);
            dp[i] = 1;
        }
        
        while(!q.empty()) {
            int u = q.front(); q.pop();
            if(u == 0)
                continue;
            vis[u] = true;
            int c = dp[u];

            for(const auto v : adjs[u]) {
                if(vis[v])
                    continue;
                res += (c + seats - 1) / seats;
                dp[v] += dp[u];

                if(--cd[v] == 1)
                    q.push(v);
            }
        }

        return res;
    }
};