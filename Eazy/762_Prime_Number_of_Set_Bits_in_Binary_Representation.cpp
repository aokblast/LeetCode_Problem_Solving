//
//Runtime 8
//Memory Usage 6
class Solution {
public:
    
    int countPrimeSetBits(int left, int right) {
        int res = 0;
        bool isPrime[22] = {0};
        memset(isPrime, 1, sizeof(isPrime));
        isPrime[1] = isPrime[0] = false;
        for(int i = 2; i <= 21; ++i)
            if(isPrime[i])
                for(int j = 2 * i; j <= 21; j += i)
                    isPrime[j] = false;
        
        auto cnt = [](int num){
            int res = 0;
            for(; num; num &= (num - 1), ++res);
            return res;
        };
        
        for(int num = left; num <= right; ++num)
            res += isPrime[cnt(num)];
        return res;

    }
};