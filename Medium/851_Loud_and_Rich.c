//dfs
//Runtime 96
//Memory Usage 42.4

class Solution {
public:
    vector<int> adjs[505];
    vector<int> visit;
    int dfs(int u, vector<int> &q){
        if(visit[u] != -1)
            return visit[u];
        int res = u;
        for(const int adj : adjs[u]){
            int cur = dfs(adj, q);
            if(q[cur] < q[res])
                res = cur;
        }
            
        return visit[u] = res;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        
        for(const auto &rich : richer)
            adjs[rich[1]].push_back(rich[0]);
        visit = vector<int>(quiet.size(), -1);
        for(int i = 0; i < quiet.size(); ++i)
            if(visit[i] == -1)
                dfs(i, quiet);
        
        return visit;
        
    }
};