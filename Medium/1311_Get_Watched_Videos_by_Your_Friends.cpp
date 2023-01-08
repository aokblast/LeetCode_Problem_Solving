//BFS
//Runtime 94
//Memory Usage 39.5


class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        bool vis[n];
        memset(vis, 0, sizeof(vis));

        queue<int> q;
        q.push(id);
        vis[id] = true;

        while(level-- && q.size()){
            int sz = q.size();
            while(sz--) {
                int u = q.front(); q.pop();

                for(const auto v : friends[u]) {
                    if(vis[v])
                        continue;
                    vis[v] = true;

                    q.push(v);
                }
            
            }

        }

        if(level != -1)
            return {};

        unordered_map<string, int> mp;

        while(!q.empty()) {
            int u = q.front(); q.pop();
            
            for(const auto &vid : watchedVideos[u])
                mp[vid]++;
        }
        
        vector<pair<int, string>> v;

        for(const auto &[n, cnt] : mp)
            v.push_back({cnt, n});


        sort(v.begin(), v.end());
    
        vector<string> res;

        for(const auto &[_, str] : v)
            res.push_back(str);

        return res;
    }
};