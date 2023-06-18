//
//Runtime 0
//Memory Usage 5.9

class Solution {
public:
    string thousandSeparator(int n) {
        string res;
        int idx = 0;
        if(n == 0)
            return "0";
        while(n) {
            res += (char)(n % 10 + '0');
            n /= 10;
            if((++idx) % 3 == 0 && n != 0)
                res += '.';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};