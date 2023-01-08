//
//Runtime 0
//Memory Usage 6

class Solution {
public:
    int numPrimeArrangements(int n) {
        int np = 1, p = 0;
        for(int i = 2; i <= n; ++i) {
            bool isPrime = true;
            for(int j = 2; j <= sqrt(i); ++j)
                if(i % j == 0) {
                    isPrime = false;
                    break;
                }
            if(isPrime)
                ++p;
            else
                ++np;
        }
        long res = 1;
        const long MOD = 1e9 + 7;
        
        for(int i = 2; i <= np; ++i)
            res = (res * i) % MOD;
        for(int i = 2; i <= p; ++i)
            res = (res * i) % MOD;  
        
        return res;
    }
};