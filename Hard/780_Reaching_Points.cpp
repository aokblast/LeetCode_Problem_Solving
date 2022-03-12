//
//Runtime 0
//Memory Usage  5.9
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if(tx < sx || ty < sy)
            return false;
        if(sx == tx && (ty - sy) % tx == 0)
            return true;
        if(sy == ty && (tx - sx) % ty == 0)
            return true;
        return reachingPoints(sx, sy, tx % ty, ty % tx);
    }
};