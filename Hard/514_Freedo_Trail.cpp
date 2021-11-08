//dp
//Runtime 80
//Memory Usage 13.2

class Solution {
public:
    int dp[105][105] = {{0}};
    int findRotateSteps(string ring, string key) {
        int n = ring.size(), m = key.size();
        vector<vector<int>> dp(m  + 1, vector<int>(n + 1, 0));
        vector<int> hasKey;
        for(int i = m - 1; i >= 0; --i){
            hasKey.clear();
            for(int j = 0; j < n; ++j)if(key[i] == ring[j])hasKey.push_back(j);
            for(int from = 0; from < n; ++from){
                dp[i][from]  = INT_MAX;
                for(const int &to : hasKey){
                    int diff = abs(from - to);
                    int step = min(n - diff, diff);
                    dp[i][from] = min(dp[i][from], step + dp[i + 1][to]);
                }
            }
        }
        return dp[0][0] + m;
    
    }
};

//dfs + memo
//Runtime 12
//Memory Usage 6.4

class Solution {
public:
    int dp[105][105] = {{0}};
    int n, m;
    
    int dfs(const string &ring, int i, const string &key, int j){
        if(j >= m)return 0;
        if(dp[j][i])return dp[j][i];
        int step = INT_MAX;
        for(int k = 0; k < n; ++k){
            if(key[j] != ring[k])continue;
            int diff = abs(i - k);
            int curStep = min(n - diff, diff);
            step = min(step, curStep + 1 + dfs(ring, k, key, j + 1));
            
        }
        return dp[j][i] = step;
        
        
        
    }
    int findRotateSteps(string ring, string key) {
        n = ring.size(), m = key.size();
        return dfs(ring, 0, key, 0);
    
    }
};