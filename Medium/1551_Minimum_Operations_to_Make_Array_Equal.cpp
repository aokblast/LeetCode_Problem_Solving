//
//Runtime 0
//Memory Usage 6

class Solution {
public:
    int minOperations(int n) {
        int res = 0, mx = n, lim = n / 2;

        for(int cur = 0; cur < lim; ++cur) {
            res += mx - (2 * cur + 1);
        }

        return res;
    }
};