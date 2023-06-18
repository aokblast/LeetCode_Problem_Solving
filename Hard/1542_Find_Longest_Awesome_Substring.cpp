//dp
//Runtime 38
//Memory 10.1
class Solution {
public:
    int longestAwesome(string s) {
        int res = 0, cur = 0, n = s.size();
        vector<int> mp(1024, s.size());

        mp[0] = -1;

        for(int i = 0; i < n; ++i) {
            char c = s[i];
            cur ^= (1 << (c - '0'));

            res = max(res, i - mp[cur]);
            for(int j = 0; j <= 9; ++j)
                res = max(res, i - mp[cur ^ (1 << j)]);

            mp[cur] = min(mp[cur], i);  
        }

        return res;
    }
};