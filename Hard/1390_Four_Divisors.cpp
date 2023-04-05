//
//Runtime 18
//Memory Usage 12.5

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;

        for(const int num : nums) {
            int cur = 0, lim = sqrt(num);
            if(lim * lim == num)
                continue;
            else
                ++lim;
            for(int i = 2; i < lim; ++i) {
                if((num % i) == 0) {
                    if(cur != 0) {
                        cur = 0;
                        break;
                    }
                    cur = i + (num / i);
                }
            }
            res += cur != 0 ? (cur + 1 + num) : 0;
        }

        return res;
    }
};