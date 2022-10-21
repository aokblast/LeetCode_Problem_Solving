//dp
//Runtime 43
//Memory Usage 10.4

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        
        int n = req_skills.size(), m = people.size();
        unordered_map<string, int> mp;
        
        for(int i = 0; i < n; ++i)
            mp[req_skills[i]] = i;
        
        vector<int> ps;
        
        for(const auto &person : people) {
            int cur = 0;
            
            for(const auto &skill : person)
                cur |= (1 << mp[skill]);
            
            ps.push_back(cur);
        }

        int lim = 1 << n;
        vector<int> dp(lim, INT_MAX);
        vector<int> parent(lim, -1);
        vector<int> parent_num(lim);
        dp[0] = 0;
        for(int i = 0; i < lim; ++i) {
            if(dp[i] == INT_MAX)
                continue;
            for(int j = 0; j < m; ++j) {
                int next = i | ps[j];
                
                if(dp[next] > dp[i] + 1) {
                    parent[next] = i;
                    parent_num[next] = j;
                    dp[next] = dp[i] + 1;
                }
                
            }
        }
        int cur = lim - 1;
        vector<int> res;
        while(parent[cur] != -1) {
            res.push_back(parent_num[cur]);
            cur = parent[cur];
        }
        return res;
        
    }
};