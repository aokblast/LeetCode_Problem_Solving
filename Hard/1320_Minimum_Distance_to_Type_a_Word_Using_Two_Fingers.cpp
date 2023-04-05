//dp
//Runtime: 3
//Memory Usage: 6.2


class Solution {
public:
    int minimumDistance(string word) {
        int n = word.size();
        pair<int, int> loc[26];

        for(int i = 0; i < 26; ++i)
            loc[i] = {i / 6, i % 6};

        int res = 0, save = 0;
        int dp[26] = {0};

        auto d = [&](int a, int b) {
            return abs(loc[a].first - loc[b].first) + abs(loc[a].second - loc[b].second);       
        };
        

        
        for (int i = 0; i < n - 1; ++i) {
            int a = word[i] - 'A', b = word[i + 1] - 'A';

            for(int c = 0; c < 26; ++c) 
               dp[a] = max(dp[a], dp[c] + d(a, b) - d(c, b));

            save = max(save, dp[a]);
            res += d(a, b);
        }
        
        return res - save;

    }
};