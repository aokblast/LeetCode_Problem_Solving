//dfs
//Runtime 200
//Memory Usage 63.4

class Solution {
    vector<int> adjs[2001];
    int color[2001] = {0};
    
    bool dfs(int u, int c = 1){
        if(!color[u]){
            color[u] = c;
            for(const int adj : adjs[u])
                if(!dfs(adj, ~c))
                    return false;
            return true;
        }else{
            return c == color[u];
        }
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        for(const auto &dislike : dislikes)
            adjs[dislike[0]].push_back(dislike[1]), adjs[dislike[1]].push_back(dislike[0]);
        for(int i = 1; i <= n; ++i)
            if(!color[i] && !dfs(i))
                return false;
        return true;
        
    }
};