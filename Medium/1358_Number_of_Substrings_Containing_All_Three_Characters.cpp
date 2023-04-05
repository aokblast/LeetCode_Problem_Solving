//dp
//Runtime 15
//Memory Usage 8.5

class Solution {
public:
    int numberOfSubstrings(string s) {
        int dp[3] = {0};

        int i = 0, j = 0, n = s.size(), res = 0;

        while(i < n) {
            dp[s[i++] - 'a']++;
            
            while(dp[0] && dp[1] && dp[2])
                dp[s[j] - 'a']--, ++j;
            res += j;    
        }

        return res;
    }
};