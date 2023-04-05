//bfs
//Runtime 325
//Memory Usage 112.9

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adjs[n];

        for(int i = 0; i < n; ++i) 
            if(manager[i] != -1)
                adjs[manager[i]].push_back(i);

        int res = 0;

        function<void(int)> dfs = [&](int u) {
            for(const auto v : adjs[u])
                informTime[v] += informTime[u], dfs(v);

            if(adjs[u].size() == 0)
                res = max(res ,informTime[u]);
        };

        dfs(headID);

        return res;
    }
};