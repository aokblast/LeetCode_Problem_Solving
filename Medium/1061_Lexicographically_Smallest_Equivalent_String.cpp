//
//Runtime 0
//Memory Usage 6.5

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int mp[26], djs[26];

        for(int i = 0; i < 26; ++i)
            mp[i] = i, djs[i] = i;

        function<int(int)> parent = [&](int u) {
            return u == djs[u] ? u : djs[u] = parent(djs[u]);
        };

        int n = s1.length();
        
        for(int i = 0; i < n; ++i) {
            int p1 = parent(s1[i] - 'a'), p2 = parent(s2[i] - 'a');
            djs[p1] = p2;
        }

        for(int i = 0; i < 26; ++i) {
            int p = parent(i);
            mp[p] = min(mp[p], i);
        }

        for(int i = 0; i < baseStr.length(); ++i) 
            baseStr[i] = mp[parent(baseStr[i] - 'a')] + 'a';

        return baseStr;
        
    }
};