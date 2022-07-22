//Prefix Sum
//Runtime 761
//Memory Usage 9.1
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        
        int preSum[n + 1][m + 1];
        memset(preSum, 0, sizeof(preSum));
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                preSum[i + 1][j + 1] = preSum[i][j + 1] + preSum[i + 1][j] - preSum[i][j] + matrix[i][j];
            
        int res = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                for(int k = i; k < n; ++k){
                    for(int l = j; l < m; ++l){
                        res += ((preSum[k + 1][l + 1] - preSum[k + 1][j] - preSum[i][l + 1] + preSum[i][j]) == target);    
                    }
                }
            }
        }
        return res;
        
    }
};