//dp
//Runtime 47
//Memory 8.8
class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        
        int dp[1 << n][n];
        int p[1 << n][n];
        int overlap[n][n];
        memset(overlap, 0, sizeof(overlap));
        memset(dp, 0x3f, sizeof(dp));
        memset(p, -1, sizeof(p));
        
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(i == j)
                    continue;
                for(int k = min(words[i].size(), words[j].size()); k >= 0; --k){
                    if(words[j].compare(0, k, words[i].substr(words[i].size() - k)) == 0){
                        overlap[i][j] = k;
                        break;
                    }
                }
            }
            
            dp[1 << i][i] = words[i].length();
        }
        int lim = 1 << n;
        for(int mask = 1; mask < lim; ++mask){
            for(int i = 0; i < n; ++i){
                if((mask & (1 << i)) == 0)
                    continue;
                for(int j = 0; j < n; ++j){
                    if(((mask & (1 << j)) == 0) || i == j)
                        continue;
                    int len = dp[mask ^ (1 << j)][i] + words[j].length() - overlap[i][j];
                    if(dp[mask][j] > len)
                        dp[mask][j] = len, p[mask][j] = i;  
                    
                }
            }
        }
        int cur = lim - 1;
        int idx = 0;
        for(int i = 1; i < n; ++i){
            if(dp[cur][i] < dp[cur][idx])
                idx = i;
        }
        string res;
        function<void(int, int)> dfs = [&](int cur, int idx){
            if(p[cur][idx] == -1)
                return void(res += words[idx]);
            dfs(cur ^ (1 << idx), p[cur][idx]);
            res += words[idx].substr(overlap[p[cur][idx]][idx]);
        };
        dfs(cur, idx);
        return res;
            
    }
};