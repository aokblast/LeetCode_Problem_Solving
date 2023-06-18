//Math
//Runtime 0
//Memory Usage 5.9

class Solution {
public:
    char findKthBit(int n, int k) {
        int len = (1 << n) - 1, f = 0;

        while(k > 1) {
            if(k == len / 2 + 1)
                return '0' + (f ^ 1);
            if(k > len / 2)
                k = len + 1 - k, f ^= 1;
            len /= 2;
        }

        return '0' + f;
    }
};