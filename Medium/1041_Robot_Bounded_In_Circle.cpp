//
//Runtime 0
//Memory Usage 6.1

class Solution {
public:

    int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
    bool isRobotBounded(string instructions) {
        int d = 0, x = 0, y = 0;
        for(const char ins : instructions){
            switch(ins){
                case 'G':
                    d %= 4;
                    x += dir[d][0], y += dir[d][1];
                    break;
                case 'L':
                    d += 3;
                    break;
                case 'R':
                    d += 1;
                    break;
            }
        }
        return !(d % 4 == 0 &&( x != 0 || y != 0));
    
    
    
    }
};