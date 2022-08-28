//
//Runtime 11
//Memory Usage 9.3
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> mp[2 * (n + m) + 5];
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                mp[i - j + n + m].push_back(mat[i][j]);
        
        for(auto &v : mp)
            sort(v.begin(), v.end(), greater());
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                mat[i][j] = mp[i - j + n + m].back(), mp[i - j + n + m].pop_back();
        
        return mat;
        
        
    }
};