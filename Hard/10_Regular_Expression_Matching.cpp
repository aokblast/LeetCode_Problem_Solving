//dp
//Runtime 0
//Memory Usage 6.2

class Solution {
public:
    bool isMatch(string s, string p) {
       int sl = s.length(), pl = p.length(), i = 0, j = 0;
	   bool dp[sl + 1][pl + 1];
	   memset(dp , 0, (sl + 1) * (pl + 1));
       dp[0][0] = true;
		for(i = 2; i <= pl && p[i - 1] == '*'; i += 2) dp[0][i] = true;
		for(i = 1; i <= sl; ++i){
			for(j = 1; j <= pl; ++j){
				if(p[j - 1] == '.' || s[i - 1] == p[j - 1] ) dp[i][j] = dp[i - 1][j - 1];
				else if(p[j - 1] == '*') dp[i][j] = dp[i][j - 2] || ((s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
			}
		}
		return dp[sl][pl];	
	}
};
