//
//Runtime 8
//Memory Usage 8.1

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for(const char c : moves){
            switch(c){
                case 'R':
                    ++x;
                    break;
                case 'L':
                    --x;
                    break;
                case 'U':
                    --y;
                    break;
                case 'D':
                    ++y;
                    break;
            }
        }
        return x == 0 && y == 0;
    }
};