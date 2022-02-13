//dp
//Runtime 236
//Memory Usage 11.1
class Solution {
public:
    bool dp[2005][2005];
    bool isMatch(string s, string p) {
        dp[0][0] = true;
        int sl = s.size(), pl = p.size();
        for (int i = 1; i <= pl && p[i - 1] == '*'; ++i) dp[0][i] = true;
        for (int i = 1; i <= sl; ++i) {
            for (int j = 1; j <= pl; ++j) {
                if (p[j - 1] == '*') dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                else if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) dp[i][j] = dp[i - 1][j - 1];
            }
        }
        return dp[sl][pl];
    }
};

//
//Runtime 4
//Memory Usage 6.6

class Solution {
public:
    bool isMatch(string s, string p) {
        int si = 0, pi = 0, sl = s.size(), pl = p.size();
        int sStart = -1, pStart = -1;
        while (si < sl) {
            if (pi < pl && (s[si] == p[pi] || p[pi] == '?')) ++pi, ++si;
            else if (pi < pl && p[pi] == '*') {
                sStart = si;
                pStart = pi++;
            }
            else if (sStart >= 0) {
                si = ++sStart;
                pi = pStart + 1;
            }
            else return false;
        }
        while (pi < pl && p[pi] == '*') ++pi;
        return pi == pl;
    }
};