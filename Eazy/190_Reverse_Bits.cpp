//
//Runtime 0
//Memory Usage 5.9
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        for(int i = 0; i < 16; ++i){
            uint32_t topBit = n & (1u << (31 - i));
            uint32_t lessBit = n & (1u << i);
            n &= ~(1u << (31 - i));
            n &= ~(1u << i);
            n |= ((topBit >> (31 - i)) << i);
            n |= ((lessBit >> i) << (31 - i));
        }
        return n;
    }
};
