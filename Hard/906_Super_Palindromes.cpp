//
//Runtime 57
//Memory 6.4
class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        auto rev = [](long val){
            long res = 0;
            while(val){
                res = res * 10 + val % 10;
                val /= 10;
            }
            return res;
        };
        auto cnt = [](long val){
            int res = 0;
            while(val)
                ++res, val /= 10;
            return res;
        };
        
        long l = sqrt(stol(left)), r = sqrt(stol(right));
        int res = 0;
        res += l <= 1 && 1 <= r;
        res += l <= 2 && 2 <= r;
        res += l <= 3 && 3 <= r;
            
        for(long i = 1; i < 10000; ++i){
            int c = cnt(i);
            for(int j = 0; j < 10; ++j){
                long val = (i * 10 + j) * pow(10, c) + rev(i);
                if(val < l)
                    continue;
                if(val > r)
                    break;
                val *= val;
                res += val == rev(val);
            }
        }
        for(long i = 1; i < 100000; ++i){
            int c = cnt(i);
            long val = i * pow(10, c) + rev(i);
            if(val < l)
                continue;
            if(val > r)
                break;
            val *= val;
            res += val == rev(val);
        }
        return res;
        
        
        
        
    }
};