//
//Runtime 0
//Memory 5.9

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int cur = n & 1;
        n >>= 1;
        while(n){
            if(cur == (n & 1))
                return false;
            cur = n & 1;
            n >>= 1;
        }
        return true;
    }
};