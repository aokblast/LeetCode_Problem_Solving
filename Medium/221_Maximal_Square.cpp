//dp
//Runtime 20 
//Memory Usage 11.4
class Solution {
public:
    int dp[305][305] = {{0}};
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans=  0;
        for(int i = 0;i  < n; ++i){
            for(int j = 0; j < m; ++j){
                if(i == 0 || j == 0) dp[i][j] = matrix[i][j] - '0';
                else if(matrix[i][j] == '1') dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                 ans = max(dp[i][j], ans);
            }
        }
        return ans * ans;
    }
    

};
