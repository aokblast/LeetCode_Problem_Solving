//
//Runtime 0
//Memory Usage 9.2

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        int rs[m], cs[n];
        
        memset(rs, 0, sizeof(rs));
        memset(cs, 0, sizeof(cs));
        
        for(const auto &indice : indices)
            rs[indice[0]]++, cs[indice[1]]++;
        
        int res = 0;
        
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                res += ((rs[i] + cs[j]) % 2) == 1;
        
        return res;
    }
};