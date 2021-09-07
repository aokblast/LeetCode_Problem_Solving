//LIS
//Runtime 40
//Memory Usage 16.4 
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        int n = envelopes.size();
        vector<int> dp(n, INT_MAX);
        int ans = 0;
        sort(envelopes.begin(), envelopes.end(), [](const vector<int> &v1, const vector<int> &v2){return v1[0] == v2[0] ? v1[1] > v2[1] : v1[0] < v2[0];});
        for(int i = 0; i < n; ++i){
            int pos = lower_bound(dp.begin(), dp.end(), envelopes[i][1]) - dp.begin();
            dp[pos] = envelopes[i][1];
            ans = max(ans, pos);
            
        }
        return ans + 1;
    }
};

//LIS + pair
//Runtime 32
//Memory Usage 17.2
class Solution {
public:
    

    
    int maxEnvelopes(vector<vector<int>>& env) {
        vector<pair<int, int>> envelopes;
        int n = env.size();
        for(int i = 0; i < n; ++i){
            envelopes.push_back( make_pair(env[i][0], env[i][1]));
        }
        vector<int> dp(n, INT_MAX);
        int ans = 0;
        sort(envelopes.begin(), envelopes.end(), [](const pair<int, int> &v1, const pair<int, int> &v2){return v1.first == v2.first ? v1.second > v2.second : v1.first < v2.first;});
        for(int i = 0; i < n; ++i){
            int pos = lower_bound(dp.begin(), dp.end(), envelopes[i].second) - dp.begin();
            dp[pos] = envelopes[i].second;
            ans = max(ans, pos);
            
        }
        return ans + 1;
    }
};
