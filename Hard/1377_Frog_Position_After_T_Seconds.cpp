//BFS
//Runtime: 19
//Memory Usage: 14.5

class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<int> adjs[n + 1];

        for(const auto &e : edges)
            adjs[e[0]].push_back(e[1]), adjs[e[1]].push_back(e[0]);
        
        queue<int> q;

        q.push(1);

        double dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[1] = 1;

        while(!q.empty()) {
            
            int sz = q.size();

            while(sz--) {
                int u = q.front(); q.pop();
                int cnt = 0;

                for(const auto v : adjs[u])
                    cnt += dp[v] == 0;
                
                if(u == target) {
                    if(t == 0 || (t > 0 && cnt == 0))
                        return dp[u];
                    return 0;
                }

                for(const auto v : adjs[u]) 
                    if(dp[v] == 0)
                        dp[v] = dp[u] / cnt, q.push(v);
                
            }
            t--;
        }

        return 0;

        
    }
};