//
//Runtime 527
//Memory 115
class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int, int> c, r, d, nd;
        unordered_set<long> s;
        
        const long u = n;
        
        for(const auto &lamp : lamps){
            int x = lamp[0], y = lamp[1];
            if(!s.count(u * x + y))
                ++c[x], ++r[y], ++d[x - y], ++nd[x + y], s.insert(u * x + y);
        }
        
        vector<int> res;
        
        for(const auto &q : queries){
            int x = q[0], y = q[1];
            if(c[x] || r[y] || d[x - y] || nd[x + y]){
                res.push_back(1);
                for(int i = -1; i <= 1; ++i){
                    for(int j =  -1; j <= 1; ++j){
                        int xx = x + i, yy = y + j;
                        if(xx < 0 || yy < 0 || xx >= n || yy >= n || !s.count(u * xx + yy))
                            continue;
                        --c[xx], --r[yy], --d[xx - yy], --nd[xx + yy], s.erase(u * xx + yy);
                    }
                }
            }else{
                res.push_back(0);
            }
        }
        return res;
        
        
        
        
        
        
    }
};