//dfs
//Runtime 394
//Memory Usage 183.2

class Solution {
public:

    int longestPath(vector<int>& parent, string s) {
        int n = s.size();
        vector<int> adjs[n];

        for(int i = 1; i < n; ++i) 
            adjs[parent[i]].push_back(i);
        int res = 1;

        function<int(int)> dfs = [&](int u) {
            int m1 = 0, m2 = 0;

            for(const auto v : adjs[u]) {
                int cur = dfs(v);
            
                if(s[u] == s[v])
                    continue;                       
                res = max(res, cur + 1);
                if(cur >= m1)
                    m2 = m1, m1 = cur;
                else if(cur > m2)
                    m2 = cur;
 
            }

            res = max(res, m1 + m2 + 1);

            return m1 + 1;
        };

        dfs(0);

        return res;    
    }
};