//Greedy
//Runtime 137
//Memory Usage 39.8

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> ans(n, -1);
        
        vector<vector<int>> adjs(n);
        
        for(const auto &path : paths)
            adjs[path[0] - 1].push_back(path[1] - 1), adjs[path[1] - 1].push_back(path[0] - 1);
        
        for(int u = 0; u < n; ++u){
            bool vis[4] = {false};
            for(const int v : adjs[u]){
                if(ans[v] == -1)
                    continue;
                vis[ans[v] - 1] = true;
            }
            
            for(int i = 0; i < 4; ++i)
                if(!vis[i]){
                    ans[u] = i + 1;
                    break;
                }
            
        }
        return ans;
    }
};