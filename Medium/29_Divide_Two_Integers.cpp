//
//Runtime 0
//Memory Usage 6

class Solution {
public:
    int divide(long long dividend, long long divisor) {
        long long q = 0, div = 1;
        bool negflag = false;
        if(dividend < 0) negflag = !negflag, dividend *= -1;
        if(divisor < 0) negflag = !negflag, divisor *= -1;
        
        while (dividend >= divisor){
            while(dividend >= divisor * div) div <<= 1;
            div >>= 1;
            q += div;
            dividend -= divisor * div;
            div = 1;
        }
        return negflag ? -q : q > INT_MAX ? INT_MAX : q;
        
    }
};