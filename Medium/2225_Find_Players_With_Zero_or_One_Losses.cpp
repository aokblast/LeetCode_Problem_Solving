//
//Runtime 461
//Memory Usage 131.2

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> res(2);
        
        const int MAXN = 1e5 + 5;
        bool app[MAXN] = {false};
        int rd[MAXN] = {0};
        
        for(const auto &match : matches) 
            app[match[0]] = app[match[1]] = true, rd[match[1]]++;
        
        
        for(int i = 0; i <= 1e5; ++i)
            if(app[i] && rd[i] <= 1)
                res[rd[i]].push_back(i);
        
        return res;
            
    }
};