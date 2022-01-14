//dp
//Runtime 37
//Memory Usage 11.7
class Solution {
public:
    int numDecodings(string s) {
        long MOD = 1e9 + 7, a0 = 0, a1 = 0, a2 = 0, h0 = 1, h1 = 0, h2 = 0;
        for(const char c : s){
            if(c == '*'){
                a0 = 9 * h0 + 9 * h1 + 6 * h2;
                a1 = h0;
                a2 = h0;
            }else{
                a0 = (c > '0') * h0 + h1 + (c <= '6') * h2;
                a1 = (c == '1')  * h0;
                a2 = (c == '2') * h0;
            }
            h0 = a0 % MOD;
            h1 = a1;
            h2 = a2;
        }
        return h0;
    }
};