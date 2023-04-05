//dp
//Runtme 96
//Memory Usage 19.5

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> items;

        for(int i = 0; i < n; ++i)
            items.push_back({ages[i], scores[i]});
        
        sort(items.begin(), items.end());

        int dp[n];

        memset(dp, 0, sizeof(dp));
        int res = 0;

        for(int i = 0; i < n; ++i) {
            auto [age, sc] = items[i];
            int cur = sc;

            for(int j = 0; j < i; ++j) {
                if(items[j].second <= sc)
                    cur = max(cur, dp[j] + sc);
            }
            res = max(res, dp[i] = cur);

        }

        return res;
    }
};