//
//Runtime 15
//Memory Usage 10.7

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int ro, int c, int rs, int cs) {
        vector<vector<int>> res;
        int lim = ro * c;
        res.reserve(lim);
        int r = 1;
        res.push_back({rs, cs});
        int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
        int d = 0;
        int inc = 0;
        while(res.size() != lim){
            for(int i = 1; i <= r; ++i){
                rs += dir[d][0], cs += dir[d][1];
                
                if(rs < ro && cs < c && rs >= 0 && cs >= 0)
                    res.push_back({rs, cs});
                if(res.size() == lim)
                    goto end;
            }
            d = (d + 1) % 4;
            r += (inc++ % 2) == 1;
            
        }
        end:
        return res;
        
        
        
    
    }
};