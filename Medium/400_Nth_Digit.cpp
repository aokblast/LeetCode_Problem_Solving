//
//Runtime 0
//Memory Usage 5.9
class Solution {
public:
    int findNthDigit(int n) {
        long long len = 1, cnt = 9, ind = 1;
        while(n > len * cnt){
            n -= len *cnt;
            cnt *= 10;
            ind *= 10;
            ++len;
        }
        ind += ((n - 1) / len);
        string s = to_string(ind);
        
        return s[(n - 1) % len] - '0';
        
    }
};
