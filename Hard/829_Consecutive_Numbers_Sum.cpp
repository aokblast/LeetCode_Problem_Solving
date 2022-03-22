//
//Runtime 3
//Memory Usage 5.8
class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int res = 0, sq = sqrt(2 * n);
        
        for(int i = 2; i <= sq; ++i)
            res += (n - (i)*(i - 1) / 2) % i == 0;
            
        return res + 1;
    }
};

