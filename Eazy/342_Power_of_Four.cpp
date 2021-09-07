//
//Runtime 0
//Memory Usage 5.9
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n < 0) return false;
        int cnt = 0;
        for(int i = 0; i < 32; ++i){
            if(n & (1 << i) ){
                if(i % 2) return false;
                ++cnt;
            }
        }
        return cnt == 1;
    }
};
