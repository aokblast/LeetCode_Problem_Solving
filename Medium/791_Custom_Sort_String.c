// 
//Runtime 0
//Memory Usage 6

class Solution {
public:
    string customSortString(string order, string s) {
        int mp[26] = {0};
        memset(mp, 0x3f, sizeof(mp));
        int n = order.size();
        for(int i = 0; i < n; ++i)
            mp[order[i] - 'a'] = i + 1;
        sort(s.begin(), s.end(), [&](const char c1, const char c2){return mp[c1 - 'a'] < mp[c2 - 'a'];});
        return s;
    }
};