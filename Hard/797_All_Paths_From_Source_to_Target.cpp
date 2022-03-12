//dfs
//Runtime: 12
//Memory Usage: 10.7

class Solution {
public:
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> cur;
        int n = graph.size();
        function<void(int)> dfs = [&](int u){
            if(n - 1 == u){
                cur.push_back(n - 1);
                res.push_back(cur);
                cur.pop_back();
                return;
            }
            cur.push_back(u);
            for(const auto adj : graph[u])
                dfs(adj);
            
            cur.pop_back();
        };
        dfs(0);
        return res;
        
    }
};

