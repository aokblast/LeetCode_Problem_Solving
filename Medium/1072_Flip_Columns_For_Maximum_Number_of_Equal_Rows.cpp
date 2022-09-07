//Greedy
//Runtime 282
//Memory Usage 64.2

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> mp;
        int n = matrix.size(), m = matrix[0].size(), res = 0;
        
        string cur(m, 'T');
        
        
        
        for(int i = 0; i < n; ++i) {
            
            int f = matrix[i][0];
            
            for(int j = 1; j < m; ++j)
                cur[j] = f == matrix[i][j] ? 'T' : 'F';
            
            res = max(res, ++mp[cur]);
        }
        
        return res;
        
    }
};