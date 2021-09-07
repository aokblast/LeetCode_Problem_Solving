//
//Runtime 0
//Memory Usage 5.9 
class Solution {
public:

    bool canMeasureWater(int x, int y, int z) {
        return !z || (x + y >= z && !(z % gcd(x, y)));
    }
};
