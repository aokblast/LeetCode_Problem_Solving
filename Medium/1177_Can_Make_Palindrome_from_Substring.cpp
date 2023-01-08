//
//Runtime 334
//Memory Usage 95

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int mask = 0;
        vector<int> ps(1);
        
        for(const char c : s) 
            ps.push_back(mask ^= (1 << (c - 'a')));
        
        vector<bool> res;
        
        for (const auto &q : queries) 
            res.push_back(q[2] >= __builtin_popcount(ps[q[0]] ^ ps[q[1] + 1]) / 2);
        
        
        return res;
        
    }
};