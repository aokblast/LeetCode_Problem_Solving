//Bit wise
//Runtime 0
//Memory Usage 5.9
class Solution {
public:
    int getSum(int a, int b) {
        long c = 0; int ans = 0;
        for(int bit = 0; bit < 32; ++bit){
            int b1 = a & (1 << bit), b2 = b & (1 << bit);
            ans |= (b1 ^ b2 ^ c);
            c = (b1 & b2) | (b1 & c) | (b2 & c);
            
            if(bit != 31)c <<= 1;
        }
        return ans;
    }
};
