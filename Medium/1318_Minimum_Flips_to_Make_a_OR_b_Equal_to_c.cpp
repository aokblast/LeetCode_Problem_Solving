//
//Runtime 0
//Memory Usage 5.8

class Solution {
public:
    int minFlips(int _a, int _b, int _c) {
        bitset<32> a(_a), b(_b), c(_c);
        int res = 0;

        for(int i = 0 ;i < 32; ++i)
            res += ((a[i] | b[i]) == c[i]) ? 0 : (c[i] == 0) ? ((int)a[i] + b[i]) : 1; 

        return res;
    }
};