//
//Runtime 358
//Memory Usage 95.7

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> adjs[n], bk[n];

        bool vis[n];
        memset(vis, 0, sizeof(vis));

        for(const auto &conn : connections)
            adjs[conn[0]].push_back(conn[1]), bk[conn[1]].push_back(conn[0]);

        vis[0] = 1;
        queue<int> q;

        q.push(0);
        int res = 0;

        while(q.size()) {
            int u = q.front(); q.pop();
            
            for(const auto v : adjs[u])
                if(!vis[v])
                    q.push(v), vis[v] = true, ++res;
            
            for(const auto v : bk[u])
                if(!vis[v])
                    q.push(v), vis[v] = true;
            
        }

        return res;
    }
};