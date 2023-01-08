//
//Runtime 7
//Memory Usage 10.9

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        bool has[8][8] = {{false}};
        
        for(const auto &q : queens)
            has[q[0]][q[1]] = true;
        
        vector<vector<int>> res;
        
        for(int i = -1; i <= 1; ++i) {
            for(int j = -1;  j <= 1; ++j) {
                if(i == 0 && j == 0)
                    continue;
                
                int x = king[0] + i, y = king[1] + j;
                
                while(x >= 0 && y >= 0 && x < 8 && y < 8) {
                    if(has[x][y]) {
                        res.push_back({x, y});
                        break;
                    }
                    x += i, y += j;
                }
            }
        }
        
        return res;
    }
};