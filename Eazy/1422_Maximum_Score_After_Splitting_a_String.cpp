//
//Runtime 0
//Memory Usage 6.4

class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
    
        int res = 0;
        int cnt[n];
        memset(cnt, 0, sizeof(cnt));

        cnt[n - 1] = s[n - 1] == '1';

        for(int i = n - 2; i >= 0; --i)
            cnt[i] = cnt[i + 1] + (s[i] == '1');

        int zs = 0, os = 1;

        for(int i = 0; i < (n - 1); ++i) {
            zs += s[i] == '0';
            os += s[i] == '1';
            res = max(res, zs + cnt[i + 1]);
        }
        return res;
    }
};