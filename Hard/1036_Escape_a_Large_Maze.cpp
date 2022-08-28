//
//Runtime 57
//Memory Usage 24.7
class Solution {
public:
    
    constexpr static int dirs[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        unordered_set<long> b;
        unordered_set<long> vis;
        const long lim = 1e6;
        
        for(const auto &block : blocked)
            b.insert(block[0] * lim + block[1]);
        
        int sx = source[0], sy = source[1], tx = target[0], ty = target[1];
        
        function<bool(int, int)> dfs = [&](int x, int y){
            if((abs(x - sx) + abs(y - sy) >= 200) || (x == tx && y == ty))
                return true;
            
            vis.insert(x * lim + y);
            for(int i = 0; i < 4; ++i){
                int xx = x + dirs[i][0], yy = y + dirs[i][1];
                
                if(xx >= 0 && xx < lim && yy >= 0 && yy < lim && !b.count(xx * lim + yy) && !vis.count(xx * lim + yy)){
                    if(dfs(xx, yy))
                        return true;
                }
                    
            }
            
            return false;
        };
        if(dfs(sx, sy)){
            sx = target[0], sy = target[1], tx = source[0], ty = source[1];
            vis.clear();
            if(dfs(sx, sy))
                return true;
            return false;
        }else{
            return false;
        }
        
        
        
    }
};