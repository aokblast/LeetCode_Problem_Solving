//
//Runtime 4
//Memory Usage 7.3

class Solution {
public:
    vector<int> numOfBurgers(int t, int c) {
        int x = t - 2 *c;
        if(x < 0 || x % 2)
            return {};

        int y = 4 * c - t;

        if(y < 0 || y % 2)
            return {};

        return {x / 2, y / 2};
    }
};