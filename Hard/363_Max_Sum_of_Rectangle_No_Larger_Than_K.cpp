//prefix Sum
//Runtime 560
//Memory Usage 10.5 
class Solution {
public:
    int prefixSum[105][105] = {{0}};
    int maxSumSubmatrix(vector<vector<int>>& matrix, int d) {
        int ans = INT_MIN;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                prefixSum[i + 1][j + 1] = prefixSum[i][j + 1] + prefixSum[i + 1][j] - prefixSum[i][j] + matrix[i][j];
            }
        }
        
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                int v = prefixSum[i - 1][j - 1];
                for(int k = i; k <= m; ++k){
                    for(int l = j; l <= n; ++l){
                        int val = prefixSum[k][l] - prefixSum[i - 1][l] - prefixSum[k][j - 1] + v;
                        
                        if(val <= d){
                            ans = max(val, ans);
                        }
                    }
                }
            }
        }
        return ans;
        
    }
};
