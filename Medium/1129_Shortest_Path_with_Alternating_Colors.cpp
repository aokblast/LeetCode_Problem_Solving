//BFS
//Runtime 16
//Memory Usage 14.4

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int, int>> adjs[n];
        
        for(const auto &vec : redEdges) 
            adjs[vec[0]].push_back({vec[1], 0});
        
        for(const auto &vec : blueEdges) 
            adjs[vec[0]].push_back({vec[1], 1});
        
        vector<int> res(n, -1);
        res[0] = 0;
        
        queue<pair<int, int>> q;
        q.push({0, -1});
        
        bool vis[n][2];
        memset(vis, 0, sizeof(vis));
        int step = 0;
        
        while(!q.empty()) {
            int sz = q.size();
            ++step;
            while(sz--) {
                auto [u, pre_color] = q.front(); q.pop();
                if(pre_color != -1) {
                    if(vis[u][pre_color])
                        continue;
                    vis[u][pre_color] = true;
                }    

                for(const auto [v, color] : adjs[u]) {
                    if(color == pre_color)
                        continue;
                    if(res[v] == -1)
                        res[v] = step;
                    q.push({v, color});
                }
            }
        }
        
        return res;
    }
};