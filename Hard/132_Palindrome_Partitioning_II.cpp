//dp
//Runtime 12 
//Memory Usage 10.6
class Solution {
public:
    int dp[2005];
    bool isP[2005][2005];
    int minCut(string s) {
        int size = s.size();
        for(int i = 0; i < size; ++i){
            isP[i][i] = true;
            dp[i] = i;
            for(int j = 0; j <= i; ++j){
                if(s[i] == s[j] && ((i - j) < 2 || isP[i -  1][j + 1])){
                    isP[i][j] = true;
                    dp[i] = j == 0 ? 0 : min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        return dp[size - 1];
    }
};
