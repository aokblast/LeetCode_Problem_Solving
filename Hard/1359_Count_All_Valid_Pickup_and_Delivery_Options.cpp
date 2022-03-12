//
//Runtime 0
//Memory Usage 5.8

class Solution {
public:
    int countOrders(int n) {
        long mod = 1e9 + 7, res = 1;
        for(int i = 2; i <= n; ++i){
            res = (res * i) % mod;
            res = (res * (2 * i - 1)) % mod;
        }
        return res;
    }
};