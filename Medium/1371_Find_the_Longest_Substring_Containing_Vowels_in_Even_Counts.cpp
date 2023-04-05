//Greedy
//Runtime 41
//Memory Usage 16.3

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int cnts[26] = {0};
        unordered_map<char, int> duiying = {{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};
        int d[1 << 5] = {0};
        memset(d, -1, sizeof(d));
        d[0] = 0;

        auto check = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        int cur = 0, res = 0;
        int n = s.size();
        for(int i = 0; i < n; ++i) {
            char c = s[i];
            if(check(c))
                cur ^= 1 << duiying[c];

            if(d[cur] != -1) {
                res = max(res, i - d[cur] + 1);
            } else {
                d[cur] = i + 1;
            }
            
        }

        return res;
    }
};