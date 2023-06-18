//
//Runtime 443
//Memory Usage 123.2

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size(), res = 0, cd[n], acc[n][26], tot = 0;
        queue<int> q;
        vector<int> es[n];

        memset(cd, 0, sizeof(cd));
        memset(acc, 0, sizeof(acc));
        
        for(const auto &e : edges)
            es[e[0]].push_back(e[1]), ++cd[e[1]];

        for(int i = 0; i < n; ++i)
            if(cd[i] == 0)
                q.push(i), ++tot;
                
        while(q.size()) {
            int u = q.front(); q.pop();
            res = max(res, ++acc[u][colors[u] - 'a']);
            for(const auto v : es[u]) {
                for(int i = 0; i < 26; ++i)
                    acc[v][i] = max(acc[v][i], acc[u][i]);

                if(--cd[v] == 0) { 
                    q.push(v);
                    ++tot;
                }
            }
        }

        return tot == n ? res : -1;
    }
};