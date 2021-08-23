//
//Runtime 0
//Memory Usgae 5.9
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int x = 1, cnt = 31;
        while(cnt--){
            if(x == n) return true;
            else if(x > n) break;
            x <<= 1;
        }
        return false;
    }
};
