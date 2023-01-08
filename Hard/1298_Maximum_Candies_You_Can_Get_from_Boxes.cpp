//BFS
//Runtime 125
//Memory Usage 39.9

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies
    , vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int> q;

        int n = status.size();

        int vis[n];
        memset(vis, 0, sizeof(vis));
        
        for(const int box: initialBoxes) 
            if(status[box])
                q.push(box);
            else 
                vis[box] = true;
                
        int res = 0;

        while(!q.empty()) {
            int u = q.front(); q.pop();

            res += candies[u];

            for(const auto key : keys[u]) {
                if(!status[key] && vis[key])
                    q.push(key);
                
                status[key] = true;
            }

            for(const auto v : containedBoxes[u])
                if(status[v])
                    q.push(v);
                else
                    vis[v] = true;
            
        }

        return res;
    }
};