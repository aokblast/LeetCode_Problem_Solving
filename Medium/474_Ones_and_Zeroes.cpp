//dp
//Runtime 44
//Memory Usage 8.8

class Solution {
public:
    int dp[105][105] = {0};
    
     
    int findMaxForm(vector<string>& strs, int m, int n) {
        int M = 0, N = 0;
        for(string &s : strs){
            M = N = 0;
            for(char &c : s)((c == '0') ? ++M : ++N);
            for(int i = m; i >= M; --i){
                for(int j = n; j >= N; --j){
                    dp[i][j] = max(dp[i][j], dp[i - M][j - N] + 1);
                }    
            }
            
        }
        return dp[m][n];
    }
};
