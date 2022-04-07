//
//Runtime 0
//Memory Usage 5.8

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int lcm = std::lcm(p, q);
        int bt = lcm / q;
        if(bt % 2 == 0)
            return 2;
        return (lcm / p) % 2;
    }
};