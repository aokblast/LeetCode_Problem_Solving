//
//Runtime 0
//Memory Usage 6

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double cur = abs((hour % 12) * 30 + 0.5 * minutes - 6 * minutes);
        return min(cur, 360 - cur);
    }
};