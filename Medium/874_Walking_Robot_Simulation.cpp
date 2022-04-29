//
//Runtime 80
//Memory Usage 32.6

class Solution {
public:
    int dirs[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    int MOD = 3e4;
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<int> s;
        for(const auto &m : obstacles)
            s.insert((m[0] + MOD) * MOD + m[1] + MOD);
        int d = 0, x = 0, y = 0, res = 0;
        for(int ob : commands){
            if(ob == -2)
                d = (d + 4 - 1) % 4;
            else if(ob == -1)
                d = (d + 1) % 4;
            else{
                int dx = dirs[d][0], dy = dirs[d][1];
                while(ob--){
                    x += dx, y += dy;
                    if(s.find((x + MOD) * MOD + y + MOD) != s.end()){
                        x -= dx;
                        y -= dy;
                    }
                }
            } 
            res = max(res, x * x + y * y);
        }
        return res;
    }
};