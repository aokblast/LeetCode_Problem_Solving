//
//Runtime 0
//Memory Usage 6.1

class Solution {
public:
    string baseNeg2(int n) {
        if(n == 0)
            return "0";
        
        string res;
        
        while(n){
            res += (char)((n & 1) + '0');
            n = -(n >> 1);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};